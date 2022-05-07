#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

int main() {
    vector<pair<int, int> > points = {
        {1, 7}, {3, 2}, {3, 1}, {6, 2}
    };
    int n = 4;

    priority_queue<tuple<int, int, int> > pq;
    for (int i = 0; i < n; i++) {
        int x = points[i].first, y = points[i].second;
        pq.push(make_tuple(x * y, x, y));           // priority_queue�� �־��ݴϴ�.
        tuple<int, int, int> best_thing = pq.top(); // x * y, x, y ������ ���� �켱���� ���� ��츦 ã���ݴϴ�.

        int px, py;
        tie(ignore, px, py) = best_thing;  // �츮�� ���ϴ� x, y ���� tuple�κ��� �������ݴϴ�.
        cout << px << " " << py << endl;
    }
    return 0;
}