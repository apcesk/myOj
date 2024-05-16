#include<iostream>
#include<cmath>
using namespace std;

int get_num(int number) {
  int sum = 0;
  // 求number的因子之和
  for (int i = 1;i <= number/2;i++) {
    if (number % i == 0) {
      sum += i;
    }
  }
  return sum;
}

int re(int number) {
  // 把number倒过来
  int temp = 0;
  while (number != 0) {
    temp = temp * 10 + number % 10;
    number /= 10;
  }
  return temp;
}

bool is_prime(int number) {
  // 判断number是不是素数
  for (int i = 2;i < number;i++) {
    if (number % i == 0) {
      return false;
    }
  }
  return true;
}
bool is_abs_prime(int number) {
  return is_prime(number) && is_prime(re(number));
}
//
int get_yinzi(int number) {
  int sum = 0;
  // 获取number的因子之和
  for (int i = 1;i <= number/2;i++) {
    sum += number % i == 0 ? i : 0;
  }
  return sum;
}

double get_money(int total_count) {
  int temp = total_count / 70;// 有多少个70
  return (temp * 70 == total_count ? temp : (temp + 1)) * 0.1;
}
// 把逻辑分层次，也是分段处理
int main() {
  double sum = 0;
  int n;
  cin >> n;
  int total_count;
  for (int i = 1;i <= n;i++) {
    cin >> total_count;
    sum += get_money(total_count);
    // --
    // --
    // --
  }
  printf("%.1lf\n", sum);
  
  return 0;
}