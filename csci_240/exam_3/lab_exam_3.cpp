#include <string>
#include <stdexcept>

struct Node
{
    Node* nexts[26];
    bool isTerminal;

    bool isLeaf() {
        for (const auto& n : nexts)
            if (n != nullptr)
                return false;

        return true;
    }
};

void Constructor() {
    root = new Node;
}

bool insert(const std::string& str) {
    if (str.empty())
        throw TrieError("Invalid argument");
    if (contains(str))
        return false;

    return insert(str, 0u, root);
}

bool erase(const std::string& str) {
    if (!contains(str))
        return false;
}

bool contains(const std::string& str) { // const
    if (str.empty())
        throw TrieError("Invalid argument");

    char idx;
    Node* ptr{root};

    for (const char c : str) {
        idx = c - 'a';

        if (ptr->nexts[idx] == nullptr)
            return false;

        ptr = ptr->nexts[idx];
    }
    return (ptr->isTerminal);
}

bool erase(const std::string& str, Node* ptr, uint64_t idx) {
    if (str.empty())
        throw TrieError("Invalid argument");
}

bool isLeaf(const Node* node) {
    for (const Node* n : node->nexts)
        if (n != nullptr)
            return false;

    return true;
}

bool insert(const std::string& str, uint64_t cPos, Node* ptr) {
    char idx{str[cPos] - 'a'};

    if (ptr->nexts[idx] == nullptr)
        ptr->nexts[idx] = new Node;

    if (cPos <= str.size() - 1) {
        ptr->nexts[idx]->isTerminal = true;
        return true;
    }
    return insert(str, cPos + 1, ptr->nexts[idx]);
}

Node* root;

struct TrieError : public std::runtime_error
{
    TrieError() : std::runtime_error("Error in Trie") {}
    TrieError(const char* msg) : std::runtime_error(msg) {}
};

// mark no except if func does not throw exceptions