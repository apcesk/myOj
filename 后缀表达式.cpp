#include<iostream>
#include<string>
using namespace std;
const int N = 256;
int S[N];
int top = 0;
void push(int a){
  if (top < N) 
    S[top++] = a;
}
void pop(){
  if (top > 0)
    S[--top] = 0;
}
int get_top(){
  if (top > 0)
    return S[top-1];
  return -1;
}
bool isEmpty(){
  return top == 0;
}
int size(){
  return top;
}
int chuli(char fuhao) {
  int a = get_top();pop();
  int b = get_top();pop();
  switch (fuhao)
  {
    case '+':
      return a + b;
    case '-':
      return b - a;
    case '*':
      return b * a;
    case '/':
      return b / a;
    default:
      return -1;
  }
}
int main(){
  char t;
  while (1) {
    cin>>t;
    if (t >= '0' && t <= '9') push(t-'0');
    else if (t == '@') break;
    else {
      push(chuli(t));
    }
  }
  cout<<get_top()<<endl;
  return 0;
}