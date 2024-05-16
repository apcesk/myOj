#include<iostream>
#include<cmath>
using namespace std;
int get_max(int n) {
  int t = -1;
  while (n != 0) {
    if (n % 10 > t) {
      t = n % 10;
    }
    t /= 10;
  }
}
// 确定pqr三个数中最大的数字
int get_max_num(int p, int q, int r) {
  int maxn = max(get_max(p), get_max(q), get_max(r));
  return maxn <= 1 ? 2 : maxn+1;
}
int get_number_equal(int number, int i){
  int n = 0;
  // 返回number的i进制对应10进制的值
  int t = 0;// 初始是0次方
  while (number != 0) {
    n += number % 10 * pow(i, t);
    t++;
    number /= 10;
  }
  return n;
}
bool check_eval(int p, int q, int r, int i) {
  int temp_p = get_number_equal(p, i), 
  temp_q = get_number_equal(q, i), 
  temp_r = get_number_equal(r, i);
  // 检查是否正确
  return temp_p * temp_q == temp_r ? true : false;
}
// 任意个非10进制数转化成为10进制的算法
// 110  = 0 * 2^0 + 1 * 2^1 + 1 * 2^2
int main() {
  int p,q,r;
  // 3 * 4 = 12 // 一定是5以上的进制
  cin >> p >> q >> r;
  // 确定从2-16进制的情况下，查看有没有一种使得
  // p * q = r;
  // 要从2进制判断到16
  for (int i = get_max_num(p,q,r);i <= 16;i++) {
    if (check_eval(p, q, r, i)) {
      // 检查p * q = r 在 i进制的前提下，是否成立
      cout << i << endl;
      return 0;
    }
  }
  cout << 0 << endl;
  return 0;
}