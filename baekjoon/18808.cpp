#include <bits/stdc++.h>

using namespace std;

int N, M; // 1 <= N, M <= 40
int K; // 1 <= K <= 100
int notebook[41][41];
int R, C; // 1 <= R, C <= 10
int sticker[11][11];

bool pastable(int x, int y) {
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (notebook[x + i][y + j] == 1 && sticker[i][j] == 1)
        return false;
    }
  }
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (sticker[i][j] == 1) {
        notebook[x + i][y + j] = 1;
      }
    }
  }
  return true;
}

void rotate() {
  int tmp[11][11];

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      tmp[i][j] = sticker[i][j];
    }
  }

  for (int i = 0; i < C; i++) {
    for (int j = 0; j < R; j++) {
      sticker[i][j] = tmp[R - 1 - j][i];
    }
  }

  swap(R, C);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M >> K;

  while (K--) {
    cin >> R >> C;

    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        cin >> sticker[i][j];
      }
    }

    for (int rot = 0; rot < 4; rot++) {
      bool is_paste = false;
      for (int x = 0; x <= N - R; x++) {
        if (is_paste) break;
        for (int y = 0; y <= M - C; y++) {
          if (pastable(x, y)) {
            is_paste = true;
            break;
          }
        }
      }
      if (is_paste) break;
      rotate();
    }
  }

  int cnt = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (notebook[i][j] == 1) cnt++;
    }
  }

  cout << cnt << "\n";

  return 0;
}
