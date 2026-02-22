#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N; // 1 <= N <= 500,000
  map<int, int> mp;
  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    if (mp[num]) {
      mp[num]++;
    } else {
      mp[num] = 1;
    }
  }
  
  int M;
  cin >> M;
  int num[M];
  for (int i = 0; i < M; i++) cin >> num[i];
  
  for (int i = 0; i < M; i++) {
    cout << mp[num[i]] << " ";
  }
  return 0;
}
