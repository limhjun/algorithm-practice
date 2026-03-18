#include <bits/stdc++.h>

using namespace std;

void MergeSort(int* begin, int* end) {
  if (end - begin <= 1) return;

  int* mid = begin + ((end - begin) / 2);
  MergeSort(begin, mid);
  MergeSort(mid, end);
  int arr[end - begin];
  int* i = begin;
  int* j = mid;
  int cur = 0;
  while (i != mid && j != end) {
    if (*i <= *j) {
      arr[cur] = *i;
      i++;
    } else {
      arr[cur] = *j;
      j++;
    }
    cur++;
  }
  if (i == mid) {
    while (j != end) {
      arr[cur++] = *j;
      j++;
    }
  } else if (j == end) {
    while (i != mid) {
      arr[cur++] = *i;
      i++;
    }
  }

  int k = 0;
  while (begin != end) {
    *begin = arr[k++];
    begin++;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  vector<int> v;
  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    v.push_back(num);
  }

  // sort(v.begin(), v.end());
  MergeSort(&v[0], &v[v.size()]);

  for (int i = 0; i < v.size(); i++) cout << v[i] << "\n";

  return 0;
}
