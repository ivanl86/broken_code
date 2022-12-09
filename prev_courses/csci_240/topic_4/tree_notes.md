# Tree Notes
## Terminology of Tree
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
## The Properites of Full and Complete Binary Tree
### Full Binary Tree
- all interanl nodes have two children, and all leaves are at the same depth
### Complete Binary Tree
- an almost full binary tree; the bottom level of the tree is filling from left to right but may not have its full complement of leaves
## Pre-order Traversal
- process the root
- process the nodes in the left subtree with a recursive call
- process the nodes in the right subtree with a recursvie call
- call in the stack
## In-order Traversal
- process the nodes in the left subtree with a recursive call
- process the root
- process the nodes in the right subtree with a recursvie call
## Post-order Traversal
- process the nodes in the left subtree with a recursive call
- process the nodes in the right subtree with a recursvie call
- process the root
## Level-order Traversal
- process the root
- process nodes one level at at time (visiting nodes in each level from left to right)
- call in the queue