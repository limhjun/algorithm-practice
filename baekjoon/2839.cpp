#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N; // 3 <= N <= 5000
  cin >> N;

  for (int i = N / 5; i >= 0; i--) {
    int r = N - (5 * i);
    if (r % 3 == 0) {
      cout << i + r / 3;
      return 0;
    }
  }

  cout << -1;
  return 0;
}
