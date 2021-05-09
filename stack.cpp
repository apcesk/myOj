#include<iostream>

using namespace std;
// 宏定义 定一个常量N代表100
#define N 100

// 创建一个长度为N的数组S来模拟栈
int S[N];
// 创建栈顶指针，指向当前要进栈元素的下标
int top = 0;
// 进栈操作 push
void push(int a){
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
int getTop(){
  if (top > 0)
    return S[top-1];
  return -1;
}
// 栈的特点，一端进出。
// 有一个栈顶指针，永远指向栈顶

int main() {
  // 进栈，出栈，获取栈顶元素
  int a;
  while(cin>>a) {
    cout<<"进栈之前 -> top: "<<top<<endl;
    push(a);
    cout<<"进栈之后 -> top: "<<top<<endl;
    cout<<getTop()<<endl;
    pop();
    cout<<"出栈之后 -> top: "<<top<<endl;
  }
  return 0;
}