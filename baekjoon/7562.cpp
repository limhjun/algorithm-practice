#include <bits/stdc++.h>

using namespace std;

int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
bool visited[301][301];
int dist[301][301];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  while (T--) {
    int I, x, y, p, q;
    cin >> I >> x >> y >> p >> q;

    queue<pair<int, int> > qe;

    qe.emplace(x, y);
    visited[x][y] = true;

    while (!qe.empty()) {
      auto cur = qe.front(); qe.pop();
      if (cur.first == p && cur.second == q) {
        cout << dist[cur.first][cur.second] << "\n";
        break;
      }
      for (int dir = 0; dir < 8; dir++) {
        int nx = cur.first + dx[dir];
        int ny = cur.second + dy[dir];
        if (nx < 0 || nx >= I || ny < 0 || ny >= I) continue;
        if (visited[nx][ny]) continue;
        visited[nx][ny] = true;
        dist[nx][ny] = dist[cur.first][cur.second] + 1;
        qe.emplace(nx, ny);
      }
    }

    for (int i = 0; i < I; i++) {
      fill(visited[i], visited[i] + I, false);
      fill(dist[i], dist[i] + I, 0);
    }
  }

  return 0;
}
