#include<iostream>

using namespace std;
#define int long long
int n, m;
int dir[4][2] = {
  1, 0,
  0, 1,
  -1, 0,
  0, -1
};
int dp[255][255];
int arr[255][255];
int dfs(int x, int y) {
  if (dp[x][y]) return dp[x][y];
  dp[x][y] = 1;
  for (int i = 0;i < 4;i++) {
    int xx = x + dir[i][0],
        yy = y + dir[i][1];
    if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && arr[xx][yy] > arr[x][y]) {
      dp[x][y] = max(dp[x][y], dfs(xx, yy) + 1);
    }
  }
  return dp[x][y];
}
signed main() {
  cin >> n >> m;
  for (int i = 1;i <= n;i++) {
    for (int j = 1;j <= m;j++) {
      cin >> arr[i][j];
    }
  }
  int ans = 0;
  for (int i = 1;i <= n;i++) {
    for (int j = 1;j <= m;j++) {
      ans = max(ans, dfs(i, j));
    }
  }
  // for (int i = 1;i <= n;i++) {
  //   for (int j = 1;j <= m;j++) {
  //     cout << dp[i][j] << ' ';
  //   }
  //   cout << endl;
  // }
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