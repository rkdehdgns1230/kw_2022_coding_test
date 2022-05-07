#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<int, int> m;

void add(int k, int v) {
    m[k] = v;
    return;
}

void remove(int k) {
    m.erase(k);
}

void find(int k) {
    if (m.find(k) != m.end()) {
        cout << m[k] << endl;
    }
    else {
        cout << "None\n";
        return;
    }
}

int main() {
    int n;

    cin >> n;

    while (n--) {
        string cmd;
        cin >> cmd;


        if (cmd == "add") {
            int k, v;
            cin >> k >> v;

            add(k, v);
        }
        else if (cmd == "remove") {
            int k;
            cin >> k;
            remove(k);
        }
        else {
            int k;
            cin >> k;
            find(k);
        }
    }



    return 0;
}