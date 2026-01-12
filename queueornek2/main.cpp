#include <iostream>
#include <queue>
using namespace std;
#include <stack>

void reverseQueue(std::queue<int>& q) {
    std::stack<int> s;
    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}


int main() {
    std::queue<int> q;
    q.push(5);
    q.push(10);
    q.push(15);
    q.push(20);
    q.push(25);

    std::cout << "orjinal kuyruk: ";
    std::queue<int> temp=q;
    while (!temp.empty()) {
        std::cout << temp.front() << " ";
        temp.pop();
    }
    std::cout << std::endl;

    reverseQueue(q);
    std::cout << "Tersine cevrilmis kuyruk: ";
    while (!q.empty()) {
        std::cout << q.front() << " ";
        q.pop();
    }


    return 0;
}