#
## Binary Search Tree (BST)
### 1
- given N as the root of subtree
- N's left subtree only contains values less than N
- and its right  subtree contains values greater than N
### 2
- N's left and right subtrees are BST
### Complexity of BST 
- O(log<sub>2</sub>(N)) <=> O(N)
###
- height of parent = max(height of lchild, height of rchild) + 1
## AVL Tree
- height balanced (the height  of the two child subtrees of any node differ by at most one)
- rotations will be carried out ot arrange its nodes to restore balance
### Four Imbalance Cases
- N is the node at which the imbalance ocurred
    - N's left child's left subtree -> right rotation
    - N's right child's right subtree -> left rotation
    - N's left child's right subtree -> left right rotation
    - N's right child's left subtree -> right left rotation
##
    rotateRight(N)
    {
        temp t = N.lchild
        N.lchild = t.rchild
        t.rchild = N
        return t
    }
##
    rotateLeft(N)                             
    {
        temp t = N.rchild
        N.rchild = t.lchild
        t.lchild = N
        return t
    }
##
    rotateLeftRight(N)
    { 
        temp t = N.lchild
        N.lchild = rotateLeft(t)
        return rotateRight(N)
    }
##
    rotateRightLeft(N)
    {
        temp t = N.rchild
        N.rchild = rotateRight(t)
        return rotateLeft(N)
    }

## Skip List

## BST Rules
- entries stored only at internal nodes
- key stored at nodes in the left subtree of v are less than or equal to the key stored at v
- keys stored at nodes in the right subtree of v are greater than or equal to the key stored v
- an in-order traversal will return the keys in order
- search proceeds down the tree to found item or an external node
- new operation: splay
    - splay moves a node to the root using rotations
        - right rotation:
        - makes the left child x of a node node y into y's parent; y becomes the right child

## Multi-Way Search Tree
- a multi-way search tree is an ordered tree such that
    - each internal node has at least two children and stores d -1 key-element items(k<sub>j</sub>, o<sub>k</sub>), where d is the number of children
    - the leaves store no items and serve as placeholders
- a (2,4) tree is a multi-way search with the following properties
    - Node-size property: every internal node has at most 4 children
- Underflow and Transfer
    - to handle an underflow at node v with parent u, we consider two cases