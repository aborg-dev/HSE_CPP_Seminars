#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    unordered_set<int> seen;
    int x;
    while (cin >> x) {
        if (seen.find(x) == seen.end()) {
            seen.insert(x);
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}
