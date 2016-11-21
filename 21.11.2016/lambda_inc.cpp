#include <iostream>

using namespace std;

int main() {
    int x = 0;
    auto incAndPrint = [&] () {
        ++x;
        cout << x << endl;
    };
    incAndPrint();
    incAndPrint();
    incAndPrint();
}
