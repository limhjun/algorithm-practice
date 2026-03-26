#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;
  vector<int> v1;
  for (int i = 0; i < N; i++) {
    int n;
    cin >> n;
    v1.push_back(n);
  }

  sort(v1.begin(), v1.end());

  int M;
  cin >> M;
  for (int i = 0; i < M; i++) {
    int n;
    cin >> n;
    if (binary_search(v1.begin(), v1.end(), n)) cout << 1;
    else cout << 0;
    cout << " ";
  }

  return 0;
}
