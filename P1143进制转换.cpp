#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
// 进制转换
int n;// 数字的进制
char s[20];// 数字的值
int m; // 要转换的进制
// 对应16进制的字母转数字
int change16_10(char a) {
  switch (a)
  {
    case 'A':
      return 10;
    case 'B':
      return 11;
    case 'C':
      return 12;
    case 'D':
      return 13;
    case 'E':
      return 14;
    case 'F':
      return 15;
  }
  return -1;
}
char out_arr[20];
int main() {
  cin>>n>>s>>m;
  // 把n转换成为10进制的值
  int len = strlen(s);
  int sum = 0;
  for (int i = len-1;i >= 0;i--) {
    if (s[i] >= '0' && s[i] <= '9') {
      // cout<<"number"<<endl;
      sum += (s[i] - '0') * pow(n, (len-1-i) * 1.0);                                                                                  
    } else {
      // cout<<"char"<<endl;
      sum += change16_10(s[i]) * pow(n, (len-1-i) * 1.0);
    }
  }
  // cout<<sum;
  int i = 0;
  while (sum != 0) {
    int t = sum % m;
    if (t <= 9) {
      out_arr[i] = t + '0';
    } else {
      char p;
      switch (t)
      {
        case 10:
          p = 'A';
          break;
        case 11:
          p = 'B';
          break;
        case 12:
          p = 'C';
          break;
        case 13:
          p = 'D';
          break;
        case 14:
          p = 'E';
          break;
        case 15:
          p = 'F';
          break;
        default:
          break;
      }
      out_arr[i] = p;
    }
    i++;
    sum /= m;
  }
  len = strlen(out_arr);
  for (int i = len -1 ;i >= 0;i--) {
    cout<<out_arr[i];
  }
  cout<<endl;
  // cout<<n<<endl<<s<<endl<<m;
  return 0;
}