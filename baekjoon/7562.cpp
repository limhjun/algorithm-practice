#include <bits/stdc++.h>

using namespace std;

int dist[301][301];
queue<pair<int, int>> que;
int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  while (T--) {
    int I;
    cin >> I;

    int x, y;
    cin >> x >> y;

    int p, q;
    cin >> p >> q;

    if (x == p && y == q) {
      cout << 0 << "\n";
      continue;
    }

    que.emplace(x, y);
    dist[x][y] = 0;
    while (!que.empty()) {
      auto cur = que.front(); que.pop();
      for (int dir = 0; dir < 8; dir++) {
        int nx = cur.first + dx[dir];
        int ny = cur.second + dy[dir];
        if (nx < 0 || nx >= I || ny < 0 || ny >= I) continue;
        if (dist[nx][ny] != 0) continue;
        dist[nx][ny] = dist[cur.first][cur.second] + 1;
        que.emplace(nx, ny);
        if (nx == p && ny == q) {
          cout << dist[nx][ny] << "\n";
          break;
        }
      }
    }

    for (int i = 0; i < 301; i++)
      fill(dist[i], dist[i] + 301, 0);
  }
  return 0;
}
