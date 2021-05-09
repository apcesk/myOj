#include<iostream>
#include<cstring>
using namespace std;
// 单向进出的叫栈？
// 究竟有什么用
// 递归：程序调用本身
// 怎么去实现一个栈
// 操作有几种： 进，出，空，顶是谁。下一个要进到哪里
// 实现栈 -> 能装多个东西的。数组
// 先考虑进和出
// 栈的进出，有序进出，要给它一个顺序，下一个来的元素要进到“数组”的哪个位置
#define STACK_KONG 0
#define STACK_SIZE 100
#define STACK_CHUSHI 1
#define STACK_TYPE int
STACK_TYPE s[STACK_SIZE];
// 需要一个指针，指针的意义为下一个元素要入栈的位置
int top = STACK_CHUSHI;
// 判断是否满
bool isFull() {
  return top == STACK_SIZE;
}
void push(int a) {
  if (!isFull()) {// 栈是否满了
    // 进栈
    s[top] = a;
    top++;
  }
}
// 判断是否为空
bool isEmpty() {
  return top == STACK_CHUSHI;
}
// 出栈
void pop() {
  if (!isEmpty()) {// 判断是否不为空
    s[top-1] = STACK_KONG;
    top--;
  }
}


// 看看顶上是谁
STACK_TYPE getTop(){
  if (!isEmpty())
    return s[top-1];
  else
    return STACK_KONG;
}
char arr[2000];
int main(){
  cin>>arr;
  int t = 0;
  // 遍历整个字符串
  for (int i = 0;i < strlen(arr);i++) {
    if (arr[i] >= '0' && arr[i] <= '9') {
      t = t * 10 + arr[i] - '0';// 计算应当录入数字的值
    } else if (arr[i] == '.') {
      push(t);// 数字录入结束
      // cout<<"T"<<t<<endl;
      t = 0;
    } else if (arr[i] == '@') {// 计算结束
      cout<<getTop()<<endl;
      break;
    } else {
      int a,b,c;
      a = getTop();// 拿最上面的
      pop();// 最上面的出去
      b = getTop();// 再拿最上面
      pop();// 最上面的再出去
      switch (arr[i])
      {
        case '+':
          c = b + a;
          break;
        case '-':
          c = b - a;
          break;
        case '*':
          c = b * a;
          break;
        case '/':
          c = b / a;
          break;
      }
      push(c);// 将计算结果放进来
      // cout<<"C"<<c<<endl;
    }
  }
  return 0;
}
