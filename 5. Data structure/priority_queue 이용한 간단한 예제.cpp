#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, m;
    priority_queue<int> pq;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        pq.push(num);
    }

    while (m--) {
        int tmp = pq.top();
        pq.pop();
        tmp -= 1;

        pq.push(tmp);
    }

    cout << pq.top() << endl;

    return 0;
}