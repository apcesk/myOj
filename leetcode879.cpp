#include<iostream>

using namespace std;
#define int long long
const int MOD = 1e9 + 7;
int dp[102][102][102];
int n, m, k;// n名员工，m种工作, 最低收益是k
int group[101], profit[101];
signed main() {
  cin >> n >> m >> k;
  for (int i = 1;i <= m;i++) {
    cin >> group[i] >> profit[i];
  }
  dp[0][0][0] = 1;
  for (int i = 1;i <= m;i++) {// 枚举每一个工作
    // 当前工作需要group[i]人
    // 当前工作的工资是profit[i]
    for (int j = 0;j <= n;j++) {// 枚举人数
      for (int l = 0;l <= k;l++) {// 盈利的计划值
        dp[i][j][k] = dp[i - 1][j][k];// 当前人数不够做第i份工作
        if (j >= group[i]) {// 当前的人数够做第i份工作
          dp[i][j][k] = dp[i - 1][j][k] + dp[i - 1][j - group[i]][max(0ll, l - profit[i])];
        }
        dp[i][j][k] %= MOD;
      }
    }
  }
  int ans = 0;
  for (int i = 0;i <= n;i++) {
    ans += dp[m][i][k];
  }
  cout << ans;
  return 0;
}
/**
DDDDD           IIIIII        OOOOOOOO
DD  DD            II          OO    OO
DD   DD           II          OO    OO
DD    DD          II          OO    OO
DD    DD          II          OO    OO
DD    DD          II          OO    OO
DD   DD           II          OO    OO
DD  DD            II          OO    OO
DDDDD           IIIIII        OOOOOOOO
*/
/*
5 2 3
2 2
2 3

10 3 5
2 6
3 7
5 8
 */