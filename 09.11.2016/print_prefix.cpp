#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>

using namespace std;

void printPrefix(const string& s, size_t len = string::npos, int dummy = 42) {
    cerr << "Dummy: " << dummy << endl;

    for (size_t i = 0; i < s.size() && i < len; ++i) {
        cout << s[i];
    }
    cout << endl;
}

int main()
{
    printPrefix("Hello world", 5);
    printPrefix("Hello world", 5);
    printPrefix("Hello world", 5, 100);
    return 0;
}
