# SDot
**Francis Kyle Clemente**

**Fiona Amaia Tano**

**LBYARCH S13**

*This x86-to-C interface programming project serves to perform a dot product between vector A and vector B and place the result in sdot, the dot product of vectors A and B.*

<ins>**Input:**</ins> Scalar variable n (integer) contains the length of the vector;  Vectors A and B are both double-precision float. Scalar sdot is a double-precision float.

<ins>**Output:**</ins> Store the result in memory location sdot.  Display the result for all versions of the kernel.

## Execution Times (Debug Mode)

In **debug** mode, the input was run 20 times to obtain the average execution time. The average execution time of the <ins>C kernel</ins> given the following input sizes are as follows.

<ins>**2<sup>20</sup>**</ins> = 0.00405s

<ins>**2<sup>24</sup>**</ins> = 0.0499s

<ins>**2<sup>28</sup>**</ins> = 1.19175s

Meanwhile, below are the average execution times of the <ins>x86-64 assembly kernel</ins>:

<ins>**2<sup>20</sup>**</ins> = 0.00215s

<ins>**2<sup>24</sup>**</ins> = 0.028s

<ins>**2<sup>28</sup>**</ins> = 0.5725s

## Execution Times (Release Mode)

In **release** mode, the program was also run 20 times. The average execution time of the <ins>C kernel</ins> given the following input sizes are as follows:

<ins>**2<sup>20</sup>**</ins> = 0.00305s

<ins>**2<sup>24</sup>**</ins> = 0.0301s

<ins>**2<sup>28</sup>**</ins> = 1.7376s

Meanwhile, below are the average execution times of the <ins>x86-64 assembly kernel</ins>:

<ins>**2<sup>20</sup>**</ins> = 0.0027s

<ins>**2<sup>24</sup>**</ins> = 0.0277s

<ins>**2<sup>28</sup>**</ins> = 0.79555

## Analysis of Kernel Performances

Naturally, execution times increase with larger input sizes due to increased iterations.

Generally, the x86-64 assembly kernel is more efficient compared to its C counterpart for multiple reasons. For instance, assembly eliminates the compiler overhead that C may have. SIMD instructions and registers are also very efficient in performing numeric computations particular to floating-point data, as was used in this project. Additionally and importantly, assembly allows direct access to registers, and registers are the fastest type of memory. Memory is also more precisely controlled in assembly.

C performs faster in release mode, as this mode enables compiler optimizations that C benefits from. Debug information is removed, reducing overhead. Meanwhile, assembly performs slightly slower in release mode compared to its execution in debug mode, likely due to the way that release mode optimizes C programs, and such optimizations may not directly affect assembly.

## Program Screenshots

Attached below are screenshots of the program given the different input sizes. Each screenshot already contains the <ins>**sdot values and execution times in both C and x86-64**</ins> for debug and release mode, respectively. *"Correctness check passed."* is outputted for all screenshots as all C and x86-64 outputs are pairwisely equal to one another.

**2<sup>20</sup>**

![2^20 debug](https://github.com/pannkakkes/LBYARCHMP/blob/master/PHOTO1.png)

![2^20 release](https://github.com/pannkakkes/LBYARCHMP/blob/master/PHOTO4.png)

**2<sup>24</sup>**

![2^24 debug](https://github.com/pannkakkes/LBYARCHMP/blob/master/PHOTO2.png)

![2^24 release](https://github.com/pannkakkes/LBYARCHMP/blob/master/PHOTO5.png)

**2<sup>28</sup>**

![2^28 debug](https://github.com/pannkakkes/LBYARCHMP/blob/master/PHOTO3.png)

![2^28 release](https://github.com/pannkakkes/LBYARCHMP/blob/master/PHOTO6.png)

## Demo Video

https://github.com/user-attachments/assets/e0bdad13-57ae-42ea-b206-f5f3010a05d1


