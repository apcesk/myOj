#include<iostream>
using namespace std;

int main(){
  // 输入ISBN码  ---  用什么存？ 10个数字+3个杠 = 13个
  // 字符存到数组中去
  char ISBN[14];
  // 要把前九个数字计算的结果存入到sum中
  int sum = 0;
  // 声明ISBN要乘以的数字 + 1 + 1 = 2;
  // 现在+ 用 ～   1 ~ 1 = 2;
  // 1 ~ 1
  int k = 1;
  // 把前9个数字分别取出来乘以一个数字
  for (int i = 1;i <= 13;i++) {
    // 输入了一个字符
    cin>>ISBN[i];
    if (ISBN[i] != '-' && i != 13) {
      sum = sum + (ISBN[i] - '0') * k;
      k++;
    }
  }
  // 如果 if 否则 else 每一个循环。输入
  // cin
  // 输出cout
  // 如果sum % 11 == (ISBN - '0') || sum % 11 == 10 && ISBN = 'X'
  if (sum % 11 == (ISBN[13] - '0') || (sum % 11 == 10 && ISBN[13] == 'X')) {
    cout<<"Right"<<endl;
  } else {
    for (int i = 1;i <= 12;i++) {
      cout<<ISBN[i];
    }
    if (sum % 11 < 10) {
      cout<<sum%11;
    } else {
      cout<<'X';
    }
  }

  return 0;
}