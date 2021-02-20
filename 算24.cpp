#include<iostream>
#include<cmath>
using namespace std;

int ans = 0;
/**
 * @param {double[]} a 存放要算24的几个数字
 * @param {int} n 数组中还剩几个数字
 */
void Counting24(double a[], int n) {
  int i, j, x, y, k, m;
  double b[4];
  // 如果试到最后一个数，并且结果为24，则结束计算。
  if (n == 1 && a[0] > 0 && fabs(a[0] - 24) < 0.0001) ans = 1;
  else if (n > 1) {
    for (i = 0;i < n;i++) { // 否则选出数组中的两个数a[i]和a[j]进行计算
      for (j = 0;j < n;j++) {
        if (i == j) continue;
        for (m = k = 0;k < n;k++) { // 把剩下的数，放入数组b
          if (k != i && k != j) {
            b[m] = a[k];
            m++;
          }
        }
        b[m] = a[i] + a[j];
        Counting24(b, m+1);
        b[m] = a[i] - a[j];
        Counting24(b, m+1);
        b[m] = a[i] * a[j];
        Counting24(b, m+1);
        if (a[j] != 0) b[m] = a[i] / a[j];
        Counting24(b, m+1);

      }
    }
  }
}

int main() {
  double a[4];
  while (cin>>a[0]>>a[1]>>a[2]>>a[3] && (a[0] + a[1] + a[2] + a[3] != 0)) {
    ans = 0;
    Counting24(a, 4);
    if (ans) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
  return 0;
}

