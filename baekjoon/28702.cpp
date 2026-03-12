#include <bits/stdc++.h>

using namespace std;

string FizzBuzz(int num);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  for (int i = 3; i > 0; i--) {
    cin >> s;
    if (isdigit(s[0])) {
      int n = stoi(s) + i;
      cout << FizzBuzz(n) << "\n";
      return 0;
    }
  }
  return 0;
}

string FizzBuzz(int num) {
  if (num % 15 == 0) return "FizzBuzz";
  if (num % 3 == 0) return "Fizz";
  if (num % 5 == 0) return "Buzz";
  return to_string(num);
}
