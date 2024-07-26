#include<iostream>

using namespace std;
const int N = 2e3 + 10;
int v[N << 1], n;
int dp[N][N];
// 对于任意的v[i] 在第k天被吃掉，那么它的收益固定是 v[i] * k
// 而其可能是吃掉了它前面所有的收益，或者是吃掉它后面所有的收益
// (dp[l][i - 1], dp[i + 1][r]) + v[i] * k;
int main() {
  cin >> n;
  for (int i = 1;i <= n;i++) {
    cin >> v[i];
    // dp[i][i] = v[i] * n;// 假设最后一天拿它
  }
  for (int L = 1;L <= n;L++) {// 区间长度
    for (int l = 1;l + L - 1 <= n;l++) {// 区间起点
      int r = l + L - 1;// 区间终点
      dp[l][r] = max(dp[l + 1][r] + v[l] * (n - L + 1), dp[l][r - 1] + v[r] * (n - L + 1));
    }
  }
  cout << dp[1][n];
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
 1 3 1 5 2
 第一天吃左边的 sum = 1, v = 3 1 5 2
 第二天吃右边的 sum = 5, v = 3 1 5
 第三天吃左边的 sum = 14, v = 1 5
 第四天吃左边的 sum = 18, v = 5
 第五天吃最后一个, sum = 43
 */
/*
  区间长度为1，则 dp[l][l] = v[l];
  区间长度为2， 则dp[l][l + 1] = max(dp[l][l] + v[l + 1] * 2, dp[l+1][l+1] + v[l] * w);
  对于长度为k的区间，以任意一个零食作为最后吃的零食，
  其状态转移方程为
  // i是枚举出来的
  dp[l][r] = max(dp[l][i - 1] + (i - 1 - l + 1) * v[i], dp[i + 1][r] + (r - i + 1 + 1) * v[i]);


 */