#include <iostream>
#include <vector>
#include <array>

using std::vector;
using std::cin;

using Permutation = vector<int>;

Permutation readPermutation(int n) {
    Permutation permutation(n);
    for (int i = 0; i < n; ++i) {
        cin >> permutation[i];
    }
    return permutation;
}

Permutation operator * (const Permutation& lhs, const Permutation& rhs) {
  Permutation result(lhs.size());
  for (size_t i = 0; i < lhs.size(); ++i) {
    result[i] = rhs[lhs[i] - 1];
  }
  return result;
}

int sign(const Permutation& p) {
  bool isPositive = true;
  for (size_t i = 0; i < p.size(); ++i) {
      for (size_t j = i + 1; j < p.size(); ++j) {
          if (p[i] > p[j]) {
              isPositive ^= 1;
          }
      }
  }
  return isPositive ? 1 : -1;
}

int main() {
    int n;
    cin >> n;
    std::array<vector<int>, 2> permutations;
    for (int i = 0; i < 2; ++i) {
        permutations[i] = readPermutation(n);
    }
    auto product = permutations[0] * permutations[1];
    std::cout << sign(product) << std::endl;
    return 0;
}
