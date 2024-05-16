#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;
int main() {
  // 求b个a相乘，的末尾三位数
  int a, b, sum = 1;
  cin >> a >> b;
  // 计算逻辑如下
  for (int i = 1; i <= b; i++) {
    // 注意，末尾的三位数，只和末尾三位数乘法相关
    // 如果不考虑这样的话，会超过int类型的数字存储上限。
    sum = sum * a;
    sum = sum % 1000;
  }

  // 输出结果。
  if (sum < 100)
    // 这里是类似.2lf类似的规则，相当于用0进行补位，输出三位数
    printf("%03d", sum);
  else
    printf("%d", sum);
  return 0;
}