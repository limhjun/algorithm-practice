#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  vector<string> v;
  while (N--) {
    string s;
    cin >> s;
    v.push_back(s);
  }

  sort(v.begin(), v.end(), [](const string &a, const string &b) {
    return a.length() == b.length() ? a < b : a.length() < b.length();
  });

  cout << v[0] << "\n";
  for (int i = 1; i < v.size(); i++) {
    if (v[i - 1] == v[i]) continue;
    cout << v[i] << "\n";
  }

  return 0;
}
