#include <bits/stdc++.h>

using namespace std;

int board[52][52];
bool visited[52][52];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
queue<pair<int, int>> q;
int M, N, K;

void bfs(int x, int y) {
  visited[x][y] = true;
  q.emplace(x, y);
  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];
      if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;;
      if (board[nx][ny] == 0 || visited[nx][ny]) continue;
      visited[nx][ny] = true;
      q.emplace(nx, ny);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  while (T--) {
    cin >> M >> N >> K;

    while (K--) {
      int X, Y;
      cin >> X >> Y;
      board[Y][X] = 1;
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (board[i][j] == 1 && !visited[i][j]) {
          bfs(i, j);
          cnt++;
        }
      }
    }

    cout << cnt << "\n";

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        board[i][j] = 0;
        visited[i][j] = false;
      }
    }

  }
  return 0;
}
