#include <bits/stdc++.h>

using namespace std;

int board[130][130];
int white_cnt = 0;
int blue_cnt = 0;

void func(int row, int col, int l) {
  int x = board[row][col];
  for (int i = row; i < row + l; i++) {
    for (int j = col; j < col + l; j++) {
      if (board[i][j] != x) {
        func(row, col, l / 2);
        func(row, col + l / 2, l / 2);
        func(row + l / 2, col, l / 2);
        func(row + l / 2, col + l / 2, l / 2);
        return;
      }
    }
  }
  if (x == 0) {
    white_cnt++;
  } else {
    blue_cnt++;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N; cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
    }
  }

  func(0, 0, N);

  cout << white_cnt << "\n";
  cout << blue_cnt << "\n";

  return 0;
}
