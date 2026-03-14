#include <bits/stdc++.h>

using namespace std;

int num[100];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;
  cin >> N >> M;

  for (int i = 0; i < N; i++) cin >> num[i];

  int sum = 0;
  int sub = 300000;
  int result = 0;
  for (int i = 0; i < N - 2; i++) {
    sum += num[i];
    for (int j = i + 1; j < N - 1; j++) {
      sum += num[j];
      for (int k = j + 1; k < N; k++) {
        sum += num[k];
        if (M - sum == 0) {
          cout << sum << "\n";
          return 0;
        }
        if (M - sum > 0) {
          sub = min(M - sum, sub);
          if (sub == M - sum) {
            result = sum;
          }
        }
        sum -= num[k];
      }
      sum -= num[j];
    }
    sum = 0;
  }

  cout << result << "\n";

  return 0;
}
