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
- an almost full binary tree; the  bottom level of the tree is filling from left to right but may not have its full complement of leaves
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
- process nodes one level at at time (visiting nodes in each level from left to right)
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
- n p = ceil((n-1)/2)

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
- n is the size of array
- h2 = (h1(k) & 0x7FFFFFFF) mod n