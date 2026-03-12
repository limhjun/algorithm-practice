#include <bits/stdc++.h>

using namespace std;

int board[102][102];
int dist[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

queue<pair<int, int>> q;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < M; j++) {
      board[i][j] = int(s[j] - '0');
    }
  }

  q.emplace(0, 0);
  dist[0][0] = 1;
  while (!q.empty()) {
    auto cur = q.front(); q.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];
      if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
      if (dist[nx][ny] != 0 || board[nx][ny] != 1) continue;
      dist[nx][ny] = dist[cur.first][cur.second] + 1;
      q.emplace(nx, ny);
    }
  }

  cout << dist[N-1][M-1] << "\n";

  return 0;
}