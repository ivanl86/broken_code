#include <string>

struct Node
{
    Node* nexts[26];
};

void Constructor() {
    root = nullptr;
}

bool insert(const std::string& str) {
    insert(str, 0u, root);
}

bool erase(const std::string& str) {}

bool contains(const std::string& str) {}

bool erase(const std::string& str, Node* ptr, uint64_t idx) {}

bool isLeaf(const Node* node) {
    for (const Node* n : node->nexts)
        if (n != nullptr)
            return false;

    return true;
}

bool insert(const std::string& str, uint64_t idx, Node* ptr) {}

Node* root;