#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int L; cin >> L;
  string s; cin >> s;

  const long long M = 1234567891;
  long long r = 1;
  long long sum = 0;
  for (int i = 0; i < L; i++) {
    sum = (sum + (s[i] - 'a' + 1) * r) % M;
    r = (r * 31) % M;
  }

  cout << sum << "\n";

  return 0;
}