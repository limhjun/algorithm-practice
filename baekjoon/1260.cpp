#include <bits/stdc++.h>
using namespace std;

int N, M, V;
int board[1001][1001];
bool visited[1001];

void DFS(int V) {
  if (V < 1 || V > N) return;

  visited[V] = true;
  cout << V << " ";
  for (int i = 1; i <= N; i++) {
    if (board[V][i] == 1 && !visited[i]) {
      DFS(i);
    }
  }
}

void BFS(int V) {
  queue<int> q;
  q.push(V);
  visited[V] = true;
  cout << V << " ";
  while (!q.empty()) {
    auto cur = q.front(); q.pop();
    if (cur < 1 || cur > N) continue;
    for (int i = 1; i <= N; i++) {
      if (board[cur][i] == 1 && !visited[i]) {
        q.push(i);
        visited[i] = true;
        cout << i << " ";
      }
    }
  }
}

void initialize() {
  for (int i = 1; i <= N; i++) visited[i] = false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  cin >> N >> M >> V;

  while (M--) {
    int i, j;
    cin >> i >> j;
    board[i][j] = 1;
    board[j][i] = 1;
  }

  DFS(V);
  initialize();
  cout << "\n";
  BFS(V);

  return 0;
}
