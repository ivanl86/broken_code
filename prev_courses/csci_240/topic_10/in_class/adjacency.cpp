#define T true
#define F false

template<typename I>
struct Node
{
    I item;
    Node<T>* next;

    Node(I item) : item{item}, next{nullptr};
};

int main(int argc, char const *argv[])
{
    bool adjMatrix [][9] {
    //  A  B  C  D  E  F  G  H  I
        F, T, F, T, T, F, F, F, F, // A
        F, F, F, F, T, F, F, F, F, // B
        F, T, F, F, F, F, F, F, F, // C
        F, F, F, F, F, F, T, F, F, // D
        F, F, F, F, F, T, F, T, F, // E
        F, F, T, F, F, F, F, T, F, // F
        F, F, F, F, F, F, F, T, F, // G
        F, F, F, F, F, F, F, F, T, // H
        F, F, F, F, F, T, F, F, F, // I
    };
    return 0;
}
