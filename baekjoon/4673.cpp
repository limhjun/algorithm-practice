#include <bits/stdc++.h>

using namespace std;

int d(int n) {
  int sum = n;
  while (n > 0) {
    sum += (n % 10);
    n /= 10;
  }
  return sum;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  bool checked[10001] = {false};

  for (int i = 1; i <= 10000; i++) {
    int x = d(i);
    if (x <= 10000) checked[x] = true;
  }

  for (int i = 1; i <= 10000; i++) {
    if (!checked[i]) cout << i << "\n";
  }

  return 0;
}
