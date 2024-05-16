#include<iostream>

using namespace std;

int main() {
  // 一个4位数，个位上的数字大于其它位置上的数字和。
  int n;
  cin >> n;
  int count = 0;// 满足条件数字的个数
  for (int i = 1;i <= n;i++) {
    int number;
    cin >> number;
    // a4个位数字
    int a4, sum = 0;
    a4 = number % 10; // 得到个位数
    number /= 10;// 缩小十倍，此时的个位数就是原来的百位数
    while (number != 0) {// 当number不位0的时候，则不断的取其个位并进行加和
      sum += number % 10; // 取出当前的个位。并加入到sum中
      number /= 10; // number缩小10
    }
    // 如果满足条件
    if (a4 > sum) {
      count++;
    }

  }
  cout << count << endl;
  return 0;
}