#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> generate(int n) {
    vector<int> v(n);
    iota(v.begin(), v.end(), 0);
    return v;
}

void generateInplace(int n, vector<int>& v) {
    v.resize(n);
    iota(v.begin(), v.end(), 0);
}

int main()
{
    auto v = generate(5);
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
