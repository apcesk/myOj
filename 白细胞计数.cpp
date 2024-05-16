#include<iostream>
#include<cmath>
using namespace std;

int main() {
  // 有一个数组长度是n
  double arr[301];
  // 输入数据
  int n;
  cin >> n;
  double maxn = 0, minn = 1e10;
  double sum = 0;
  for (int i = 0;i < n;i++) {
    cin >> arr[i];
    // 把最大值和最小值，记录
    if (arr[i] > maxn) {
      maxn = arr[i];
    }  
    if (arr[i] < minn) {
      minn = arr[i];
    }
    sum += arr[i];
  }
  sum -= maxn;
  sum -= minn;
  double average = sum / (n-2);
  double abs_max = 0;
  for (int i = 0;i < n;i++) {
    if (arr[i] == maxn) {
      maxn = -1;
      continue;
    }
    if (arr[i] == minn) {
      minn = -1;
      continue;
    }
    if (abs(average - arr[i]) > abs_max) {
      abs_max = abs(average - arr[i]);
    }
  }
  printf("%.2lf %.2lf", average, abs_max);
    // 把最大值和最小值，去掉。

  // 求平均数

  // 求每个数据和平均数差值的最大值

  // 输出平均数，输出和平均数差值的最大值是多少

  return 0;
}