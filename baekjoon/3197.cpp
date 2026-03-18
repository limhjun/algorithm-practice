#include <bits/stdc++.h>

using namespace std;

char board[1501][1501];
bool swan_visited[1501][1501];
queue<pair<int, int>> current_swan_q;
queue<pair<int, int>> tomorrow_swan_q;
queue<pair<int, int>> current_water_q;
queue<pair<int, int>> tomorrow_water_q;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int R, C;

bool CanSwanMeetToday() {
  while (!current_swan_q.empty()) {
    auto cur = current_swan_q.front();
    current_swan_q.pop();

    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];

      if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
      if (swan_visited[nx][ny]) continue;

      swan_visited[nx][ny] = true;
      if (board[nx][ny] == 'X') {
        tomorrow_swan_q.push({nx, ny});
      } else if (board[nx][ny] == 'L') {
        return true;
      } else {
        current_swan_q.push({nx, ny});
      }
    }
  }
  return false;
}

void MeltIce() {
  while (!current_water_q.empty()) {
    auto cur = current_water_q.front();
    current_water_q.pop();

    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];

      if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
      if (board[nx][ny] != 'X') continue;

      board[nx][ny] = '.';
      tomorrow_water_q.push({nx, ny});
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> R >> C; // 1 <= R, C <= 1500

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> board[i][j];
      if (board[i][j] == 'L') {
        current_water_q.push({i,  j});

        if (current_swan_q.empty()) {
          current_swan_q.push({i, j});
          swan_visited[i][j] = true;
        }
      } else if (board[i][j] == '.') {
        current_water_q.push({i, j});
      }
    }
  }

  int day = 0;
  while (true) {
    if (CanSwanMeetToday()) break;
    MeltIce();

    current_swan_q = move(tomorrow_swan_q);
    current_water_q = move(tomorrow_water_q);

    tomorrow_swan_q = queue<pair<int, int>>();
    tomorrow_water_q = queue<pair<int, int>>();

    day++;
  }

  cout << day << "\n";

  return 0;
}
