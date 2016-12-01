#include <iostream>
#include <vector>

using std::vector;

template <typename InIter, typename OutIter, typename Predicate, typename Action>
OutIter transform_if(
  InIter first,
  InIter last,
  OutIter out,
  Predicate condition,
  Action f) {
  while (first != last) {
    if (condition(*first)) {
      *out = f(*first);
      ++out;
    }
    ++first;
  }
  return out;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> v[i];
  }
  vector<int> test(n);
  transform_if(v.begin(), v.end(), test.begin(),
               [] (int x) { return x % 2 == 1; },
               [] (int x) { return x * x; });
  for (int x : test) {
    std::cout << x << " ";
  }
  std::cout << std::endl;
  return 0;
}
