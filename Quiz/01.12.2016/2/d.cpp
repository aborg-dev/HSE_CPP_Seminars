#include <iostream>
#include <deque>

using std::deque;
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
  int n;
  cin >> n;
  cin.ignore(1, '\n');
  deque<string> names;
  for (int i = 0; i < n; ++i) {
    string line;
    getline(cin, line);
    int spacePosition = line.find(" ");
    auto name = line.substr(0, spacePosition);
    auto side = line.substr(spacePosition + 1);
    if (side == "top") {
      names.push_front(name);
    } else {
      names.push_back(name);
    }
  }
  int m;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    int position;
    cin >> position;
    --position;
    cout << names[position] << endl;
  }
  return 0;
}
