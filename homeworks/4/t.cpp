#include <iostream>
#include <list>
#include <vector>

namespace mystd {

template <typename It>
It unique(It first, It last) {
    if (first == last) {
        return last;
    }
    It lastUnique = first++;
    while (first != last) {
        if (*first != *lastUnique) {
            *(++lastUnique) = *first;
        }
        ++first;
    }
    return ++lastUnique;
}

}  // namespace::mystd

void testUnique() {
    std::list<int> sample = {1, 2, 2, 1, 3, 1, 1, 5};
    auto uniqueIt = mystd::unique(sample.begin(), sample.end());
    sample.erase(uniqueIt, sample.end());
    for (auto value : sample) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

void solveProblem() {
    std::vector<int> values;
    int value;
    while (std::cin >> value) {
        values.push_back(value);
    }
    auto uniqueIt = mystd::unique(values.begin(), values.end());
    values.erase(uniqueIt, values.end());
    for (auto value : values) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

int main() {
    solveProblem();
    return 0;
}
