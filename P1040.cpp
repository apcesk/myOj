#include<iostream>

using namespace std;
#define int long long
int n;
int arr[35];
int dp[35][35];
int root[35][35];
void pre_order(int l, int r) {
  if (l <= r)
    cout << root[l][r] << ' ';
  if (l < r) {
    pre_order(l, root[l][r] - 1);
    pre_order(root[l][r] + 1, r);
  }
}
signed main() {
  cin >> n;
  for (int i = 1;i <= n;i++) cin >> arr[i];
  for (int i = 1;i <= n;i++) {
    dp[i][i] = arr[i];
    dp[i][i - 1] = 1;
    root[i][i] = i;
  }
  for (int len = 2;len <= n;len++) {
    for (int i = 1;i + len - 1 <= n;i++) {
      int j = i + len - 1;
      dp[i][j] = dp[i + 1][j] + dp[i][i];// 选左端点为根
      root[i][j] = j;
      for (int k = i + 1;k < j;k++) {
        if(dp[i][k - 1] * dp[k + 1][j] + dp[k][k] > dp[i][j]) {
          root[i][j] = k;
          dp[i][j] =  dp[i][k - 1] * dp[k + 1][j] + dp[k][k];
        }
      }
    }
  }
  cout << dp[1][n] << endl;
  pre_order(1, n);
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