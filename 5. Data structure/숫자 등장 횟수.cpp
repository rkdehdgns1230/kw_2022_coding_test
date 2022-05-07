#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, int> map;
int n, m;

int main() {
    int i, j;
    cin >> n >> m;

    for (i = 0; i < n; i++) {
        int num;
        cin >> num;

        if (map.find(num) == map.end()) {
            map[num] = 1;
        }
        else {
            int cnt = map[num];
            cnt += 1;
            map[num] = cnt;
        }
    }

    for (i = 0; i < m; i++) {
        int ques;
        cin >> ques;
        cout << map[ques] << " ";
    }
    cout << endl;
    return 0;
}