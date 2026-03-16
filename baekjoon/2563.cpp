#include <bits/stdc++.h>

using namespace std;

int board[100][100];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  while (N--) {
    int c, r;
    cin >> c >> r;

    for (int i = r; i < r + 10; i++) {
      for (int j = c; j < c + 10; j++) {
        if (board[i][j] == 1) continue;
        board[i][j] = 1;
      }
    }
  }

  int res = 0;
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      if (board[i][j] == 1) res++;
    }
  }

  cout << res << "\n";

  return 0;
}
