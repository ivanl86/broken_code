# Project 2: Skip List
### CSCi 240
### Fall 2022

## Skip List
Skip lists provide for faster operations compared to a linked list. The word, "List," in "linked list," has a meaning all its own. There is an abstract data type called, "List", which is an ordered collection with a certain set of operations and behaviors, but linked list is something different. The term simply refers to a technique of storing data in memory. The linked list does exhibit the behaviors and ordering of a *List* but the two terms do not mean the same thing. We will explore the *List* ATD soon.

The skip list is a modification on the linked list that requires, to achieve better performance, that the elements of the list be sorted. One might look at it from another perspective, the skip list provides better performance on operations when a sorted linked list is needed.

The skip list relies on stochastic operations when creating its structure. Because of this, its performance can only be estimated in terms of high probability. 

## Activity
Implement a skip list in the way discussed in class. 
You should adhere to the following requirements:
- Limit the use of memory
	- For every element stored in the list there should be only one node created.
- A node will contain a collection of node pointers for creating links to different nodes at different levels. 
- The node class that I give you **can be** modified
- If you want to create a doubly or n-ary linked list you can as long as you don't violate the other requirements
- The skip list class should take into its constructor a comparator so the client can determine its ordering (ascending or descending).
- The number of levels should not be fixed but should be dynamic.
- Strictly adhere to the interface
	- Do not add or remove public operations
	- You can, an should, include one or more constructor
- Your skip list class should not inherit any other class

## Design Notes
- You can use vectors in this project. 
	- They should be passed or returned by reference or pointer.
- It would be beneficial to write a separate utility (helper) function for searching for position. 
	- This function will be used by almost every public function.
- You should follow the principle of "least privilege". 
	- When passing items of type T to and returning them from functions.
	- They should be passed by reference and should be *const* where they should not be changed.
- Other valued design principles:
	- Prof.A's principle: Do not wait until your project works to refactor it into something you know to be correct; in the refactoring process you will irreparably break it and do double the work. Think about every line of code.
	- Write your code so that you'll be proud of it the completed project. These are the things that you can show at a job interview. 
	- Do not write a single C++ statement until you know how you are going to implement your class. Designing while coding is mistake on every level.
	- Don't lose site of the fact that these projects are meant to make you better programmers and to give you a better understanding of the data structure. Short cuts will only rob you of that experience.
	- Procrastination is the enemy of productivity, efficiency, and excellence. If you enjoy what you do you will not want to procrastinate.

## Submit 
- Submit a **zip** archive that contains all of the code that is required for the program to compile and run
	- You can also use, if you prefer: tar, gz, or 7z (my preferred). 