#include<iostream>

using namespace std;
int n;
int arr[250];
int dp[250][250];
int main() {
  cin >> n;
  int ans = 0;
  for (int i = 1;i <= n;i++) {
    cin >> arr[i];
    dp[i][i] = arr[i];
    ans = max(ans, arr[i]);
    if (i > 1) {
      dp[i - 1][i] = arr[i] == arr[i - 1] ? arr[i] + 1 : 0;
      ans = max(ans, dp[i - 1][i]);
    }
  }
  for (int len = 3;len <= n;len++) {
    for (int i = 1;i <= n - len + 1;i++) {
      int j = i + len - 1;
      // 枚举断点
      for (int k = i;k < j;k++) {
        if (dp[i][k] == dp[k + 1][j] && dp[i][k] != 0) {
          dp[i][j] = max(dp[i][j], dp[i][k] + 1);
          ans = max(ans, dp[i][j]);
        }
      }
    }
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