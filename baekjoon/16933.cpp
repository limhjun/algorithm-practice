#include <bits/stdc++.h>

using namespace std;

struct State {
  int x, y;
  int dist;
  int remain; // 벽 깨뜨림 남은 횟수
  bool day; // true가 낮, false가 밤
};
int board[1002][1002];
bool visited[1002][1002][11][2]; // [x][y][K][day]
queue<State> q;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M, K; // N(1 ≤ N ≤ 1,000), M(1 ≤ M ≤ 1,000), K(1 ≤ K ≤ 10)
  cin >> N >> M >> K;

  for (int i = 1; i <= N; i++) {
    string s;
    cin >> s;
    for (int j = 1; j <= M; j++) {
      board[i][j] = s[j - 1] - '0';
    }
  }

  q.push({1, 1, 1, K, true});
  visited[1][1][K][true] = true;
  while (!q.empty()) {
    auto cur = q.front(); q.pop();

    if (cur.x == N && cur.y == M) {
      cout << cur.dist << "\n";
      return 0;
    }

    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.x + dx[dir];
      int ny = cur.y + dy[dir];

      if (nx < 1 || nx > N || ny < 1 || ny > M) continue;
      if (cur.remain == 0 && board[nx][ny] == 1) continue;
      if (cur.day && cur.remain > 0 && board[nx][ny] == 1) {
        if (!visited[nx][ny][cur.remain - 1][!cur.day]) {
          visited[nx][ny][cur.remain - 1][!cur.day] = true;
          q.push({nx, ny, cur.dist + 1, cur.remain - 1, !cur.day});
        }
      } else if (!cur.day && cur.remain > 0 && board[nx][ny] == 1) {
        if (!visited[cur.x][cur.y][cur.remain][!cur.day]) {
          visited[cur.x][cur.y][cur.remain][!cur.day] = true;
          q.push({cur.x, cur.y, cur.dist + 1, cur.remain, !cur.day});
        }
      } else if (board[nx][ny] == 0) {
        if (!visited[nx][ny][cur.remain][!cur.day]) {
          visited[nx][ny][cur.remain][!cur.day] = true;
          q.push({nx, ny, cur.dist + 1, cur.remain, !cur.day});
        }
      }
    }
  }

  cout << -1 << "\n";

  return 0;
}
