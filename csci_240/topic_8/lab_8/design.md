# Lab 8
## Set ADT
- set ADT provides the interface for the ordered set
- the ADT is provided by professor
## Ordered Set
- ordered set should inherit set
- use the inorder traversal to make it ordered
- the inorder traversal function is used for ascending order
## Binary Search Tree (BST)
- the data stucture to hold the data
- the constructor takes in a comparator function to order the set
- left child is smaller than or equal to the parent
- right child is greater than the parent
- duplicate is not added for the ordered set
- use iterator to traversal through the tree
- the iterator is used for
- position represent the number of item in the inorder traversal
## Set Functions
- insert(item)
    - inserts an item into the set if there is no duplicate and return true
    - otherwise do not insert and return false
- erase(item)
    - remove an item if found and return true
    - if not found, return false
    - the removed node should be replaced by another node either through rotate or copy a node from lower level
- erase(position)
    - find the item in the position using inorder traversal
    - removed the item by calling erase(item)
    - return false if the item is not found
- clear()
    - removes all the nodes in the tree
- empty()
    - use 