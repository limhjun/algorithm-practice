#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  int size[6];
  for (int & i : size) {
    cin >> i;
  }

  int T, P;
  cin >> T >> P;

  int cnt_t = 0;
  for (int & i : size) {
    if (i % T == 0) {
      cnt_t += i / T;
    } else {
      cnt_t += (i / T) + 1;
    }
  }

  int cnt_p1 = N / P;
  int cnt_p2 = 0;
  if (N % P != 0) {
    cnt_p2 = N - (cnt_p1 * P);
  }

  cout << cnt_t << "\n" << cnt_p1 << " " << cnt_p2;

  return 0;
}
