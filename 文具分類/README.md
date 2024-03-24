# OOP with C++ (and more)
#### Spring, 2023
#### Prof Y C Cheng
#### Dept of Computer Science and Information Engineering
#### Taipei Tech

## Assignment 6

### Due: 11:59 p.m., 3 May 2023 FRI

### Purpose of this assignment:

Practice polymorphism and template function.

### Problems:
Implement a C++ program that uses polymorphism to model different types of stationery items, such as pencils and erasers. You should create an base class called `Stationery` that has virtual methods for calculating the `price` and its `name` (Don't need to consider the default value). Then, create two concrete subclasses called `Pencil` and `Eraser` that inherit from the Stationery class and implement their own versions of the price and name methods.

#### Folder Structure
You will have the following folder structure.
```
├── src
│   ├── eraser.h
│   ├── pencil.h
│   ├── sort.h
│   └── stationery.h
├── test
│   ├── eraser_test.h
│   ├── pencil_test.h
│   ├── stationery_sort_test.h
│   └── test_main.cpp
├── .gitignore
└── makefile
```

Here are some additional details and requirements for the program:

#### Pencil
- The Pencil class should have two private data member for the `length` of the pencil and the `hardness` of the pencil.
- Constructor of Pencil accept `double length` and `std::string hardness` as its parameter.
- There are five kinds of `hardness`: `2H`, `H`, `HB`, `B`, and `2B`.
- The length of the pencil should greater than 0 and less or equal than 50.
- The price of a pencil should be calculated based on its length and hardness, the numbers to the hardness are as follow:  

    | hardness | number |
    | -------- | ------ |
    | 2H       | 2.6    |
    | H        | 3.1    |
    | HB       | 1.9    |
    | B        | 2.5    |
    | 2B       | 2.0    |

so the price of a `Pencil(15, 'HB')` should be 28.5 (15 * 1.9)
- The name of the pencil should be `{hardness} Pencil`.(e.g. Name of `Pencil(20, '2H')` is "2H Pencil")
- If the input of price or hardness is invalid, it should throw exceptions.

#### Eraser
- The Eraser class should have two private data member for the `size` of the eraser (e.g. `Small`, `Medium`, `Large`) and the brand of the eraser (e.g. `Staedtler`, `MUJI`, `Pentel`)
- Constructor of Eraser accept `std::string eraser` and `std::string brand` as its parameter.
- The price of an eraser should be calculated based on its size and brand, the numbers to the size and the numbers to the brand are as follow:  

    | size   | number |
    |--------|--------|
    | Small  | 1      |
    | Medium | 2      |
    | Large  | 4      |

    | brand     | number |
    |-----------|--------|
    | Staedtler | 15     |
    | MUJI      | 29     |
    | Pentel    | 39     |

so the price of a `Eraser("Medium", 'MUJI')` should be 58 (2 * 29)
- The name of the eraser should be `{size} {brand} Eraser`.(e.g. Name of `Eraser("Large", 'MUJI')` is "Large MUJI Eraser")
- If the input of size or brand is invalid, it should throw exceptions.

### Template function of sort
We are going to learn how to write a template function. In this part, we need to design a template function `sortByPrice` that can accept three kinds of vectors (`std::vector<Stationery *>`, `std::vector<Pencil *>`, `std::vector<Eraser *>`) and sort them by their price in `ascending` order. This function will be put in the `sort.h`.

Example:
```
Pencil p1(18, "H");
Pencil p2(15, "2B");
Pencil p3(12, "2H");
Eraser e1("Large", "MUJI");

std::vector<Stationery *> items = {&p1, &p2, &p3, &e1};
sortByPrice(items);

# the first item of the items should be p2
# the second item of the items should be p3
# the third item of the items should be p1
# the last item of the items should be e1
```

score:
- src:
    - Stationery, Pencil, Eraser (15%)
    - sortByPrice (15%)
- tests:
    - pencil and eraser tests (15%)
    - sortByPrice tests (15%)
- TA tests (40%)

Notes:
- Please implement the code reasonably, or you will get no point for that sub-problem.
