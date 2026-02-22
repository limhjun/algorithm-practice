#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N; // 1 <= N <= 500,000
  vector<int> cards(N);
  for (int i = 0; i < N; i++) {
    cin >> cards[i];
  }

  sort(cards.begin(), cards.end());
  
  int M;
  cin >> M;

  for (int i = 0; i < M; i++) {
    int num;
    cin >> num;

    cout << upper_bound(cards.begin(), cards.end(), num) - lower_bound(cards.begin(), cards.end(), num) << " ";
  }
  return 0;
}
