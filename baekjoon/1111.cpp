#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  vector<int> v;
  for (int i =0 ; i < N; i++) {
    int num;
    cin >> num;
    v.push_back(num);
  }

  if (N == 1) {
    cout << "A\n";
    return 0;
  }

  if (N == 2) {
    if (v[0] == v[1]) cout << v[0] << "\n";
    else cout << "A\n";
    return 0;
  }

  if (v[1] == v[0]) {
    if (v[2] != v[1]) {
      cout << "B\n";
      return 0;
    }

    for (int i = 1; i < N; i++) {
      if (v[i] != v[0]) {
        cout << "B\n";
        return 0;
      }
    }

    cout << v[0] << "\n";
    return 0;
  }

  if ((v[2] - v[1]) % (v[1] - v[0]) != 0) {
    cout << "B\n";
    return 0;
  }

  int a = (v[2] - v[1]) / (v[1] - v[0]);
  int b = v[1] - a * v[0];

  for (int i = 1; i < N; i++) {
    if (v[i] != v[i - 1] * a + b) {
      cout << "B\n";
      return 0;
    }
  }

  cout << v[N - 1] * a + b << "\n";
  return 0;
}
