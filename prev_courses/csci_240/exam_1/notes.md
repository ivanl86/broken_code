
# Exam 1 Notes
## Polymorphism
- the same entity behaves differently in different scenarios

## Memory Layouts
### Highest Memory Address
#### Stack
- store all local variables
- passing arguments
- all recursive function calls are added to here
#### Heap
- dynamic memory allocation happens here
#### BSS (Block Starting Symbol)
- uninitialized data stores here
- all uninitialized global and static variables store here
#### Data
- initialized data stores here
- all predefined global, static, constant, and external variables store here
- can be both read-only and read-write
#### Text
- machine code of compiled program stores here
- usually read-only
### Lowest Memory Address

## Data structure types
- stack
- queue
- linked list
- node
- deque

## Adstract Data Type
- a model of a data structure
- defines the characteristics of the collection of data
- defines the operations that can performed on the collection
- does not specify how the ADT wil be implemented
- a given ADT can have multiple implementations

## Algorithms
- a procedure for sovling a problem

## Static Member Functions
- static member functions belong to the class as a whole
- have no access to the data members of the class

## Growth Function
### Big O = worst case
- O(g(n)) = f(n)
## Big Omega = best case
- f(n) >= g(n) for n such that n >= n0
### Big Theta = average case
- c'g(n) <= f(n) <= c"g(n)
#### Example
- f(n) = 5n^4 + 3n^3 + 2n + 1
- cg(n) = (5 + 3 + 2 + 1)n^4
- cg(n) = 11n^4, where n >= 1
- c = 11, g(n) = n^4
- O(n^4) = f(n)
#### Recursive Function (n - k)
- T(n) = 1 + T(n - k)
- n - k = 1
- k = n - 1
- T(n) = n - 1 + 1 = n
- O(n) = f(n)
#### Recursive Function (n - n/2^k)
- T(n) = 1 + T(n - n/2^k)
- n/2^k = 1
- n = 2^k
- log(n) = log(2^k)
- log(n) = k
- T(n) = log(n) + 1
- f(n) = O(log(n))