#include <bits/stdc++.h>
using namespace std;

int board[1001][1001];
int dist[1001][1001];
queue<pair<int, int>> q;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m; // 2 <= n,m <= 1000
  cin >> n >> m;

  for (int i = 0; i < n; i++) fill(dist[i], dist[i] + m, -1);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> board[i][j];
      if (board[i][j] == 2) {
        q.push({i, j});
        dist[i][j] = 0;
      }
    }
  }

  while (!q.empty()) {
    auto cur = q.front(); q.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (board[nx][ny] == 0) continue;
      if (dist[nx][ny] != -1) continue;
      dist[nx][ny] = dist[cur.first][cur.second] + 1;
      q.push({nx, ny});
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (board[i][j] == 0) cout << 0 << " ";
      else cout << dist[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}
