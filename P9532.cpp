#include<iostream>

using namespace std;
const int N = 5e3 + 5, INF = 0x3f3f3f3f;
int dp[N][N];
int n, h[N];
int main() {

  cin >> n;
  for (int i = 1;i <= n;i++) {
    cin >> h[i];
  }
  cout << 0 << ' ';
  for (int L = 2;L <= n;L++) {
    int ans = INF;
    for (int l = 1;l + L - 1 <= n;l++) {
      int r = l + L - 1;
      dp[l][r] = dp[l + 1][r - 1] + abs(h[l] - h[r]);
      ans = min(ans, dp[l][r]);
    }
    cout << ans << ' ';
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