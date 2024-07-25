#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n, arr[110], dp[25500];
/*
  关键：用尽可能原有的数字，表示其中某些个数字。
 */
int main() {
  int t;
  cin >> t;
  while(t--) {
    cin >> n;
    for (int i = 1;i <= n;i++) {
      cin >> arr[i];
    }
    sort(arr + 1, arr + 1 + n);
    memset(dp, 0, sizeof dp);
    dp[0] = 1;
    int ans = n;
    for (int i = 1;i <= n;i++) {
      if (dp[arr[i]]) {
        ans--;
        continue;
      }
      for (int j = arr[i];j <= arr[n];j++) {
        dp[j] = dp[j] | dp[j - arr[i]];
      }
    }
    cout << ans << endl;
  }
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