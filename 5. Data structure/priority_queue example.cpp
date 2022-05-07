#include <iostream>
#include <queue>

using namespace std;

int main() {
    priority_queue<int> pq;

    int n;

    cin >> n;


    while (n--) {
        string str;
        cin >> str;

        if (str == "push") {
            int num;
            cin >> num;
            pq.push(num);
        }
        else if (str == "pop") {
            cout << pq.top() << endl;
            pq.pop();
        }
        else if (str == "size") {
            cout << pq.size() << endl;
        }
        else if (str == "empty") {
            if (pq.empty()) {
                cout << "1\n";
            }
            else {
                cout << "0\n";
            }
        }
        else {
            cout << pq.top() << endl;
        }
    }

    return 0;
}