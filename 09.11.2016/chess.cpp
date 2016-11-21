#include <iostream>

int main() {
    int x1, y1, x2, y2;
    std::cin >> x1 >> y1;
    std::cin >> x2 >> y2;
    int d = std::max(abs(x1 - x2), abs(y1 - y2));
    if (d == 1) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
    return 0;
}
