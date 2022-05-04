#include <iostream>
#include <vector>
#define MAX 1001

using namespace std;

vector<int> v[MAX];
bool visited[MAX];

int n, m;
int res = 0;

void dfs(int idx) {
    for (int i = 0; i < v[idx].size(); i++) {
        int next_idx = v[idx][i];
        if (!visited[next_idx]) {
            visited[next_idx] = true;
            res++;
            dfs(next_idx);
        }
    }
    return;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y;

        cin >> x >> y;

        v[x].push_back(y);
        v[y].push_back(x);
    }
    // 1은 방문처리 한다.
    visited[1] = true;
    dfs(1);

    cout << res << "\n";

    return 0;
}