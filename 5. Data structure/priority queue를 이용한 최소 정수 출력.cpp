#include <iostream>
#include <queue>

using namespace std;

int main() {
    priority_queue<int> pq;
    int n;
    cin >> n;

    while (n--) {
        int x;
        cin >> x;

        if (x == 0 && !pq.empty()) {
            cout << -pq.top() << endl;
            pq.pop();
        }
        else if (x == 0 && pq.empty()) {
            cout << "0\n";
        }
        else {
            pq.push(-x);
        }
    }



    return 0;
}