#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s; cin >> s;

  int m = s[s.size() - 1] - '0';
  int sum = 0;
  int weight = 0;
  for (int i = 0; i < s.size() - 1; i++) {
    if (s[i] == '*') {
      if (i % 2 == 1) {
        weight = 3;
      } else {
        weight = 1;
      }
      continue;
    }
    if (i % 2 == 1) {
      sum += (s[i] - '0') * 3;
      continue;
    }
    sum += (s[i] - '0');
  }

  for (int x = 0; x <= 9; x++) {
    if ((sum + x * weight + m) % 10 == 0) {
      cout << x << "\n";
      break;
    }
  }
  return 0;
}
