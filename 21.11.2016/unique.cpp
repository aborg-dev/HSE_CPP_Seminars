#include <iostream>
#include <vector>

using namespace std;

int MAXD = 10000000;

int main() {
    vector<bool> seen(MAXD, false);
    int x;
    while (cin >> x) {
        x += MAXD / 2;
        if (!seen[x]) {
            seen[x] = true;
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}

