# PS5: DNA Alignment

## Contact
Name: Juan Fernando Ruiz
Section: 204
Time to Complete: 10 hours

Partner: Louis Carrico-Braun

## Description
Implements the Needleman-Wunsch algorithm to find the optimal alignment of two DNA sequences, represented by strings x and y. The program calculates the alignment score using a dynamic programming approach, storing the results in a 2D vector opt which holds the minimal penalty scores at each step. Key functions include optDistance, which computes the optimal distance between segments of the sequences; alignment, which reconstructs the alignment from the scoring matrix; penalty, which assigns a cost to mismatches, gaps, and matches ; and min3, a helper function used to find the minimum of three values, facilitating the determination of the minimal score by comparing different possible alignments.

### Features
The program calculates the alignment score using a dynamic programming approach, storing the results in a 2D vector opt which holds the minimal penalty scores at each step. Key functions include optDistance, which computes the optimal distance between segments of the sequences; alignment, which reconstructs the alignment from the scoring matrix; penalty, which assigns a cost to mismatches, gaps, and matches ; and min3, a helper function used to find the minimum of three values, facilitating the determination of the minimal score by comparing different possible alignments.

### Testing
Runs 5 tests testing different features as well as some different alignments to make sure things line up properly

### Issues
Unit tests are not passing the autograder's mettle

## Analysis

### Example
Do one additional test case by hand. It should be constructed in such a way that you know the correct  output before running your program on it, and it should be a "corner case" that helps check if your program handles all special situations correctly. 

Please list:
 - a copy of the test case input
 - the expected test case output
 - whether your program ran correctly on it or not
 - optionally, any other remarks
 
 

### Specs
Ran on a VM
Memory: 4GB alloted to VM, 16GB total in the machine
Processors: i7-12700h, 14 cores @2.7GHz(4 alloted to VM)

Partner's Computer
Memory: 16GB
Processors: i7 10710u, 6 cores @1.1Ghz

### Runs
Fill in the table with the results of running your code on both your and your partner's computers.

| data file     | distance | memory (mb) | time (seconds) | partner time |
|---------------|----------|-------------|----------------|--------------|
|ecoli2500.txt  |   118    |   24.07     |   0.116448     |  0.171335s   |
|ecoli5000.txt  |   160    |   95.76     |   0.436532     |  0.646549s   |
|ecoli10000.txt |   223    |   382.2     |   1.83781      |  2.55383s    |
|ecoli20000.txt |   3135   |   1491      |   8.06143      |  16.8475s    |
|ecoli50000.txt |          |             |    killed      |  killed      |
|ecoli100000.txt|          |             |    killed      |  killed      |

Here is an example from another computer for some of the files.

| data file    | distance | time (s) |
|--------------|----------|----------|
|ecoli2500.txt |      118 |    0.171 |
|ecoli5000.txt |      160 |    0.529 |
|ecoli7000.txt |      194 |    0.990 |
|ecoli10000.txt|      223 |    1.972 |
|ecoli20000.txt|     3135 |    7.730 |

### Time
Assume the two strings are the same length (M = N).  By applying the doubling method to the data points that you obtained, estimate the running time of youu program in seconds as a polynomial function of N, in the form a * N^b for some constants a and b.  Determine the largest input your program can handle if it is limited to one day of computation.

Using getting averages and then applying the doubling method to each, we got the following:
 - a = 0.000001724
 - b = 2.03
 - largest N = 7341

### Memory
Assume the two strings are the same length (M = N).  Look at your code and determine how much memory it requires as a polynomial function of N, in the form a * N^b for some constants a and b.  Determine the largest input size your computer can handle if limited to 8GiB of RAM.
 - a = 4
 - b = 2
 - largest N = ~400

### Valgrind
Yes, it was relatively close to what I expected it to be, but it wasnt exact not just due to performance differences but also due to the fact that I am running things on a VM with limited RAM and cores, so extrapolation of data can only go so far.

## Pair Programming
We really like the Pair Programming method and both really appreciated the extra insight we lent each other. However, we often found ourselves both splitting off to work on the project separately and then come back together and compare notes. While we did often work together on one computer, we had vastly different thought processes and found it difficult to not nit pick the other's attempts. Overall though it was still about a 50/50 split of  using shared editor and two separate editors.

## Extra Credit
Anything special you did.  This is required to earn bonus points.

## Acknowledgements
Tutoring center
