#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N; cin >> N;

  int cnt = 0;
  while (N >= 5) {
    cnt += N / 5;
    N /= 5;
  }

  cout << cnt << "\n";

  return 0;
}