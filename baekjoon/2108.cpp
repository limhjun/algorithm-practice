#include <bits/stdc++.h>

using namespace std;
#define ll long long

int num_array[8002];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N; // 1 <= N <= 500,000, N은 홀수
  if (!(cin >> N)) return 0;

  vector<int> v;
  v.reserve(N);

  // 입력되는 정수의 절댓값은 4,000을 넘지 않는다.
  // 산술평균 : N개의 수들의 합을 N으로 나눈 값
  double sum = 0;
  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    v.push_back(num);
    sum += (double) num;
  }
  int a = round(sum / N);
  cout << a << "\n";

  // 중앙값 : N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
  sort(v.begin(), v.end());
  int b = v[((ll)v.size()) / 2];
  cout << b << "\n";

  // 최빈값 : N개의 수들 중 가장 많이 나타나는 값
  for (int i = 0; i < N; i++) {
    num_array[v[i] + 4000]++;
  }
  int max = 0;
  for (int i = 0; i < 8002; i++) {
    if (num_array[i] > max) {
      max = num_array[i];
    }
  }
  bool is_second = false;
  int cnt = 0;
  int c = 0;
  for (int i = 0; i < 8002; i++) {
    if (is_second) break;
    if (num_array[i] == max) {
      c = i - 4000;
      cnt++;
    }
    if (cnt == 2) {
      is_second = true;
    }
  }
  cout << c << "\n";

  // 범위 : N개의 수들 중 최댓값과 최솟값의 차이
  ll d = v[v.size() - 1] - v[0];
  cout << d << "\n";
}