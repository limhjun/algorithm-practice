#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;
  cin >> N >> M; // 1 <= N, M <= 100,000

  unordered_map<string, int> nameToNum;
  vector<string> numToName(N + 1);
  for (int i = 1; i <= N; i++) {
    string name;
    cin >> name;
    nameToNum.emplace(name, i);
    numToName[i] = name;
  }

  for (int i = 0; i < M; i++) {
    string query;
    cin >> query;

    if (isdigit(query[0])) {
      int num = stoi(query);
      cout << numToName[num] << "\n";
    } else {
      cout << nameToNum[query] << "\n";
    }
  }

  return 0;
}
