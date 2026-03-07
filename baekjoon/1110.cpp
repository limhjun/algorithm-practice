#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  int original = N;
  int cycle = 0;

  while (true) {
    int sum = (N / 10) + (N % 10);
    int new_num = (N % 10) * 10 + (sum % 10);

    cycle++;
    N = new_num;

    if (new_num == original) break;
  }

  cout << cycle << "\n";

  return 0;
}
