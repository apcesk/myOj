#include<iostream>

using namespace std;
const int N = 101;
int S[N];
int top = 0;
void push(int a){
  if (top < N) S[top++] = a;
}
void pop(){
  --top;
}

int getTop(){
  return S[top-1];
}
// 清空栈
void clear() {
  top = 0;
}
// 判断栈是否为空
bool isEmpty(){
  return top == 0;
}
int arr[N];
int main(){
  // 给一个n
  int n;
  cin>>n;
  // 给一个序列,把给定的序列存放到数组中
  for (int i = 0;i < n;i++) {
    cin>>arr[i];
  }
  int j = 0;// j代表arr数组中当前要出栈的数字
  int i = 1;
  // 有了要输出的顺序，有了输入的数字，看根据输入的顺序是否能够得到指定的输出顺序
  while(1){
    // 一个数字进栈
    if (i <= n) push(i);
    while(getTop() != arr[j] && i <= n) push(++i);
    if (getTop() == arr[j]) {
      // cout<<"getTop(): "<<getTop()<<endl;
      pop();
      j++;
    } else {
      cout<<"NO!"<<endl;
      return 0;
    }
    i++;
  }
  cout<<"YES!"<<endl;
  return 0;
}