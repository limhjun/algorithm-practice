#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  int sum = 0;
  int num = 0; // 몇 번째인지
  while (true) {
    num++;
    sum += num;
    if (N <= sum) break;
  }

  int k = num - 1;
  int sum2 = k * (k + 1) / 2;
  int n;
  int m;
  int pos = N - sum2;
  if (num % 2 == 0) {
    n = pos;
    m = num + 1 - pos;
  } else {
    m = pos;
    n = num + 1 - pos;
  }

  cout << n << '/' << m << '\n';

  return 0;
}
