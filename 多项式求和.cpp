#include<iostream>
#include<cmath> // 由于要使用pow函数，所以要引入这个库
using namespace std;

int main() {

  double x;
  int n;
  cin >> x >> n;
  double sum = 0;
  // 题目要求从x的n次方一直加到x的0次方，也就是1
  // 也就是说我们至少要执行n次循环，每次求出x的当前循环层数的次方的结果
  for (int i = 0;i <= n;i++) {
    // pow(x, n)，相当于求x的n次方
    // 小知识，非0的数的0次方都等于1
    sum += pow(x, n);
  }
  cout << sum << endl;
  return 0;
}