/**
 * @class MyClass
 * @brief A class that extends  to add move semantics.
 * 
 * The MyCass class inherits from ArrayList
 * (https://github.com/egaebel/Array-List--Cplusplus.git) and adds move constructor
 * and move assignment operator functionality. This allows MyClass to 
 * efficiently transfer resources from one instance to another without 
 * performing deep copies, which can enhance performance when dealing with 
 * temporary objects or in situations where copying is not necessary.
 * 
 * Features:
 * - Inherits constructors and methods from ArrayList.
 * - Implements move constructor.
 * - Implements move assignment.
 * - Utilizes the existing copy constructor and copy assignment operator 
 *   from ArrayList for copying behavior.
 * - Compares the performance of the type of constructors and assignemts
 */
#include "ArrayList.h"
#include <iostream>
#include <chrono>
using namespace std;
template <typename T>
class MyClass : public ArrayList<T>{
public:
    //Default Constructor
    MyClass() : ArrayList<T>() {}
    //Constructor with size
    MyClass(int size) : ArrayList<T>(size) {}
    //Move Constructor
    MyClass(MyClass &&other) : ArrayList<T>(){
        std::cout << "Hi move constructor" << std::endl;
        this->array = new T[other.getSize()];
        this->capacity = other.getSize();
        this->size = other.getSize();
        this->array = other.array;
        other.size = 0;
        other.array = nullptr;
    }
    //Move assignment
    MyClass &operator=(MyClass &&other){
        std::cout << "Hi move assignment";
        delete[] this->array;
        this->size = other.size;
        this->array = other.array;
        other.size = 0;
        other.array = nullptr;
        return *this;
    }
    //Copy Constructor
    MyClass(const MyClass &other):ArrayList<T>(other){}
    //Copy Assignemt
    MyClass &operator=(const MyClass &other){
        ArrayList<T>::operator = (other);
    };
};

int main(void){
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

