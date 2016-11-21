#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v(10, 42);

    for (const auto& x : v) {
        cout << x << endl;
    }
    return 0;
}
