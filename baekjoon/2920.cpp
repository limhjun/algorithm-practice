#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int nums[8];
  for (int &num: nums) {
    cin >> num;
  }

  int ascending_cnt = 0;
  int descending_cnt = 0;
  for (int i = 1; i < 8; i++) {
    if (nums[i] == nums[i - 1] + 1) {
      ascending_cnt++;
    } else if (nums[i] == nums[i - 1] - 1) {
      descending_cnt++;
    }
  }

  if (ascending_cnt == 7) {
    cout << "ascending";
  } else if (descending_cnt == 7) {
    cout << "descending";
  } else {
    cout << "mixed";
  }

  return 0;
}
