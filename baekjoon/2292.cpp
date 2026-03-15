#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  int layer = 1;
  int num = 1;
  while (N > num) {
    num += 6 * layer;
    layer++;
  }

  cout << layer;

  return 0;
}