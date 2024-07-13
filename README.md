# Move Construct Assignment



## Overview

This project demonstrates the use of move semantics in C++ by extending a basic `ArrayList`(ttps://github.com/egaebel/Array-List--Cplusplus.git) class to create a `MyClass` class. The `Myclass` class includes move constructor and move assignment operator functionality, which allows for efficient transfer of data between instances. This can significantly improve performance when dealing with temporary objects or in situations where copying is not necessary.

## Classes

### ArrayList

The `ArrayList` class provides basic functionality for managing an array. It includes:
- A default constructor
- A parameterized constructor
- A destructor
- A copy constructor
- A copy assignment operator
  
## Source
https://github.com/egaebel/Array-List--Cplusplus.git

### MyClass

The `MyClass` class inherits from `ArrayList` and adds the following:
- A move constructor
- A move assignment operator

The `MyClass` class leverages the copy constructor and copy assignment operator from the `ArrayList` class for copying behavior, while introducing move semantics for efficient resource management.

## Key Features

- Inherits constructors and methods from `ArrayList`.
- Implements a move constructor to transfer.
- Implements a move assignment operator.
- Utilizes the existing copy constructor and copy assignment operator from `ArrayList`.

## Performance

### Timing Results

- **Copy constructor**: 13.245 milliseconds
- **Move constructor**: 0.023 milliseconds

The move constructor is approximately 57,435% faster than the copy constructor, demonstrating the efficiency gains provided by move semantics.

## Usage

### NOTE: After pulling the ArrayList class, you need to change the class modifier from private to protected

### Example

The following example shows how to use the `MyClass` class:

```cpp
#include <iostream>

int main() {
    //create a list with a size 10000
    MyClass<int> myList(1000000);
    for (int i = 0; i < 1000000; i++){
        myList.add(i);
    }

    clock_t start_time = std::clock();
    cout << "Creating new List using copy constructor.\n";
    MyClass<int> copyhugeList(myList);
    clock_t end_time = std::clock();
    float diff = static_cast<float>(end_time - start_time); // static_cast
    diff /= CLOCKS_PER_SEC;                                 // POSIX-defined as 1000000
    std::cout << "Time: " << 1000 * diff << " milliseconds \n";

    cout << "Creating new List using move constructor.\n";
    start_time = std::clock();
    MyClass<int> movehugeList = std::move(myList);
    end_time = std::clock();
    diff = static_cast<float>(end_time - start_time); // static_cast
    diff /= CLOCKS_PER_SEC;                                 // POSIX-defined as 1000000
    std::cout << "Time: " << 1000 * diff << " milliseconds \n";

    // Timing Results:
    // Copy constructor: 13.245 milliseconds
    // Move constructor: 0.023 milliseconds
    // The move constructor is approximately 57435% faster than the copy constructor.
    return 0;
}
