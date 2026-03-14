#include <bits/stdc++.h>

using namespace std;

int dist[100001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, K;
  cin >> N >> K;

  fill(dist, dist + 100001, -1);

  deque<int> dq;
  dq.push_back(N);
  dist[N] = 0;

  while (!dq.empty()) {
    int cur = dq.front(); dq.pop_front();

    int nx = cur * 2;
    if (nx <= 100000 && (dist[nx] == -1 || dist[nx] > dist[cur])) {
      dist[nx] = dist[cur];
      dq.push_front(nx);
    }

    nx = cur - 1;
    if (0 <= nx  && (dist[nx] == -1 || dist[nx] > dist[cur] + 1)) {
      dist[nx] = dist[cur] + 1;
      dq.push_back(nx);
    }

    nx = cur + 1;
    if (nx <= 100000  && (dist[nx] == -1 || dist[nx] > dist[cur] + 1)) {
      dist[nx] = dist[cur] + 1;
      dq.push_back(nx);
    }
  }

  cout << dist[K] << "\n";

  return 0;
}
