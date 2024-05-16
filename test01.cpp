#include<iostream>


using namespace std;
int n;
bool mark[21];
int person_job[21][21];

int sum = 0xfffffff7;

void dfs(int person, int now_sum) {
  if (person == n + 1) {
    sum = sum < now_sum ? sum : now_sum;
    return;
  }
  for (int j = 1;j <= job_count;j++) {
    if (mark[j] == false) {
      // 计算当前这个人拿到这个活的花销
      now_sum += person_job[person][j];
      mark[j] = true;
      // 给下一个人干活
      dfs(person + 1, now_sum);
      // 回溯
      mark[j] = false;
      now_sum -= person_job[person][j];
    }
  }

}



void hannuoi(char source, char mid, char taget, int n) {
  if (n == 1) {
    cout << "from" << source << "to" << taget;
  }

  hannuoi(source, taget, mid, n-1);
  cout << "from" << source << "to" << taget;
  hannuoi(mid, source, taget, n-1);

}
int main() {
  cin >> n;
  for (int i = 1;i <= n;i++) {
    for (int j = 1;j <= n;j++) {
      cin >> person_job[i][j];
    }
  }
  dfs(1, 0);
  cout << sum;
  return 0;
}