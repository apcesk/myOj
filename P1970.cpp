#include<iostream>

using namespace std;
#define int long long
const int N = 1e5 + 10;
int n;
// dp1上升序列，dp2下降序列
int h[N], dp1[N], dp2[N];
signed main() {
  cin >> n;
  for (int i = 1;i <= n;i++) 
    cin >> h[i];// 输入每朵花的高度
  dp1[1] = dp2[1] = 1;
  for (int i = 2;i <= n;i++) {
    if (h[i] > h[i - 1]) {// 当前的比前一个大，能够形成上升序列
      dp1[i] = max(dp1[i - 1], dp2[i - 1] + 1), dp2[i] = dp2[i - 1];
    } else {// 当前的比前一个小
      if (h[i] < h[i - 1]) dp1[i] = dp1[i - 1], dp2[i] = max(dp1[i - 1] + 1, dp2[i - 1]);
      else dp1[i] = dp1[i - 1], dp2[i] = dp2[i - 1];// 相等
    }
  }
  cout << max(dp1[n], dp2[n]);
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