#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int x, y, z;

  while (true) {
    cin >> x >> y >> z;
    if (x == 0 && y == 0 && z == 0) break;

    if (x > y) {
      int tmp = x;
      x = y;
      y = tmp;
    }

    if (y > z) {
      int tmp = y;
      y = z;
      z = tmp;
    }

    if (x * x + y * y == z * z) {
      cout << "right";
    } else {
      cout << "wrong";
    }
    cout << "\n";
  }

  return 0;
}
