#include<iostream>

using namespace std;
string s[601];
int dp[601][102][102];
int sum0[601], sum1[601];// 0的前缀和和1的前缀和
int main() {
  int t, m, n;// m个0n个1
  cin >> t >> m >> n;
  for (int i = 1;i <= t;i++) {
    cin >> s[i];
    int l = s[i].length();
    for (int j = 0;j < l;j++) {
      sum0[i] += s[i][j] == '0';
      sum1[i] += s[i][j] == '1';
    }
    // sum0[i] += sum0[i - 1];
    // sum1[i] += sum1[i - 1];
  }
  
  for (int i = 1;i <= t;i++) {// 前i个字符串里面，组合成j个0，k个1的方案总数
    // int len = s[i].length();
    int cnt0 = sum0[i];// 第i个字符串中0的总个数
    int cnt1 = sum1[i];// 第i个字符串中1的总个数
    for (int j = 0;j <= m;j++) {// 拿j个0
      for (int k = 0;k <= n;k++) {
        dp[i][j][k] = dp[i - 1][j][k];// 默认不拿这个字符串
        if (j >= cnt0 && k >= cnt1) {
          dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - cnt0][k - cnt1] + 1);
        }
      }
    }
  }
  cout << dp[t][m][n];
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
/**
5 5 3
10 0001 111001 1 0


3 1 1
10 0 1
 */