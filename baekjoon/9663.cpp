#include <bits/stdc++.h>

using namespace std;

int queen[16];
int N;
int ans = 0;

bool canPlace(int row, int col) {
  for (int prevRow = 0; prevRow < row; prevRow++) {
    int prevCol = queen[prevRow];
    if (prevCol == col) return false;
    if (abs(row - prevRow) == abs(col - prevCol)) return false;
  }
  return true;
}

void dfs(int row) {
  if (row == N) {
    ans++;
    return;
  }

  for (int col = 0; col < N; col++) {
    if (!canPlace(row, col)) continue;
    queen[row] = col;
    dfs(row + 1);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  // 1. 0행에서 한 열을 퀸으로 배치한다
  // 2-1. 다음 행에서 한 열을 퀸 후보로 둔다
  // 2-2. 여태까지 퀸들과 열이 같은지 혹은 대각선이 겹치는지 확인하고 겹치지 않는다면 퀸으로 배치한다
  // 3. N행 전까지 2의 과정을 반복한다.
  dfs(0); // 사실 여기에서 dfs로 해야하는 발상이 이해가 안간다. 왜 하필이면 bfs지? 만약 완전히 잊고 이것과 비슷한 문제를 풀면 함수명도 그냥 func라 하고 단순히 for문으로 순회하면서 절차적으로 로직을 구현했을 거 같다.

  cout << ans;
  return 0;
}
