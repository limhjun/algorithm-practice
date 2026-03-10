#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int A, B, V;
  cin >> A >> B >> V;

  int day = (V - A) / (A - B);
  if ((V - A) % (A - B) != 0) day++;

  cout << day + 1 << "\n";

  return 0;
}
