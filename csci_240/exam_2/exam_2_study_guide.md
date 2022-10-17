# Exam 2 Studey Guide
## Skip List
### Insert

- for item, the element to be inserted, search the list to find where the item fits.
    - this will be the node with the greatest item less than or equal to the item being inserted
    - always insert the element into the bottom level (L0)
- with a probability of 0.5, insert the item into level 1 (L1) of the list
    - this is called promotion
- if inserted into L1, then with a 0.5 probability, insert into L2
- follow this procedure until the item is not inserted into a level or there are no more levels to insert into
### Hash Table
- h<sub>1</sub>

int h1(int k)
{ return k; }