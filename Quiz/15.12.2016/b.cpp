#include <iostream>
#include <deque>

using namespace std;

template <typename T, typename Container = std::deque<T>>
class Queue {
 public:
    Queue() {}

    const T& front() const {
        return underlying.front();
    }

    T& front() {
        return underlying.front();
    }

    void pop() {
        underlying.pop_front();
    }

    void push(const T& t) {
        underlying.push_back(t);
    }

    size_t size() const {
        return underlying.size();
    }

    bool empty() const {
        return underlying.empty();
    }

    friend bool operator == (const Queue& lhs, const Queue& rhs) {
        return lhs.underlying == rhs.underlying;
    }

    friend bool operator != (const Queue& lhs, const Queue& rhs) {
        return !(lhs == rhs);
    }

 private:
    Container underlying;
};

/*
int main() {
    Queue<int> q;
    q.push(3);
    cout << q.front() << endl;
    q.push(4);
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    cout << q.size() << endl;
    return 0;
}
*/
