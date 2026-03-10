#include <bits/stdc++.h>

using namespace std;

vector<int> prime_num;

bool is_prime(int num) {
  int cnt = 0;
  for (int i = 1; i <= num; i++) {
    if (num % i == 0) {
      cnt++;
    }
  }
  if (cnt == 2) return true;
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int A, B;
  cin >> A >> B;

  for (int i = 1; i <= 10000; i++) {
    if (is_prime(i)) {
      prime_num.push_back(i);
    }
  }

  int GCD = 1;

  for (int i : prime_num) {
    while (A % i == 0 && B % i == 0) {
      GCD *= i;
      A /= i;
      B /= i;
    }
  }

  int LCM = GCD * A * B;

  cout << GCD << "\n" << LCM;

  return 0;
}
