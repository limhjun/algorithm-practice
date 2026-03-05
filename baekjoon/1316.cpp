#include <bits/stdc++.h>

using namespace std;

int abc_cnt[30];

void flushCnt() {
  for (auto & a : abc_cnt) {
    a = 0;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N; // 1 <= N <= 100
  cin >> N;

  int word_cnt = 0;
  while (N--) {
    string s;
    cin >> s;
    // 1. s를 순회한다
    // 2. 바로 전과 같이 않은 문자인데 쓰인 적이 있는 문자면 그룹단어가 아니다.
    // 3. 다 순회하고 나서 그룹단어 체크가 true이면 카운트+1

    bool word_check = true;
    abc_cnt[(s[0] - 'a')]++;
    for (int i = 1; i < s.length(); i++) {
      if (s[i - 1] != s[i] && abc_cnt[s[i] - 'a'] > 0) {
        word_check = false;
        break;
      }
      abc_cnt[s[i] - 'a']++;
    }
    if (word_check) word_cnt++;
    flushCnt();
  }

  cout << word_cnt << "\n";

  return 0;
}
