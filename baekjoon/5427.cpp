#include <bits/stdc++.h>

using namespace std;

char board[1001][1001];
bool sang_visited[1001][1001];
bool fire_visited[1001][1001];
int sang_dist[1001][1001];
int fire_dist[1001][1001];
queue<pair<int, int>> sang_queue;
queue<pair<int, int>> fire_queue;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 0; i < 1001; i++) {
    fill(sang_dist[i], sang_dist[i] + 1001, -1);
    fill(fire_dist[i], fire_dist[i] + 1001, -1);
  }

  int T;
  cin >> T;

  while (T--) {
    int w, h; // 1<=w,h<=1000
    cin >> w >> h;

    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        cin >> board[i][j];
        if (board[i][j] == '@') {
          board[i][j] = '.';
          sang_dist[i][j] = 0;
          sang_queue.push({i, j});
          sang_visited[i][j] = true;
        }
        if (board[i][j] == '*') {
          fire_dist[i][j] = 0;
          fire_queue.push({i, j});
          fire_visited[i][j] = true;
        }
      }
    }

    while (!fire_queue.empty()) {
      auto cur = fire_queue.front(); fire_queue.pop();
      for (int dir = 0; dir < 4; dir++) {
        int nx = cur.first + dx[dir];
        int ny = cur.second + dy[dir];
        if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
        if (fire_visited[nx][ny] || board[nx][ny] != '.') continue;
        fire_queue.push({nx, ny});
        fire_visited[nx][ny] = true;
        fire_dist[nx][ny] = fire_dist[cur.first][cur.second] + 1;
      }
    }

    bool is_finish = false;
    while (!sang_queue.empty()) {
      auto cur = sang_queue.front(); sang_queue.pop();
      for (int dir = 0; dir < 4; dir++) {
        int nx = cur.first + dx[dir];
        int ny = cur.second + dy[dir];
        if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
          is_finish = true;
          cout << sang_dist[cur.first][cur.second] + 1 << "\n";
          break;
        }
        if (sang_visited[nx][ny] || board[nx][ny] != '.') continue;
        int next_time = sang_dist[cur.first][cur.second] + 1;
        if (fire_dist[nx][ny] != -1 && fire_dist[nx][ny] <= next_time) continue;
        sang_queue.push({nx, ny});
        sang_visited[nx][ny] = true;
        sang_dist[nx][ny] = sang_dist[cur.first][cur.second] + 1;
      }
      if (is_finish) break;
    }

    if (!is_finish) cout << "IMPOSSIBLE" << "\n";

    for (int i = 0; i < h; i++) {
      fill(sang_visited[i], sang_visited[i] + 1001, false);
      fill(fire_visited[i], fire_visited[i] + 1001, false);
      fill(sang_dist[i], sang_dist[i] + 1001, -1);
      fill(fire_dist[i], fire_dist[i] + 1001, -1);
    }
    while (!sang_queue.empty()) sang_queue.pop();
    while (!fire_queue.empty()) fire_queue.pop();
  }

  return 0;
}
