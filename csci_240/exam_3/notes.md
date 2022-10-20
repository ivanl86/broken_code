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
##
    vector<Node *> levels