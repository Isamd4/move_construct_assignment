# move_construct_assignment


# MoveArrayList Project

## Overview

This project demonstrates the use of move semantics in C++ by extending a basic `ArrayList` class to create a `MoveArrayList` class. The `MoveArrayList` class includes move constructor and move assignment operator functionality, which allows for efficient transfer of resources between instances. This can significantly improve performance when dealing with temporary objects or in situations where copying is not necessary.

## Classes

### ArrayList

The `ArrayList` class provides basic functionality for managing a dynamic array. It includes:
- A default constructor
- A parameterized constructor
- A destructor
- A copy constructor
- A copy assignment operator

### MoveArrayList

The `MoveArrayList` class inherits from `ArrayList` and adds the following:
- A move constructor
- A move assignment operator

The `MoveArrayList` class leverages the copy constructor and copy assignment operator from the `ArrayList` class for copying behavior, while introducing move semantics for efficient resource management.

## Key Features

- Inherits constructors and methods from `ArrayList`.
- Implements a move constructor to transfer ownership of resources.
- Implements a move assignment operator to handle resource transfer.
- Utilizes the existing copy constructor and copy assignment operator from `ArrayList` for copying behavior.

## Performance

### Timing Results

- **Copy constructor**: 13.245 milliseconds
- **Move constructor**: 0.023 milliseconds

The move constructor is approximately 57,435% faster than the copy constructor, demonstrating the efficiency gains provided by move semantics.

## Usage

### Example

The following example shows how to use the `MoveArrayList` class:

```cpp
#include <iostream>

int main() {
    MoveArrayList<int> list1(10);    // Uses parameterized constructor
    MoveArrayList<int> list2 = std::move(list1); // Uses move constructor

    MoveArrayList<int> list3;
    list3 = std::move(list2); // Uses move assignment operator

    MoveArrayList<int> list4(list3); // Uses copy constructor
    MoveArrayList<int> list5;
    list5 = list4; // Uses copy assignment operator

    std::cout << "Program completed successfully.\n";
    return 0;
}
