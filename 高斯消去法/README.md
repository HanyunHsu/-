# OOP with C++ (and more)
#### Spring, 2023
#### Prof Y C Cheng
#### Dept of Computer Science and Information Engineering
#### Taipei Tech

## Assignment 4

### Due: 11:59 p.m., 31 March 2023 WED

### Purpose of this assignment:

Learn how to use class.

### Problems:

We've learened how to define and initialize a class. In this assignment, we need to use `MathVector` design a function `gaussion_elimination`. 

https://en.wikipedia.org/wiki/Gaussian_elimination  

Please refer to the link above.  

Input of the function `gaussion_elimination` is an [augmented matrix](https://en.wikipedia.org/wiki/Augmented_matrix) represented as a `std::vector<MathVector>`
After the calculation of Gaussian elimination,
We will get a [reduced row echelon form](https://en.wikipedia.org/wiki/Row_echelon_form#Reduced_row_echelon_form) (or called row canonical form) of it.

Example:
``` c++
# Unique solution
MathVector v1 = {{2, 1, -1, 8}};
MathVector v2 = {{-3, -1, 2, -11}};
MathVector v3 = {{-2, 1, 2, -3}};

std::vector<MathVector> matrix = {v1, v2, v3};

std::vector<MathVector> result = gaussian_elimination(matrix);

# Output should be
# First MathVector in result:  {1, 0, 0, 2}
# Second MathVector in result: {0, 1, 0, 3}
# Third MathVector in result:  {0, 0, 1, -1}
```
``` c++
# Infinitely many solutions
MathVector v1 = {{2, 4, 6, 10}};
MathVector v2 = {{1, 2, 3, 5}};

std::vector<MathVector> matrix = {v1, v2};

std::vector<MathVector> result = gaussian_elimination(matrix);

# Output should be
# First MathVector in result:  {1, 2, 3, 5}
# Second MathVector in result: {0, 0, 0, 0}  
```
``` c++
# No solution
MathVector v1 = {{1, 2, 3, 4}};
MathVector v2 = {{4, 5, 6, 7}};
MathVector v2 = {{7, 8, 9, 10}};

std::vector<MathVector> matrix = {v1, v2, v3};

std::vector<MathVector> result = gaussian_elimination(matrix);

# Output should be
# First MathVector in result:  {1, 0, -1, -2}
# Second MathVector in result: {0, 1, 2, 3}
# Third MathVector in result: {0, 0, 0, 0}
```
  
score:
- gaussion_elimination (30%)
- Your tests:
    - gaussion_elimination:
        - Unique solution (10%)
        - Infinitely many solutions (10%)
        - No solution (10%)
- TA's Tests (40%)

Notes:
- Your tests should cover cases where you have a unique solution, infinitely many solutions or no solution.
- Please implement the code reasonably, or you will get no point for that sub-problem.