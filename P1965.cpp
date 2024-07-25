#include<iostream>

using namespace std;
/*
  n个小伙伴坐一起玩游戏。编号为0到n-1
  每一轮，当前位置的人走到其位置+m的位置上。注意是围成一圈
  现在经过了10^k 轮，问x号的小伙伴最后走到了哪个位置
  -------
  思考：
    由于每次向后走m个，
    那么走lcm(n,m)轮的时候，x一定会回到自己原来的位置上
  ----
    确定一下x最终的位置
    (x + m * 10^k) % n即可
*/
#define int long long
int n, m, k, x;
int fastmi(int a, int b, int mod) {
  int res = 1;
  while(b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
signed main() {
  cin >> n >> m >> k >> x;
  cout << (x + m * fastmi(10, k, n) % n) % n;
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