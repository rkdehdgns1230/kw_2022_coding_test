/*
    ���� ������ �ٸ� ���� 
    1. ���� ���� ������ ���ÿ� �����δٴ� ��
    2. ������ �ε����� �����ٴ� ��
    3. �׷��⿡ ������ ��ġ�� ����ϴ� ���ο� �迭���� �ʿ��ϴٴ� ���̴�.
*/
#include <iostream>
#define MAX 21

using namespace std;

int arr[MAX][MAX];
int count[MAX][MAX];
int next_count[MAX][MAX];

int n, m, t;

bool inRange(int x, int y) {
    if (0 > x || x >= n || 0 > y || y >= n) return false;
    else return true;
}

pair<int, int> GetNextPos(int x, int y) {
    int dx[4] = { -1, 1, 0, 0 };
    int dy[4] = { 0, 0, -1, 1 };
    // move to maximum adjacent element
    int max = 0;
    pair<int, int> maxPos = { x, y };

    int idx = 0;
    bool changed = false;

    for (int i = 0; i < 4; i++) {
        int next_x = x + dx[i];
        int next_y = y + dy[i];

        if (inRange(next_x, next_y) && max < arr[next_x][next_y]) {
            max = arr[next_x][next_y];
            changed = true;
            idx = i;
        }
    }

    if (changed) {
        x = x + dx[idx];
        y = y + dy[idx];
        maxPos.first = x, maxPos.second = y;

        return maxPos;
    }
    // didn't move. because current position is biggest one compared with adjacent elements
    return maxPos;
}

void Move(int x, int y) {
    pair<int, int> next_pos = GetNextPos(x, y);
    int next_x = next_pos.first, next_y = next_pos.second;

    next_count[next_x][next_y]++;
}

void MoveAll() {
    // �� ��ġ������ ������ ������ ��� �ʱ�ȭ
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            next_count[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // move (i, j)
            if (count[i][j] == 1)
                Move(i, j);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            count[i][j] = next_count[i][j];
        }
    }
}

void RemoveDuplicateMarbles() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (count[i][j] >= 2)
                count[i][j] = 0;
        }
    }
}

int main() {
    cin.tie(NULL);

    cin >> n >> m >> t;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        count[x - 1][y - 1]++;
    }

    while (t--) {
        MoveAll();
        RemoveDuplicateMarbles();
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res += count[i][j];
        }
    }
    cout << res << "\n";
    return 0;
}