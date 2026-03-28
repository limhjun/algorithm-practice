#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s; cin >> s;

  int sum = 0;
  int starIdx = -1;
  for (int i = 0; i < 12; i++) {
    if (s[i] == '*') {
      starIdx = i;
      continue;
    }

    int num = s[i] - '0';

    if (i % 2 == 1) {
      sum += num * 3;
    } else {
      sum += num;
    }
  }
  int last = s[12] - '0';
  int weight = starIdx % 2 == 1 ? 3 : 1;

  for (int x = 0; x <= 9; x++) {
    if ((sum + x * weight + last) % 10 == 0) {
      cout << x << "\n";
      break;
    }
  }

  return 0;
}
