#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T, H, W, N;
  cin >> T;

  while (T--) {
    // H: 층수
    // W: 각 층마다 방수
    // N: 몇 번째 손님
    cin >> H >> W >> N;

    int count = 0;
    for (int i = 1; i <= W; i++) {
      for (int j = 1; j <= H; j++) {
        count++;
        if (count == N) {
          if (i < 10) {
            cout << j << "0" << i << "\n";
          } else {
            cout << j << i << "\n";
          }
          break;
        }
      }
    }
  }

  return 0;
}
