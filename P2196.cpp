#include<iostream>

using namespace std;
int n;// n个地窖
int arr[25];// arr[i] = k代表第i个地窖中有多少雷
bool G[25][25];// 图
int dp[25], path[25];
void output(int idx) {
  if (idx) {
    output(path[idx]);
    cout << idx << ' ';
  }
  
}
int main() {
  cin >> n;
  for (int i = 1;i <= n;i++) cin >> arr[i];
  for (int i = 1;i < n;i++) {
    for (int j = i + 1;j <= n;j++) {
      cin >> G[i][j];
    }
  }
  int maxn = 0, maxn_idx = 0;
  for (int i = 1;i <= n;i++) {
    dp[i] = arr[i];
    for (int j = 1;j < i;j++) {
      if (G[i][j] || G[j][i]) {
        if (dp[j] + arr[i] > dp[i]) {
          dp[i] = dp[j] + arr[i];
          path[i] = j;
        }
      }
    }
    if (dp[i] > maxn) {
      maxn = dp[i];
      maxn_idx = i;
    }
  }
  output(maxn_idx);
  cout << endl;
  cout << maxn << endl;
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