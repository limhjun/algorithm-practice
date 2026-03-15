#include <bits/stdc++.h>

using namespace std;

int board[101][101];
bool visited[101][101];
int dist[101][101];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int ans = INT_MAX;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
    }
  }

  int no = 0; // 섬의 번호
  queue<pair<int, int> > q;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (board[i][j] == 1 && !visited[i][j]) {
        no++;
        q.push({i, j});
        visited[i][j] = true;
        board[i][j] = no;

        while (!q.empty()) {
          auto cur = q.front();
          q.pop();
          for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (visited[nx][ny] || board[nx][ny] != 1) continue;
            q.push({nx, ny});
            visited[nx][ny] = true;
            board[nx][ny] = no;
          }
        }
      }
    }
  }

  for (int n = 1; n <= no; n++) {
    for (int i = 0; i < N; i++) {
      fill(visited[i], visited[i] + 101, false);
      fill(dist[i], dist[i] + 101, -1);
    }

    queue<pair<int, int> > qe;

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (board[i][j] == n) {
          q.push({i, j});
          visited[i][j] = true;
          dist[i][j] = 0;
        }
      }
    }

    while (!q.empty()) {
      auto cur = q.front();
      q.pop();
      for (int dir = 0; dir < 4; dir++) {
        int nx = cur.first + dx[dir];
        int ny = cur.second + dy[dir];
        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
        if (visited[nx][ny] || board[nx][ny] == n) continue;
        if (board[nx][ny] == 0) {
          q.push({nx, ny});
          visited[nx][ny] = true;
          dist[nx][ny] = dist[cur.first][cur.second] + 1;
        } else {
          ans = min(ans, dist[cur.first][cur.second]);
        }
      }
    }
  }

  cout << ans;

  return 0;
}
