#include<iostream>
#include<string>
using namespace std;
string a, // 加密信息
       b, // 加密信息的原信息
       c; // 要求解密的信息
bool vis[26], visb[26];// vis[i] 代表字母i是否有对应的解密规则
char arr[26];// arr[i] 代表密字对应的原字
int main() {
  cin >> a >> b >> c;
  int lena = a.length();
  int lenc = c.length();
  int cnt = 0;
  for (int i = 0;i < lena;i++) {
    // 把密文a[i] 对应 其原文 b[i];
    if(!vis[a[i] - 'A'] && !visb[b[i] - 'A']) {
      arr[a[i] - 'A'] = b[i];
      visb[b[i] - 'A'] = 1;
      vis[a[i] - 'A'] = 1;
      cnt++;
    } else {
      if (arr[a[i] - 'A'] == b[i]) continue;
      else {
        cout << "Failed";
        return 0;
      }
    }
  }
  if (cnt < 26) {// 解密规则不够
    cout << "Failed";
    return 0;
  }
  // 把c解密
  string ans = "";
  for (int i = 0;i < lenc;i++) {
    if (!vis[c[i] - 'A']) {
      cout << "Failed";
      return 0;
    }
    ans += arr[c[i] - 'A'];
  }
  cout << ans;
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