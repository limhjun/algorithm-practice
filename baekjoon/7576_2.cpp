#include <bits/stdc++.h>

using namespace std;

int board[1001][1001];
int dist[1001][1001];
queue<pair<int, int>> q;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
#define X first
#define Y second

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int M, N;
  cin >> M >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];
      dist[i][j] = -1;
      if (board[i][j] == 1) {
        q.emplace(i, j);
        dist[i][j] = 0;
      }
    }
  }

  while (!q.empty()) {
    auto cur = q.front(); q.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
      if (dist[nx][ny] != -1 || board[nx][ny] != 0) continue;
      q.emplace(nx, ny);
      dist[nx][ny] = dist[cur.X][cur.Y] + 1;
    }
  }

  int max_day = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (dist[i][j] == -1 && board[i][j] == 0) {
        cout << -1 << "\n";
        return 0;
      }
      max_day = max(max_day, dist[i][j]);
    }
  }

  cout << max_day << "\n";

  return 0;
}