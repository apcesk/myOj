#include<iostream>
#include<string>
#include<cctype>
using namespace std;
string a, b;// a是密钥，b是密文
// 输出其加密前的样子
char to_upper(char c) {
  if (c <= 'Z' && c >= 'A') return c;
  else return (char)(c - 32);
}
int main() {
  cin >> a >> b;
  int lena = a.length();
  int lenb = b.length();
  int tot = lena;
  string k = a;
  while (tot < lenb) {
    k += a;
    tot += lena;
  }
  // 此时密钥不比密文短
  for (int i = 0;i < lenb;i++) {
    if (b[i] <= 'Z') {
      cout << (char)(((b[i] - 'A' - (to_upper(k[i]) - 'A') + 26) % 26) + 'A');
    } else if (b[i] >= 'a') {
      cout << (char)(((b[i] - 'a' - (to_upper(k[i]) - 'A') + 26) % 26) + 'a');
    }
  }
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