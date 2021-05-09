#include<iostream>
#include<string>
using namespace std;
const int N = 256;
char S[N];
int top = 0;
// 进栈操作 push
void push(char a){
  // a要进栈，栈不满才能进栈
  if (top < N) 
    S[top++] = a;
}
// 出栈
void pop(){
  // 栈内有元素的时候才能出栈
  if (top > 0)
    S[--top] = 0;
}
// 获取栈顶元素
char get_top(){
  if (top > 0)
    return S[top-1];
  return -1;
}
bool isEmpty(){
  return top == 0;
}
// 判断栈中元素有多少个
int size(){
  return top;
}
int main(){
  string p;
  cin>>p;
  int i = 0;
  char t;
  bool flag = true;
  while(i < p.length()) {
    t = p[i];
    if (t == '(' || t == '[') {
      push(t);
    } else if (t == ')') {
      if (get_top() == '(') {
        pop();
      } else {
        flag = false;
        break;
      }
    } else if (t == ']') {
      if (get_top() == '[') {
        pop();
      } else {
        flag = false;
        break;
      }
    }
    
    i++;
  }
  if (flag && isEmpty())
    cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return 0;
}