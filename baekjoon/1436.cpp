#include <bits/stdc++.h>

using namespace std;

bool ContainsTripleSix(int num) {
  string s = to_string(num);

  for (int i = 0; i < s.size() - 2; i++) {
    string target = s.substr(i, 3);
    if (target == "666") return true;
  }

  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N; cin >> N;

  int cnt = 0;
  int num = 666;
  while (cnt < N) {
    if (ContainsTripleSix(num)) {
      cnt++;
    }

    if (cnt == N) {
      cout << num << "\n";
    }

    num++;
  }
  return 0;
}
