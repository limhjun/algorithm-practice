#include <bits/stdc++.h>

using namespace std;

int board[201][201];
bool visited[201][201][31];
int dist[201][201][31];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int hx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int hy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

struct Monkey {
  int x;
  int y;
  int horse_count;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int K;
  cin >> K; // 원숭이가 말처럼 움직일 수 있는 횟수

  int W, H;
  cin >> W >> H; // W: 렬, H: 행

  if (H == 1 && W == 1) {
    cout << 0 << "\n";
    return 0;
  }

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> board[i][j];
    }
  }

  queue<Monkey> qe;
  qe.push({0, 0, K});
  visited[0][0][K] = true;
  while (!qe.empty()) {
    auto cur = qe.front(); qe.pop();
    if (cur.horse_count > 0) {
      for (int dir = 0; dir < 8; dir++) {
        int nx = cur.x + hx[dir];
        int ny = cur.y + hy[dir];
        if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
        if (visited[nx][ny][cur.horse_count - 1] || board[nx][ny] == 1) continue;
        visited[nx][ny][cur.horse_count - 1] = true;
        qe.push({nx, ny, cur.horse_count - 1});
        dist[nx][ny][cur.horse_count - 1] = dist[cur.x][cur.y][cur.horse_count] + 1;
        if (nx == H - 1 && ny == W - 1) {
          cout << dist[nx][ny][cur.horse_count - 1] << "\n";
          return 0;
        }
      }
    }
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.x + dx[dir];
      int ny = cur.y + dy[dir];
      if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
      if (visited[nx][ny][cur.horse_count] || board[nx][ny] == 1) continue;
      visited[nx][ny][cur.horse_count] = true;
      qe.push({nx, ny, cur.horse_count});
      dist[nx][ny][cur.horse_count] = dist[cur.x][cur.y][cur.horse_count] + 1;
      if (nx == H - 1 && ny == W - 1) {
        cout << dist[nx][ny][cur.horse_count] << "\n";
        return 0;
      }
    }
  }

  if (qe.empty()) cout << -1 << "\n";

  return 0;
}
