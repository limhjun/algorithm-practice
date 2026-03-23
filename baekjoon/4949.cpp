#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  while (getline(cin, s)) {
    if (s == ".") break;

    stack<char> st;
    bool valid = true;
    for (auto c : s) {
      if (c == '(' || c == '[') {
        st.push(c);
      } else if (c == ')') {
        if (st.empty() || st.top() != '(') {valid = false; break; }
        st.pop();
      } else if (c == ']') {
        if (st.empty() || st.top() != '[') {valid = false; break; }
        st.pop();
      }
    }

    cout << (valid && st.empty() ? "yes" : "no") << "\n";
  }


  return 0;
}
