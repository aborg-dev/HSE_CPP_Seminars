#include <iostream>
#include <stack>
#include <map>

using namespace std;

template<typename T>
class SetWrapper
{
public:
    using value_type = T;
    using reference = T&;
    using const_reference = const T&;
    using size_type = size_t;

    void push_back(const T& t) {
        int key = underlying.size() + 1;
        underlying.emplace(key, t);
    }

    void pop_back() {
        auto it = underlying.end();
        --it;
        underlying.erase(it);
    }

    bool empty() const {
        return underlying.empty();
    }

    T& back() {
        auto it = underlying.end();
        --it;
        return it->second;
    }

    const T& back() const {
        auto it = underlying.end();
        --it;
        return it->second;
    }

private:
    std::map<int, T> underlying;

};

int main() {
    stack<int, SetWrapper<int>> S;
    S.push(3);
    cout << S.top() << endl;
    return 0;
}
