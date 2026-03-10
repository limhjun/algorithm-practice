#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> people;
vector<int> results;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  while (N--) {
    int x, y;
    cin >> x >> y;

    people.emplace_back(x, y);
  }

  for (int i = 0; i < people.size(); i++) {
    int kilo = people[i].first;
    int meter = people[i].second;
    int k = 0;
    for (int j = 0; j < people.size(); j++) {
      if (j != i && people[j].first > kilo && people[j].second > meter) {
        k++;
      }
    }
    results.push_back(k + 1);
  }

  for (int i : results) cout << i << " ";

  return 0;
}
