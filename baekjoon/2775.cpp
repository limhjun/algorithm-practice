#include <bits/stdc++.h>

using namespace std;

int func(int floor, int room) {
  if (floor == 0) return room;

  int sum = 0;
  for (int i = 1; i <= room; i++) {
    sum += func(floor - 1, i);
  }

  return sum;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  while (T--) {
    int k, n;
    cin >> k >> n;

    int result = func(k, n);

    cout << result << "\n";
  }

  return 0;
}
