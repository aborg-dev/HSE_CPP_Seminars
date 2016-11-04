#include <iostream>
#include <array>

using namespace std;

const int MAX_LINE_LEN = 100;

int main()
{
    while (true) {
        string key;
        string value;
        getline(cin, key, ':');
        if (!getline(cin, value)) {
            break;
        }

        if (value.back() == ',') {
            value.pop_back();
        }

        cout << "(" << key << ", " << value << ")\n";
    }
    return 0;
}
