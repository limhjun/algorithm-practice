#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;
  cin >> N >> M;

  vector<vector<int>> conn(N + 1, vector<int>(N + 1, 0));
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    conn[a][b] = 1;
    conn[b][a] = 1;
  }

  vector<bool> visited(N + 1, false);
  queue<int> q;
  q.push(1);
  visited[1] = true;

  int cnt = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v = 1; v <= N; v++) {
      if (conn[u][v] == 0 || visited[v]) continue;
      visited[v] = true;
      cnt++;
      q.push(v);
    }
  }

  cout << cnt << "\n";

  return 0;
}
