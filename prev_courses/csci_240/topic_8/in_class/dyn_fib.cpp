#include <iostream>

uint64_t fib(int n);
uint64_t fib_dyn(int n, uint64_t mem[]);
uint64_t fib_dyn_2(int n, uint64_t mem[]);

int main(int argc, char const *argv[])
{
    const int n{50};

    {
        uint64_t mem[n + 1] {};
        std::cout << fib_dyn(n, mem) << "\n";
    }

    {
        uint64_t mem[n + 1] {0, 1};
        std::cout << fib_dyn_2(n, mem) << "\n";
    }

    return 0;
}

uint64_t fib(int n) {
    if (n <= 1)
        return n;

    return fib(n - 1) + fib(n - 2);
}

uint64_t fib_dyn(int n, uint64_t mem[]) {
    if (n <= 1)
        return n;

    if (mem[n] == 0)
        mem[n] = fib_dyn(n - 1, mem) + fib_dyn(n - 2, mem);

    return mem[n];
}

uint64_t fib_dyn_2(int n, uint64_t mem[]) {
    static int i{2};

    if (i >= n)
        return n;

    // mem[i] = mem[i - 1] + mem[i - 2];
    mem[i] = fib_dyn_2(n - 1, mem) + fib_dyn_2(n - 2, mem);
    ++i;

    return mem[n];
}