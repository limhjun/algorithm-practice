#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  vector<int> v;
  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    v.push_back(num);
  }

  sort(v.begin(), v.end());

  for (int i = 0; i < v.size(); i++) cout << v[i] << "\n";

  return 0;
}
