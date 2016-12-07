#include <iostream>
#include <string>
#include <bitset>
#include <cstdint>

using namespace std;

int main() {
    string input;
    cin >> input;
    for (char c : input) {
        cout << bitset<8>(c) << " ";
    }
    cout << endl;
    return 0;
}


