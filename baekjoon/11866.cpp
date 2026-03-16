#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, K;
  cin >> N >> K;

  queue<int> q;
  for (int i = 1; i <= N; i++) {
    q.push(i);
  }

  vector<int> res;
  while (!q.empty()) {
    for (int i = 1; i <= K; i++) {
      int n = q.front();
      q.pop();
      if (i == K) {
        res.push_back(n);
      } else {
        q.push(n);
      }
    }
  }

  cout << "<";
  for (int i = 0; i < res.size(); i++) {
    if (i == res.size() - 1) {
      cout << res[i];
    } else {
      cout << res[i] << ", ";
    }
  }
  cout << ">";

  return 0;
}
