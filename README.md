# SDot
**Francis Kyle Clemente**

**Fiona Amaia Tano**

**LBYARCH S13**

*This x86-to-C interface programming project serves to perform a dot product between vector A and vector B and place the result in sdot, the dot product of vectors A and B.*

<ins>**Input:**</ins> Scalar variable n (integer) contains the length of the vector;  Vectors A and B are both double-precision float. Scalar sdot is a double-precision float.

<ins>**Output:**</ins> Store the result in memory location sdot.  Display the result for all versions of the kernel.

## Comparative Execution Time

The average execution time of the <ins>C kernel</ins> given the following input sizes are as follows:

<ins>**2<sup>20</sup>**</ins> = 0.00405s

<ins>**2<sup>24</sup>**</ins> = 0.0499s

<ins>**2<sup>28</sup>**</ins> = 1.19175s

Meanwhile, below are the average execution times of the <ins>x86-64 assembly kernel</ins>:

<ins>**2<sup>20</sup>**</ins> = 0.00215s

<ins>**2<sup>24</sup>**</ins> = 0.028s

<ins>**2<sup>28</sup>**</ins> = 0.5725s

Generally, the x86-64 assembly kernel is more efficient compared to its C counterpart for multiple reasons. For instance, assembly eliminates the compiler overhead that C may have. SIMD instructions and registers are also very efficient in performing numeric computations particular to floating-point data, as was used in this project. Additionally and importantly, assembly allows direct access to registers, and registers are the fastest type of memory. Memory is also more precisely controlled in assembly.

## Program Screenshots

Attached below are screenshots of the program given the different input sizes. Each screenshot already contains the <ins>**sdot values and execution times in both C and x86-64**</ins>. *"Correctness check passed."* is outputted for all screenshots as all C and x86-64 outputs are pairwisely equal to one another.

**2<sup>20</sup>**

![2^20](https://github.com/pannkakkes/LBYARCHMP/blob/master/PHOTO1.png)

**2<sup>24</sup>**

![2^24](https://github.com/pannkakkes/LBYARCHMP/blob/master/PHOTO2.png)

**2<sup>28</sup>**

![2^28](https://github.com/pannkakkes/LBYARCHMP/blob/master/PHOTO3.png)
