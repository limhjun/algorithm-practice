#include <bits/stdc++.h>

using namespace std;

int N;
int T[20], P[20];
int max_profit = 0;

void func(int day, int sum) {
  // 1. 종료 조건
  if (day == N + 1) {
    max_profit = max(sum, max_profit);
    return;
  }

  if (day > N + 1) {
    return;
  }

  // 2. 경우의 수 탐색
  func(day + 1, sum);

  if (day + T[day] <= N + 1) {
    func(day + T[day], sum + P[day]);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  vector<pair<int, int>> v(N + 1);

  for (int i = 1; i <= N; i++) {
    // 각각의 T, P를 다 어딘가에 담아놓고 최대 수익을 계산해야한다
    // 인덱스 하나에 T, P 두 개가 담겨야된다
    // 연속적이므로 vector를 사용한다
    cin >> T[i] >> P[i];
  }

  func(1, 0);

  cout << max_profit << "\n";

  return 0;
}