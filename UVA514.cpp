#include<iostream>
using namespace std;
/**
 * 使用自己定义的栈模板
*/
// 栈
int stack[1001];
// 栈顶指针
int top = 0;
// 进栈
void push(int ele){
  // cout<<"in->stack: "<<ele<<endl;
  stack[top++] = ele;
}
// 出栈
void pop(){
  // cout<<"out->stack: "<<stack[top-1]<<endl;
  stack[top-1] != 0 && top--;
  // cout<<"stack->top: "<<top<<endl;
}
// 获取栈顶元素
int get_top(){
  return stack[top-1];
}
// 检测栈是否为空
bool is_empty(){
  return (top == 0);
}
// 清空栈
void clear_stack(){
  top = 0;
}
int main(){
  // n节车厢
  int n;
  // 输入n
  cin>>n;
  // 记录已经出栈的元素个数
  int i = 0;
  // 记录当前入栈的数字
  int r = 1;
  // 记录当前要出栈的元素
  int t;
  while (1) {
    // 输入要出栈的元素
    cin>>t;
    // 如果t不等于0，但是i等于n，则说明这是第二轮的出栈顺序匹配了
    if(t != 0 && i == n) {
      i = 0;
      r = 1;
      clear_stack();
    }
    // 如果t=0，则说明要输入新的序列了
    if (t == 0) {
      // cout<<"t is 0"<<endl;
      cin>>n;
      if (n == 0) return 0;
      i = 0;
      r = 1;
    }
    
    // 出栈顺序的判别
    while (r <= n && t != 0) {
      // 如果栈顶元素等于t，则栈顶元素出栈
      if (get_top() == t) {
        pop();
        break;
      }
      push(r);
      r++;
    }
    // 如果栈顶元素等于t，则栈顶元素出栈
    if (get_top() == t) {
      pop();
    }
    t != 0 && ++i;
    // cout<<"i is "<<i<<endl;
    // cout<<"is_empty(): "<<is_empty()<<endl;
    // 如果所有的元素都入过栈，并且栈为空，则说明出栈顺序是正确的。
    if (i == n && is_empty()) {
      cout<<"YES"<<endl;
      clear_stack();
    }
    // 如果所有的t都输入过，且栈不为空
    if (i == n && !is_empty()) {
      cout<<"NO"<<endl;
      clear_stack();
    }
  }
  return 0;
}