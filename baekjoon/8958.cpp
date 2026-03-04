#include <bits/stdc++.h>

using namespace std;

int ox_cnt[82];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  string ox;
  for (int i= 0; i < N; i++) {
    // 길이가 0보다 크고 80보다 작은 문자열
    int sum = 0;
    cin >> ox;
    if (ox[0] == 'O') {
      ox_cnt[0] = 1;
      sum++;
    } else {
      ox_cnt[0] = 0;
    }
    for (int j = 1 ; j < ox.length(); j++) {
      if (ox[j] == 'O' && ox_cnt[j - 1] != 0) {
        ox_cnt[j] = ox_cnt[j - 1] + 1;
        sum += ox_cnt[j];
      } else if (ox[j] == 'O' && ox_cnt[j - 1] == 0) {
        ox_cnt[j] = 1;
        sum += ox_cnt[j];
      } else {
        ox_cnt[j] = 0;
      }
    }

    cout << sum << "\n";
  }

  return 0;
}