#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  char arr[5][15];
  memset(arr, 0, sizeof(arr));
  for (int i = 0; i < 5; i++) cin >> arr[i];

  for (int j = 0; j < 15; j++) {
    for (int i = 0; i < 5; i++) {
      if (arr[i][j]) cout << arr[i][j];
    }
  }

  return 0;
}
