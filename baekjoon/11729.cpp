#include <bits/stdc++.h>
using namespace std;

void func1(int k, int from, int to) {
  if (k == 1) {
    cout << from << ' ' << to << '\n';
    return;
  }
  int via = 6 - (from + to);
  func1(k - 1, from, via);
  func1(1, from, to);
  func1(k - 1, via, to);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  cout << (1 << N) - 1 << '\n';
  func1(N, 1, 3);
}