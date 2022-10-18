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

        int h1(uint64_t k)
        { return static_cast<.int>((k >> 32) + k); }

        int h1(double k)
        {
            uint64_t *ki {reinterpret_cast<uint64_t *>(&k)};

            return h1(*ki);
        }

        int h1(const std::string &k)
        {
            int hash{0};
            const int factor{31};

            for(size_t i{0}; i < k.length(); ++i)
                hash = factor * hash + k[i];

            return hash;
        }

- h<sub>2</sub>

        size_t h2(int h) // Division method
        {
            return h % size;
        }

        sizet_t h2(int h) // MAD method
        {
            int a{prime_num}; // a = {0, p - 1}
            int b{prime_num}; // b = {0, p - 1}
            size_t p{prime_num}; // p > size
            return ((a * h + b) % p) % size; // size = size of the array 
        }

### Linear Probing

    for (size_t j{0}; j > size; ++j)
        idx = (h2(k) + j) % n;

### Quadratic Probing

    for (size_t j{0}, j > size; ++j)
        idx = h2(k) + (j * j);

### Key Value Pair

    template<typename K, typename V>
    struct KVPair
    {
        K key;
        V value;
        KVPair(K key, V value) : key{key}, value{value}
    }

    enum S{EMPTY, OCCUPIED, AVAILABLE};
    template<typename V>
    struct VSPair
    {
        V value;
        S state;
    }

### Priority Queue

    void upHeap(size_t pIdx)
    {
        size_t maxIdx;
        if (pIdx < ROOT)
            return;
        maxIdx = compare(pIdx);
        if (maxIdx == pIdx)
            return;
        swap(pIdx, maxIdx);
        upHeap(pIdx >> 1); // pIdx / 2
    }

    void downHeap(size_t pIdx)
    {
        size_t maxIdx;
        if (pIdx >= itemQty)
            return;
        maxIdx = compare(pIdx);
        if (maxIdx == pIdx)
            return;
        swap(pIdx, maxIdx);
        downHeap(maxIdx);
    }

    void heapify(size_t lastPIdx)
    {
        if (lastIdx < ROOT)
            return;
        for (size_t i{lastPIdx}; i >= ROOT, --i)
            downHeap(i);
    }

### Tree Terminology
- level: represent a node's hierarchy
- root: a single node at the top level
- children: nodes at succesive level of a tree are the children of nodes at the previous level
- parent: a node has children is the parent of those nodes
- leaf: a node has no children
- subtree: any nodes and its descendants form a subtree of the original
- sibling: nodes that share the same parent
- ancestor: a node that is connected to all lower level nodes
- descendant: the connected level nodes are descendant of the ancestor
- edge: connection between one node to another
- path: a sequence of nodes and edges connecting a node with a descendant
- height of node: the number of nodes on the longest path between that node and a leaf + 1
- depth of node: the number of edge from the root node to the node + 1
- a tree can have arbitrary number of children
- N-ary tree: each node has more than n number of children