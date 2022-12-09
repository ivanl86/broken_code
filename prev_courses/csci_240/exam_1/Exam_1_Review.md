# Exam 1
## Section 1
1. While loop
2. For loop
3. 
    - is-a: inheritance where a class is defined by the inheriting of another class's members(public, protected)
    - has-a: composition or aggregation: an instance of a class is the member of another class
4. 
    - template(typename T)
    - struct Sack
    - {
    -   virtual void put(T) = 0;
    -   virtual T grab() = 0;
    -   virtual T look() = 0;    
    -   bool empty() = 0;
    - };
5. 
    - polymorphism: a variable of the base class can reference(poinnt to) objects of the  derived class. we can treat instances of the derived class as the object of the base class
    - inheritance: 
## Section 2
1.  - data structure: an encpsulation of (a collection of) related data and oprations that can be performed on them
    - example: 
2. - ADT: abstract data type (design element), it is the description of the operations (not implementation) of a data structure (can be written in pseudocode)
3.  
    - a. uses pointers of references to link objects in memory
    - b. Node
    - c. doubly-linked, circular-linked
4. 
    - In the heap
    - pro: dynamic in size
    - con: runtime overhead (management), no special locality - cache misses
## Section 3
1. 
    - LIFO: last in first out
    - example: stack of plate - last plate of the stack(top) is the first plate used 
2. 
    - template(typename T)
    - struct Class
    - {
    -   virtual void push(T) = 0;
    -   virtual T peek() = 0;
    -   virtual T pop() = 0;
    -   virtual bool empty () = 0;
    - };
3. No, stack is simple. It is processed until empty
4. 
    - void clear()
    - {
    -   Node(T) *t = nullptr;
    -   while (t = top)
    -   {
    -   top = top->next;
    -   delete t;
    -   }
    - }
## Section 4
1. 
    - FIFO: first in first out
    - example: line at bakery (take a number)
2. 
    - templete(tyepname T)
    - class Queue
    - {
    -   public:
    -   virtual void enqueue(T) = 0;
    -   virtual T dequeue() = 0;
    -   virtual T front() = 0;
    -   bool empty() = 0;
    - }
3. No, we use a front and back pointer to reference the list. Enqueue on the back and dequeue from the front
4. 
    - void enqueue(T item)
    - {
    -   Node(T) *newNode{new Node(T)(item)};
    -   if (empty())
    -   {
    -   back = newNode;
    -   front = back;
    -   }
    -   else
    -   {
    -   back->next = newNode;
    -   back = newNode;
    -   }
    - }
5. 
    1. O(n)
    2. 
        1. T(n) = 2T(n/2) + n
        2. T(n/2) = 2T(n/4) + (1/2)n
        3. T(n/4) = 2T(n/8) + (1/4)n
        4. plug 2 into 1
        - T(n) = 2(2T(n/4) + (1/2)n) + n
        - T(n) = 4T(n/4) + 2n
        5. plug 3 into 4
        - T(n) = 4(T(n/8)) + (1/4)n) + 2n
        - T(n) = 8T(n/8) + 3n
        - T(n) = (2^k)T(n/2^k) + kn
        - n/2^k = 1
        - n = 2^k
        - log2(n) = k
        -  = n + (log2(n))n
