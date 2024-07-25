#include<iostream>
#include<string>
using namespace std;

int main() {
  string str;
  cin >> str;
  int len = str.length();
  bool flag = false;
  string temp = "";
  char c;
  cin >> c;
  temp += c;
  while (cin >> c) {
    if (c == 'o') break;
    if (c != '+' && c != '-' && c != '=') {
      temp += c;
    } else {
      cout << temp << endl;
      temp = "";
      temp += c;
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