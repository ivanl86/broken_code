#ifndef VALUESTATE_PAIR_H
#define VALUESTATE_PAIR_H

enum S{EMPTY, AVAILABLE, OCCUPIED};

template<typename V>
struct VSPair
{
    V value;
    S state;

    VSPair() : state{EMPTY} {}

    bool operator<(const VSPair<V>& other) { return value < other.value; }
    bool operator>=(const VSPair<V>& other) { return !(*this < other); }

    bool operator>(const VSPair<V>& other) { return value > other.value; }
    bool operator<=(const VSPair<V>& other) { return !(*this > other); }

    bool operator==(const VSPair<V>& other) { return value == other.value; }
    bool operator!=(const VSPair<V>& other) { return !(*this == other); }

    bool operator<(const V& other) { return value < other; }
    bool operator>=(const V& other) { return !(*this < other); }

    bool operator>(const V& other) { return value > other; }
    bool operator<=(const V& other) { return !(*this > other); }

    bool operator==(const V& other) { return value == other; }
    bool operator!=(const V& other) { return !(*this == other); }
};

#endif  /* KEYVALUE_PAIR_H */