#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  int cnt = 0;
  for (int i = 1; i <= N; i++) {
    if (1 <= i && i <= 99) {
      cnt++;
      continue;
    }

    if (i == 1000) break;

    int n1 = i % 10;
    int n2 = (i / 10) % 10;
    int n3 = i / 100;
    if (n3 - n2 == n2 - n1) {
      cnt++;
    }
  }

  cout << cnt << "\n";
  return 0;
}
