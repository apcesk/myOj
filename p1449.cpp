#include<iostream>
#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;
stack<int> s;//创建一个int 类型的栈
int compute(char c){//计算方法
    int a,b;
    a = s.top();
    s.pop();
    b = s.top();
    s.pop();
    switch (c){
        case '*':
            return a * b;
        case '-':
            return b - a;
        case '+':
            return a + b;
        case '/':
            return b / a;
    }
}
char c[1001];
int main(){
    cin >> c;
    int len = strlen(c);
    int i = 0;
    int tmp = 0;
    while(i < len){
        if (c[i] >= '0' && c[i] <= '9'){
            tmp = tmp * 10 + c[i] - '0';
        }else if (c[i] == '.'){
            s.push(tmp);//将数字入栈
            tmp = 0;
            i++;
            continue;
        }else if (c[i] != '@'){
            //要计算
            int res = compute(c[i]);
            s.push(res);
        }
        i++;
    }
    cout<<s.top();
    return 0;
}