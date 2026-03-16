#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, K;
  cin >> N >> K;

  int res;
  int n = 1;
  int m = 1;
  for (int i = 0; i < N; i++) {
    n *= (i + 1);
  }
  for (int i = 0; i < K; i++) {
    m *= (i + 1);
  }
  for (int i = 0; i < N - K; i++) {
    m *= (i + 1);
  }

  res = n / m;

  cout << res << "\n";

  return 0;
}
