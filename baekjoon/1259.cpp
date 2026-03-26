#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  while (true) {
    string num; cin >> num;
    if (num == "0") break;

    int left = 0;
    int right = num.size() - 1;
    while (left <= right) {
      if (num[left] != num[right]) {
        cout << "no\n";
        break;
      }
      left++;
      right--;
    }
    if (left >= right) {
      cout << "yes\n";
    }
  }
  return 0;
}
