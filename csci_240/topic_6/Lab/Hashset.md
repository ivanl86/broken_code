## Description
A Set is a type of collection that will hold exactly one of any object or value based on its *key*. If used to store an object, the **equality** operator of the object will need to be overloaded to determine if one object is equal to another. If the client program tries to insert two equal items, the set will simply not store the second one. 

A hashset is a set that requires a **hashcode** function to be defined for for the items stored in it to store and retrieve the items in constant time. This function need not be in the object itself but can be defined anywhere that it can be accessed. A better way of providing it is to pass it into the constructor of the hashset. 

Note: two objects with different keys (objects that are not equal) could generate the same hash code and/or be compressed such that the hash function will generate the same index at which to store those objects (a collision). 

## Set ADT
The set ADT has the following operations:
- insert(item): Inserts an item into the set. Returns true if successful or false otherwise.
- erase(item): Removes an item from the Set. Returns true if the item was successfully removed or false otherwise.
- find(item): Returns a constant reference to an item if it exists or null otherwise
- size(): Returns the number of items stored in the set. 
- contains(item): Returns true of the item is a member of the set or false otherwise.

## Activity
In this exercise you must create **two classes** that implement the provided interface, *Set*, using two different probing methods. **Note: Do not alter the interface in any way**. 

You will implement the two hashsets with an array of size 157. These two hash sets should be called **HashSetLP** (uses linear probing), and **HashSetQP** (uses quadratic probing).  Use an item’s hashcode function, passed into the constructor, and a compression function that should be integral to the hashset class that will generate an array subscript at which to store the item. Do not allow more than 27 probing attempts. If you cannot find a location in which to store the item after 27 attempts, return false from the function under execution.  

The hashsets should resize dynamically when they reach 60% occupancy. On a resize you will need to locate each item in the set and recalculate it's destination bucket because the size of the array has changed. In the new array. In the new array be sure to initialize the status of all buckets to a **Empty** status.
 
For a compression algorithm, implement the division method: $h_2(k) = |k|\, MOD\, n$, where n = the size of the array. 

When an item is removed, you will not need to relocate any items that were entered using probing. You should create a struct to hold the item of type T and a status variable to show if each bucket in the array has been: 
- **Occupied**: holds an item
- **Empty**: the element has never been used
- **Available**: the element was occupied but the item has been removed

Use an enum for these status.
  
Test your program thoroughly.

## What to submit:
-   hashset_lp.h, hashset_qp.h and your test program.