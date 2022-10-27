# Skip List Design

## Skiplist Node
### Constructor
- initialize to nullptr?

## Constructor
- passes in a function to determine list is in ascending or descending order
- initialize itemQty to 0

## Add
- adds an item to level 0
- insert it based on its value in ascending order
- promote it to next level if gets promoted
- repeat promotion until not getting promoted
- increment 1 to itemQty

## Remove
- starts at the top level
- if found the item, remove the node and all of its connected bottom node
- if the next item found is larger than the search item, go down one level at current node and continue the search
- repeat the process until the search is found, then remove it and all of its connected bottomm node
- if reach the end of a level, starts at next lower level
- after removed the item, return the removed item
- decrement 1 to itemQty

## Contains
- starts at the top level
- if found the item, return true
- if the next item found is larger than the search item, go down one level at current node and continue the search
- repeat the process until the search is found, then return true
- if reach the end of a level, starts at next lower level
- after the search item is found, return true
- if the search item is not found, return false

## Questions
##
    Anything we need to add to the skiplist node? Upper level? Lower level?
    What is going to be returned by the remove function if the search item is not found?
    How to access the items in the vector?