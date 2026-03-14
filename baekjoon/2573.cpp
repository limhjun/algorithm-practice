#include <bits/stdc++.h>

using namespace std;

int board[301][301];
bool vis[301][301];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

struct Melt {
  int x;
  int y;
  int amount;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;
  cin >> N >> M; // 3 <= N, M <= 300

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];
    }
  }

  int year = 0;
  while (true) {
    queue<pair<int, int>> q;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (board[i][j] > 0 && !vis[i][j]) {
          q.emplace(i, j);
          cnt++;
          if (cnt == 2) {
            cout << year << "\n";
            return 0;
          }
          vis[i][j] = true;
          while (!q.empty()) {
            auto cur = q.front(); q.pop();
            for (int dir = 0; dir < 4; dir++) {
              int nx = cur.first + dx[dir];
              int ny = cur.second + dy[dir];
              if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
              if (vis[nx][ny] || board[nx][ny] == 0) continue;
              q.emplace(nx, ny);
              vis[nx][ny] = true;
            }
          }
        }
      }
    }

    queue<Melt> qe;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (board[i][j] > 0) {
          int amount = 0;
          for (int dir = 0; dir < 4; dir++) {
            int nx = i + dx[dir];
            int ny = j + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (board[nx][ny] == 0) amount++;
          }
          qe.push({i, j, amount});
        }
      }
    }
    while (!qe.empty()) {
      auto cur = qe.front(); qe.pop();
      board[cur.x][cur.y] -= cur.amount;
      if (board[cur.x][cur.y] < 0) board[cur.x][cur.y] = 0;
    }

    for (int i = 0; i < 301; i++) fill(vis[i], vis[i] + 301, false);

    if (cnt == 0) {
      cout << 0 << "\n";
      break;
    }

    year++;
  }

  return 0;
}
