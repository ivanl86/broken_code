#ifndef KEYVALUE_PAIR_H
#define KEYVALUE_PAIR_H

enum S{EMPTY, AVAILABLE, OCCUPIED};

template<typename K>
struct KVPair
{
    K key;
    S state;

    KVPair() : state{EMPTY} {}
    // KVPair(K key) : key{key} {}

    bool operator<(const KVPair<K>& other) { return key < other.key; }
    bool operator>=(const KVPair<K>& other) { return !(*this < other); }

    bool operator>(const KVPair<K>& other) { return key > other.key; }
    bool operator<=(const KVPair<K>& other) { return !(*this > other); }

    bool operator==(const KVPair<K>& other) { return key == other.key; }
    bool operator!=(const KVPair<K>& other) { return !(*this == other); }
};

#endif  /* KEYVALUE_PAIR_H */