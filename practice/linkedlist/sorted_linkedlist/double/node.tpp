template <typename T>
Node<T>::Node(T item)
    : Node<T>(item, nullptr, nullptr) {}

template <typename T>
Node<T>::Node(T item, Node<T>* prev, Node<T>* next)
    : item{item}, prev{prev}, next{next} {}