#include <bits/stdc++.h>

using namespace std;

char board[52][52];

int CountPoint(int start_x, int start_y) {
  int cnt = 0; // (0, 0)이 W인 경우
  for (int i = start_x; i < start_x + 8; i++) {
    for (int j = start_y; j < start_y + 8; j++) {
      if ((i + j) % 2 == 0) {
        if (board[i][j] == 'B') cnt++;
      } else {
        if (board[i][j] == 'W') cnt++;
      }
    }
  }

  return min(cnt, 64 - cnt);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M; // 8 <= N, M <= 50
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];
    }
  }

  int min_result = 8 * 8;
  for (int i = 0; i <= N - 8; i++) {
    for (int j = 0; j <= M - 8; j++) {
      int min_cnt = CountPoint(i, j);
      min_result = min(min_result, min_cnt);
    }
  }

  cout << min_result << "\n";

  return 0;
}
