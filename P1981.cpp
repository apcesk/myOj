#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
/**
 * 已知表达式只有 + 和 * 以及合法的数字
 * 又因为只需要输出后四位，则每一步的操作过后都 取余 10000
 */
// 数值栈
stack<long long> ns;
string s;
int main(){
  // freopen("P1981_2.in", "r", stdin);
  // freopen("P1981_2.out", "w", stdout);
  cin>>s;
  // cout<<s<<endl;
  long long number = 0;
  int i = 0;
  // 读入第一个数字
  for (;s[i] <= '9' && s[i] >= '0';i++) {
    number = number * 10 + (s[i]-'0');
    i++;
  }
  ns.push(number);
  number = 0;
  bool first = true;
  for (;i < s.length();++i) {
    if (s[i] == '+') {
      continue;
    } else if (s[i] == '*') { // 遇到乘号
      // 先把上一次的数字入栈
      ns.push(number % 10000);
      number = 0;
      i++;
      // 接下来找到下一个要入栈的数字
      while (s[i] <= '9' && s[i] >= '0') {
        number = number * 10 + (s[i]-'0');
        i++;
      }
      long long t = ns.top();
      ns.pop();
      ns.push(number % 10000 * t % 10000);
      number = 0;
      i--;
    } else if (s[i] <= '9' && s[i] >= '0') {
      number = number * 10 + (s[i]-'0');
      if (i == s.length() - 1) {
        ns.push(number);
      }
    }
  }
  long long sum = 0;
  while(!ns.empty()) {
    sum += ns.top();
    sum %= 10000;
    ns.pop();
  }
  printf("%lld\n", sum);
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}

