#include<iostream>
#include<stack>
using namespace std;
stack<int> s;
int main(){
  int n;
  cin>>n;
  int i = 0;
  int r = 1;
  int t;
  while (1) {
    cin>>t;
    if(t != 0 && i == n) {
      i = 0;
      r = 1;
      while(!s.empty()) s.pop();
    }
    if (t == 0) {
      cin>>n;
      if (n == 0) return 0;
      i = 0;
      r = 1;
    }
    while (r <= n && t != 0) {
      if (!s.empty() && s.top() == t) {
        s.pop();
        break;
      }
      s.push(r);
      r++;
    }
    if (t != 0 && s.top() == t) {
      s.pop();
    }
    t != 0 && ++i;
    if (i == n && s.empty()) {
      cout<<"YES"<<endl;
    }
    if (i == n && !s.empty()) {
      cout<<"NO"<<endl;
      while(!s.empty()) s.pop();
    }
  }
  return 0;
}