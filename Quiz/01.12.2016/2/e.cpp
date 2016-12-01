#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <deque>

using std::vector;
using std::deque;
using std::string;
using std::cin;
using std::cout;
using std::endl;

using FrequencyPair = std::pair<string, int>;
using FrequencyMap = std::unordered_map<string, int>;

bool operator < (const FrequencyPair& lhs, const FrequencyPair& rhs) {
  if (lhs.second == rhs.second) {
    return lhs.first < rhs.first;
  }
  return lhs.second > rhs.second;
}

void printFrequencies(const FrequencyMap& frequency) {
  vector<FrequencyPair> frequencyArray(frequency.begin(), frequency.end());
  std::sort(frequencyArray.begin(), frequencyArray.end());
  for (const auto& p : frequencyArray) {
    cout << p.second << " - " << p.first << endl;
  }
}

template <typename It>
string join(It first, It last) {
  string joined;
  while (first != last) {
    joined += *first;
    joined += " ";
    ++first;
  }
  if (!joined.empty()) {
    joined.pop_back();
  }
  return joined;
}

int main() {
  size_t m, n;
  cin >> m >> n;
  deque<string> window;
  FrequencyMap frequency;
  for (size_t i = 0; i < m; ++i) {
    string word;
    cin >> word;
    window.push_back(word);
    if (window.size() > n) {
      window.pop_front();
    }
    if (window.size() == n) {
      auto ngram = join(window.begin(), window.end());
      ++frequency[ngram];
    }
  }
  printFrequencies(frequency);
  return 0;
}
