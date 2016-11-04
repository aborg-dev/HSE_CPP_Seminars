#include <iostream>
#include <array>

using namespace std;

const int MAX_LINE_LEN = 100;

int main()
{
    string name;
    int count = 0;
    while (getline(cin, name)) {
        cout << name << endl;
        ++count;
    }
    cout << count << endl;
    return 0;
}
