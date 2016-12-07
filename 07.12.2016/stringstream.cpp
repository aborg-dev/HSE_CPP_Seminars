#include <sstream>
#include <iostream>

using namespace std;

int main() {
    string line;
    getline(cin, line);

    stringstream ss(line);
    int n;
    while (ss >> n) {
        cout << n << endl;
    }

    getline(cin, line);
    cout << line << endl;
}
