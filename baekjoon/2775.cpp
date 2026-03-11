#include <bits/stdc++.h>

using namespace std;

int cache[15][15];

int func(int k, int n) {
  if (k == 0) return n;
  if (n == 1) return 1;

  int &res = cache[k][n];
  res = func(k, n - 1) + func(k - 1, n);

  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  while (T--) {
    int k, n;
    cin >> k >> n;

    cout << func(k, n) << "\n";
  }

  return 0;
}
