# notes
## polymorphism
- the same entity behaves differently in different scenarios

## class member access modifiers
- private
    - can be accessed by anybody
- protected
    - can be accessed by base members, friends, and derived classes
- public
    - can only be accessed by base members and friends

## class inheritance access modifiers
- private inheritance
    - public and protected inherited members become private and private inherited members stay inaccessible
- protected inheritance
    - public and protected inherited members become protected and private inherited members stay inaccessible
    - least common
- public inheritance
    - public inherited members stay public, protected inherited members stay protected and private inherited members inaccessible private
    - most common

## data member vs data function
- data members are the data variables
- data functions are the functions used to manipulate data members
- data members and data functions define the properties and behavior of the objects in a class

## base class exceptions
- class logic_error is the base class of several standard exception classes that indicate errors in porgram logic
- class runtime_error is the base class of several other standard exception classes that indicate execution-time errors

## try catch block

## stack unwinding
- when an exception is thrown but not caught in a particular scope, the function call stack is "unwound" and an an attempt is made to catch the exception in the next outer try catch block

## rethrow exception
try {
    if (false)
        throw exception();
}
catch (const exception&) {
    cout << "throw an exception";
    throw; // rethrow the same exception
}

## how do they terminate?
- by default, the termainzte handler calls abort when no catch handler can be found for a thrown exception

## noexcept operator
- when a function does not throw any exceptions and does not call any functions that throw exceptions, you can explicitly state that a function does throw exceptions
- this indicates to programmers that there is no need to call the function in a try catch block
- add noexcept to the right of the function's parameter list in both the prototype and the definition
- for a const member function, place noexcept after const
- if a funciton that is declared noexcept calls another function that throws an exception or executes a throw statement, the program terminates

## 3 file system mode

## keywords
- also known as reserved words
    - these words are already defined by the compiler and cannot be used as an identifier

## linked list
- static array
- pointer in the heap
- linked list

## function overloading
- when more than one definition for a function
- the compiler determine whcih definition to use by comparing the number and data type of arguments used to call the function

## operator overloading
- when more than one definition for a operator
- the compiler determine whcih definition to use by comparing the data type of arguments used to call the operator

## const keyword
- when const keyword it attached with any functions, pointers, and variables, it prevents that specific data to be modified
- example
const int num = 5; // a constant integer
const int *ptr = &num; // a pointer to a constant integer
int const *cptr = &num; // a constant pointer to an integer
const int const *ccptr = &num; // a constant pointer to a constant integer
void function() const // a constant function that cannot modify any member variables in the class

## namespace and memberspace resolution
- namespace is a declarative region that provides a scope to the identifiers inside it. It prevents name collisions
- exapmle
namespace except {
    void exception();
}

except::exception();

## pointer
- pointer is a integer variable that stores the memory address of an object
    - pointer is used to allocate new onjects on the heap
    - to pass functions to other functions
    - to iterate over elements in arrays or other data structures

## custom exception

## number system
- conversion from signed int to binary to hex
- example
- 16 bits
-172
1 2 5 10 21 43 86 172
1 0 1  0  1  1  0   0
0000 0000 1010 1100 // positive 172 in binary
1111 1111 0101 0011 // converting to -172
                  1
1111 1111 0101 0100 // binary
ff54 // hex

-1023
1 3 7 15 31 63 127 255 511 1023
1 1 1  1  1  1   1   1   1    1
0000 0011 1111 1111 // positive 1023 in binary
1111 1100 0000 0000 // converting to -1023
                  1
1111 1100 0000 0001 // binary
fc01 // hex

- conversion form unsigned int to binary to hex