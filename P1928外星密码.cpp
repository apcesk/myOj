#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

char c;
string read(){
  string s = "";
  while (cin>>c) {
    if (c == '[') {
      int t;
      cin>>t;
      string tmp="";
      tmp = read();
      while (t--) s += tmp;
    } else {
      if (c == ']') return s;
      else s += c;
    }
  }
}

int main() {
  cout<<read()<<endl;
  return 0;
}