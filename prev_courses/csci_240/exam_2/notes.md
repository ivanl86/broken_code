# Lecture Notes

## hierarchical data structure
- tree place data in hierarchical  structure
- tree a collection of nodes connected by edges
- edges is the line to connect nodes
- graph has cycle
- tree has no cycle
- file directories
## Terminology
- level: the level of a node represents that node's hierarchy
- root: a single node at the top level
children: the nodes at each succesive level of a tree are the children of the nodes at the previous level
- parent: a node that has children is the parent of those children
- leaf: a node has no children
- subtree: any node and its descendants form a subtree of the original tree
- sibling: sibling nodes share the same parent node
- uncles: siblings of that node's parent
- ancestor: a node that is connected to all lower-level nodes
- descendant: the connected lower-level nodes are "descendants" of the ancestor node
- edge: connectin between one node to another
- path: a sequence of nodes and edges connecting a node with a descendant
- height of node: the number of nodes on the longest path  between that node and a leaf + 1
- height of tree: the height of its root node
- depth of node: the number of edges from the tree's root node to the node+1
- a tree can have an arbitrary number of children
- N-ary Tree: each nodes has no more than n number of children
- binary tree: each node has at most two children
- ternary tree: each node has at most three children
## full binary tree
- all interanl nodes have two children, and all leaves are at the same depth
- a complete tree with all leaf nodes filling their level
## complete binary tree
- an almost full binary tree; the bottom level of the tree is filling from left to right but may not have its full complement of leaves
- all internal nodes have two children and leaf nodes and all of the leaves are on the same level filling left to right

### the nubmer of nodes in a full binary tree of height h is:
- n = 2^h - 1
### the height of a full or complete binary tree having n nodes:
- h = ceil(log2(n + 1))
### the number of leaf nodes in a full binary tree having a height h is
- n = 2^(h - 1)
### the number of non leaf nodes in a full binary tree having a height h is
- n = 2^(h - 1) - 1
### the number of non leaf nodes in a complete binary tree having a number of nodes n:
- nl = ceil((n-1)/2)
## Balanced binary tree
- subtrees of each node in the tree differ in height by no more than 1
## Pre-order Traversal
- process the root
- process the nodes in the left subtree with a recursive call
- process the nodes in the right subtree with a recursvie call
- call in the stack
- pesudo code
preOrder(root)
{
    if root == null
        return
    process(root)
    preOrder(root.left)
    preOrder(root.right)
}
## In-order Traversal
- process the nodes in the left subtree with a recursive call
- process the root
- process the nodes in the right subtree with a recursvie call
- pesudo code
inOrder(root)
{
    if root == null
        return
    inOrder(root.left)
    process(root)
    inOrder(root.right)
}
## Post-order Traversal
- process the nodes in the left subtree with a recursive call
- process the nodes in the right subtree with a recursvie call
- process the root
- pesudo code
postOrder(root)
{
    if root == null
        return
    postOrder(root.left)
    postOrder(root.right)
    process(left)
}
## Level-order Traversal
- process the root
- process nodes one level at a time (visiting nodes in each level from left to right)
- call in the queue
## Find out how each traversal work

## Formulas for the array representation
- the data from the root always appears in the [1] component of the array
- left child at component [2i] or [i<<1]
- right child at component [2i+1] or [i<<1+1]
- parent at component [i>>1] of the child
## Node Representation
- each node of a binary tree can be stored as an object of a binary tree node class
- the class contains instance variables that are pointers to other nodes in the tree
- an entire tree is represented as a pointer to the root node
- the pointer to the  root is similar to the head of a linked list, providing a starting point to access all the nodes in the tree
- we could include other things in the tree node
- height should be included in the node
template<typename T>
struct Node
{
    T item;
    Node<T> leftChild;
    Node<T> rightChild;   
};
## Heap ADT
- is a complete binary tree
- add: adds an item to the heap in a way that maintains the heaps structure
- remove: removes and returns an item while maintains the structure of the heap
- root: return but does not remove the root of the heap
- clear: empties the heap
- size: return quantity of items in the heap
### Max Heap
- is a heap where every child item is <= parent
- add: adds an item such that the requirement of the max heap is satisfied
- max (root): return the max value in the heap without removing it
- remove: removes and returns the max item
- clear:
- size:
### Max Heap Example
- when adding an item, it becomes the last leaf
- upheap: compare root of subtree with  its children, if lesser, then swap with greatest child
- upheap is recursive if swap call on parent
- downheap: compare changed element with children, if lesser, then swap with grestest cild
### Min Heap
- is a heap where every child item is >= parent
- add: adds an item such that the requirement of the min heap is satisfied
- min (root): return the min value in the heap without removing it
- remove: removes and returns the min item
- clear: 
- size:
## Priority Queue


