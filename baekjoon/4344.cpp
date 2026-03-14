#include <bits/stdc++.h>

using namespace std;

vector<int> grades;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int C;
  cin >> C;

  while (C--) {
    int N;
    cin >> N;

    int sum = 0;
    for (int i = 0; i < N; i++) {
      int grade;
      cin >> grade;
      grades.push_back(grade);
      sum += grade;
    }
    double avg = static_cast<double>(sum) / N;
    // 학생들의 성적을 알아야하기 때문에 담아둘 수 있는 자료구조가 필요함.
    int cnt = 0;
    for (int g: grades) {
      if ((double) g > avg) {
        cnt++;
      }
    }
    grades.erase(grades.begin(), grades.end());
    double result = (double) cnt / N * 100.000;
    cout << fixed << setprecision(3) << result << "%" << "\n";
  }
  return 0;
}
