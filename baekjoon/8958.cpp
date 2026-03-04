#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  string ox;
  for (int i = 0; i < N; i++) {
    cin >> ox;

    int sum = 0, streak = 0;
    for (char c : ox) {
      if (c == 'O') {
        streak++;
        sum += streak;
      } else {
        streak = 0;
      }
    }
    cout << sum << "\n";
  }

  return 0;
}