##
- n = number of nodes in a complete binary tree
- number of non-leaf nodes = ceil((n-1)/2)

##
- heapify
-   for i = np to 1
-       idx = compare(i)
-           if idx != i
                swap(i, idx)
            end if
        next i

## Hashing (Hashmap or Hashtable)
- a hashmap is a map that provide BigO(a) complexity on almost all operations

## Map
- is a ADT
- size: returns number of items stored
- empty: returns true if zero items or false otherwise
- put: adds (K, V) to the map
- find: finds and returns valus of the key
- erase: remove (K, V) for K

### Hash question
- a hash function, h, is a one way function that takes an input and generates an almost unique ineger value (fingerprint)
- given  h(k) = k' (k prime)
- there is no function h'(k') = k 
### h2 - Compression
- return h1(k) mod n
- assume int is 4 byte
- n is the size of array of the buckets, is best when its prime
- h2 = (h1(k) & 0x7FFFFFFF) mod n
### Compression Methods
- assume n is the size of array and is prime
- Division: |h1(k)| % n = h2(k)
- MAD: [(a|h1(k)| + b) % p] % n = h2(k), p is prime and p > n, a & b [p, p - 1], a > 0, a and b are co-prime

### Keyvalue
- available
    - was used but is now unused
- occupied
    - used
- unoccupied
    - never been used
### Example
- enum State{ available, occupied, unoccupied }
- struct KVPair
- {
-   K key;
-   V value;
-   State state;
- }
### Linear Probing
- i = h(k)
- for j = 0 to n - 1
-   i = (h2(k) + j) % n
- i is the subscript under inspection
### Quadratic Probing
- f(j) = j * j
- i = h(k) + f(j)
- for j = 0, 1, 2,...
- h(k<sub>1</sub>) = h(k<sub>2</sub>)
### Loading Factor
- qty/n
- resize when >= 0.75
### Linked list
- con: add, search, remove of an ordered link list is usually O(n)
### Skip list
- add, remove, search of a skip list is O( $log_2 n) with a high probability
- def: skip list is a probabilistic DS that allows a high prob of O( $log<sub>2</sub>(n) ) complexity
- add: start at highest level
- search for the greatest key that is <= the search term. If found or null, begin at that node or null on the next lower level
- if a key is found, replace value with the new value
- insert: for item, the element to be inserted, search the list to find where the item fits
    - this will be the node with the greatest item less than or equal to the item being inserted
    - always insert the element into the bottom level (L0)
- with a probability of 0.5, insert the item into level 1 (L1) of the list
    - this is called a promotion
- if inserted into L1, then with a 0.5 probability, insert into L2
- follow thi procedure until the item is not inserted into a level or there are no more levels to insert into
- delete: seach for the item to remove
- if it exists, remove it and its tower, otherwise, do nothing
- search: start at the beginning of the highest level and search for the node with  the  greatest item value <= the search item
    - if an item was found that equals search term then return a reference to the bottom most node in that column
- drop to the level below and continue the search from the node that was found in the previous step
    - if an item was found with  the same value as the search term then return a reference to the bottom most node in the column
- continue the same process droppping down each level until the bottom level is reached
    - return a reference to the node that contains the greatest item <= the search item
- question: can this be implemented as a single linked list with a finite number of levels and a modified node?
### Graph