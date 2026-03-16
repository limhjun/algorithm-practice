#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, K;
  cin >> N >> K;

  int res = 1;
  for (int i = 1; i <= K; i++) res = res * (N + i - K) / i;

  cout << res << "\n";

  return 0;
}
