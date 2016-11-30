#include <iostream>
#include <set>

using namespace std;


int main() {
    std::set<int> a{1, 2, 3};
    auto first = a.begin();
    std::set<int>::iterator second = a.end();

    cout << "Distance: " << std::distance(first, second) << endl;

    cout << "Reversed: ";
    for (auto it = a.rbegin(); it != a.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}


