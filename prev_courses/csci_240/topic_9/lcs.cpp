#include <iostream>
#include <string>

size_t lcs(const std::string&, const std::string&, size_t, size_t);

int main(int argc, char const *argv[])
{
    std::string s{"ACTAGAT"};
    std::string t{"ATGACGT"};

    std::cout << lcs(s, t, s.size(), t.size()) << "\n";

    return 0;
}

size_t lcs(const std::string& S, const std::string& T, size_t s, size_t t) {
    if (s == 0 || t == 0)
        return 0;

    if (S[s - 1] == T[t - 1])
        return 1 + lcs(S, T, s - 1, t - 1);

    return std::max(lcs(S, T, s - 1, t), lcs(S, T, s, t - 1));
}