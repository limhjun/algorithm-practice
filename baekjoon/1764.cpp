#include <bits/stdc++.h>

using namespace std;

map<string, int> mp;
map<string, int> res;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;
  cin >> N >> M;

  while (N--) {
    string s;
    cin >> s;

    mp[s]++;
  }

  int cnt = 0;
  while (M--) {
    string s;
    cin >> s;

    if (mp[s] != 0) {
      cnt++;
      res[s]++;
    }
  }

  cout << cnt << "\n";

  for (auto &p : res) {
    if (p.second != 0) {
      cout << p.first << "\n";
    }
  }

  return 0;
}
