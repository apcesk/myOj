#include<iostream>

using namespace std;
char s[65536];
int n;
void f(int idx, int left, int right) {
  if (left > n / 2 || right > n / 2) {
    return;
  }
  if (idx == n) {
    cout << s << endl;
    return;
  }
  if (left < n / 2) {// 加个做括号
    s[idx] = '(';
    f(idx + 1, left + 1, right);
  } 
  if (right < left) {
    s[idx] = ')';
    f(idx + 1, left, right + 1);
  }
}
int main() {
  cin >> n;// 生成长度为n的括号序列
  f(0, 0, 0);
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