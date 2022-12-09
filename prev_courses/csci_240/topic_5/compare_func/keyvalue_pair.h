#ifndef KEYVALUE_PAIR_H
#define KEYVALUE_PAIR_H

template<typename K, typename V>
struct KVPair
{
    K key;
    V value;

    KVPair(K key, V value) : key{key}, value{value} {}

    bool operator<(const KVPair<K, V>& other) { return key < other.key; }
    bool operator>=(const KVPair<K, V>& other) { return !(*this < other); }

    bool operator>(const KVPair<K, V>& other) { return key > other.key; }
    bool operator<=(const KVPair<K, V>& other) { return !(*this > other); }

    bool operator==(const KVPair<K, V>& other) { return key == other.key; }
    bool operator!=(const KVPair<K, V>& other) { return !(*this == other); }
};

#endif  /* KEYVALUE_PAIR_H */