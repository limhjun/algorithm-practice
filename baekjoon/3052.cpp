#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  set<int> st;

  for (int i = 0; i < 10; i++) {
    int num;
    cin >> num;

    st.emplace(num % 42);
  }

  cout << st.size() << "\n";

  return 0;
}