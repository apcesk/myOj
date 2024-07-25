#include<iostream>
#include<cstring>
using namespace std;
/**
 * 用自己最小的形态，和其它所有最大的形态去比较即可
 */
int n, m;
char c[3030];
int min_arr[3030], max_arr[3030];
int main() {
  cin >> n >> m;
  for (int i = 1;i <= n;i++) {
    cin >> c;
    // 构造序列
    for (int j = 0;j < m;j++) {
      if (j == 0)
        max_arr[i] = min_arr[i] = c[j] - 'a';
      else {
        min_arr[i] = min(min_arr[i], c[j] - 'a');
        max_arr[i] = max(max_arr[i], c[j] - 'a');
      }
    }
  }
  bool flag = true;
  for (int i = 1;i <= n;i++) {
    flag = true;
    for (int j = 1;j <= n;j++) {
      if (i == j) continue;// 不和自己比
      if (min_arr[i] < max_arr[j]) continue;
      else {
        flag = false;
        cout << 0;
        break;
      }
    }
    if (flag) cout << 1;
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