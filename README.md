# CPP_Modules
Project is an introduction to C++ language at School21/Ecole42.

Each module is dedicated to some aspects of C++ language and helps to get acquainted with language syntax, constructions and tools.

## General rules
- According to project requirements all programs are compiled using <code>c++</code>, <code>-std=c++98</code>, <code>-Wall- Wextra -Werror</code> flags.
- Each task contains own Makefile that compiles the program.

## CPP Module 00

Whole module is dedicated to Namespaces, classes, member functions, stdio streams, initialization lists, static, const, and some other language basics.

[ex00](https://github.com/D-Dashka/CPP-Modules/tree/main/CPP_00/ex00)

Simple program as an introduction to <code>std::cout</code>

[ex01](https://github.com/D-Dashka/CPP-Modules/tree/main/CPP_00/ex01)

The program represents a phonebook that can read from STDIN three commands **ADD**, **SEARCH**, **EXIT** in a loop and store maximum up to 8 contacts.
9th contact will erase and replace the oldest contact in the phonebook.

[ex01](https://github.com/D-Dashka/CPP-Modules/tree/main/CPP_00/ex02)

The main goal of the task is to reconstruct the <code>Account.cpp</code> upon given <code>Account.hpp</code> and <code>intra.log</code> file.

## CPP Module 01

Module is dedicated to memory allocation, pointers to members, references, switch statement.

## CPP Module 02

Module is dedicated to polymorphism, operator overloading and Orthodox Canonical class form.

[ex00 - ex02](https://github.com/D-Dashka/CPP-Modules/tree/main/CPP_02)

Creation of a class that can store a fixed-point variable.

[ex03](https://github.com/D-Dashka/CPP-Modules/tree/main/CPP_02/ex03)

The task is to implement bsp function that uses Fixed and Point class from previous exercises and should determine whether the point with given coordinates is inside the triangle or not.

## CPP Module 03

Module is an introduction to inheritance.

[ex00 - ex02](https://github.com/D-Dashka/CPP-Modules/tree/main/CPP_03)

Implementation of base class and derived classes.

[ex03](https://github.com/D-Dashka/CPP-Modules/tree/main/CPP_03/ex03)

Task is dedicated to solving Diamond problem.

```
	     ClapTrap
	    /       \
	   /         \
	  /           \
       ScavTrap    FragTrap
     	  \           /
	   \         /
	    \       /
	   DiamondTrap
```

## CPP Module 04

Introductoin to subtype polymorphism, abstract classes, interfaces.

[ex00 - ex02](https://github.com/D-Dashka/CPP-Modules/tree/main/CPP_04)

Implementation of base and pure virtual classes and its derived classes.

[ex03](https://github.com/D-Dashka/CPP-Modules/tree/main/CPP_04/ex03)

Implementation of several pure virtual classes and interfaces.
The whole program resembles the game where character has some inventory slots to store materia (attack or heal) and actions that he/she can aplly on others.

## CPP Module 05

[ex00 - ex03](https://github.com/D-Dashka/CPP-Modules/tree/main/CPP_05)

The whole module is dedicated to usage of exception

## CPP Module 06

C++ type casting

[ex00](https://github.com/D-Dashka/CPP-Modules/tree/main/CPP_06/ex00)

<code>static_cast<></code>

[ex01](https://github.com/D-Dashka/CPP-Modules/tree/main/CPP_06/ex01)

<code>reinterpret_cast<></code>

[ex02](https://github.com/D-Dashka/CPP-Modules/tree/main/CPP_06/ex02)

<code>dynamic_cast<></code>

## CPP Module 07

The module is an introduction to templates in C++.

[ex00 - ex02](https://github.com/D-Dashka/CPP-Modules/tree/main/CPP_07)

## CPP Module 08

The module is about templated containers, iterators, algorithms.
The module encourages to use STL and Algorithms libraries in C++.

[ex00 - ex01](https://github.com/D-Dashka/CPP-Modules/tree/main/CPP_08)

Introduction to algorithms and iterators in C++.

[ex02](https://github.com/D-Dashka/CPP-Modules/tree/main/CPP_08)

Implementation of <code>std::stack</code> class with additional feature: the class should be iterable.

## CPP Module 09

The module is dedicated to usage of Container classes.

[ex00](https://github.com/D-Daria/CPP-Modules/tree/main/CPP_09/ex00)

Program should output the value of certain amount of bitcoin on a certain date. It reads `input` file, comparing corresponding dates with those in `data.csv` and make an exchange depending on rate.

data.csv

```
date,exchange_rate
2009-01-02,0
2009-01-05,0
2009-01-08,0
2009-01-11,0
2009-01-14,0
2009-01-17,0
2009-01-20,0
...
```

input

```
date | value
2005-02-02 | 0.1
2011-09-14 | 390.57
2010-11-03 | 517.239
2020-06-26 | 998.808
2012-07-09 | 1242.2
2019-07-11 | 700.492
2019-06-25 | 416.636
2017-05-22 | 507.753
...
```

[ex01](https://github.com/D-Daria/CPP-Modules/tree/main/CPP_09/ex01)

Implementation of Reverse Polish notation

[ex02](https://github.com/D-Daria/CPP-Modules/tree/main/CPP_09/ex02)

The aim is to implement merge insertion sort algorithm using two different containers and compare the time spent by both containers on data management and sorting.
