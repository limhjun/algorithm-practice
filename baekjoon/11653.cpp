#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N; // 1 ≤ N ≤ 10,000,000
  cin >> N;

  for (int i = 2; i <= N; i++) {
    while (N % i == 0) {
      cout << i << "\n";
      N /= i;
    }
  }

  return 0;
}
