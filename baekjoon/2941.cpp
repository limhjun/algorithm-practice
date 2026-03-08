#include <bits/stdc++.h>

using namespace std;

string alpha[] = {"c=", "c-", "d-", "lj", "nj", "s=", "z="};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  int cnt = 0;
  for (int i = 0; i < s.length(); ) {
    bool matched = false;

    if (i + 2 < s.length() && s.substr(i, 3) == "dz=") {
      cnt++;
      i += 3;
      continue;
    }

    for (string &a : alpha) {
      if (i + 1 < s.length() && s.substr(i, 2) == a) {
        cnt++;
        i += 2;
        matched = true;
      }
    }

    if (!matched) {
      cnt++;
      i += 1;
    }
  }

  cout << cnt << "\n";

  return 0;
}
