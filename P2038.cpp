#include<iostream>

using namespace std;
#define int long long 

int d;// 传播距离
int n;// 有n个具有公共场所的数量
int arr[130][130];// 地图
// 暴力枚举
signed main() {
  cin >> d >> n;
  // cout << d << ' ' << n << endl;
  for (int i = 1;i <= n;i++) {
    // cout << i << endl;
    int x, y, k;
    cin >> x >> y >> k;
    arr[x + 1][y + 1] = k;
  }
  int ans = 0, cnt = 0;
  for (int i = 1;i <= 129;i++) {
    for (int j = 1;j <= 129;j++) {
      int temp = 0;
      for (int x = max(1ll, i - d);x <= min(i + d, 129ll);x++) {
        for (int y = max(1ll, j - d);y <= min(j + d, 129ll);y++) {
          temp += arr[x][y];
        }
      }
      if (temp > ans) {
        ans = temp;
        cnt = 1;
      } else if (temp == ans) {
        cnt++;
      }
    }
  }
  cout << cnt << ' ' << ans;
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