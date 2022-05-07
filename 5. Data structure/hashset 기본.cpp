#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<int> set;

void add(int x) {
    set.insert(x);
    return;
}

void remove(int x) {
    set.erase(x);
    return;
}

void find(int x) {
    if (set.find(x) != set.end()) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        string str;
        cin >> str;

        if (str == "find") {
            int x;
            cin >> x;
            find(x);
        }
        else if (str == "add") {
            int x;
            cin >> x;
            add(x);
        }
        else {
            int x;
            cin >> x;
            remove(x);
        }
    }

    return 0;
}