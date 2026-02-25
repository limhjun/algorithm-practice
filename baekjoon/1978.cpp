#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  int cnt = 0;
  while (N--) {
    int num;
    cin >> num;

    bool is_prime = true;
    if (num == 1) is_prime = false;
    for (int i = 2; i * i <= num; i++) {
      if (num % i == 0) {
        is_prime = false;
        break;
      }
    }

    if (is_prime) cnt++;
  }

  cout << cnt;

  return 0;
}
