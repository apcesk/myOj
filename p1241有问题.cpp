#include<iostream>
#include<cstdio>
#include<stack>

using namespace std;
stack<char> s;//创建一个存放字符的栈s，用来检测是否是合理表达式
stack<char> out;//创建一个存放字符的栈s，用来存放已经合理的表达式
int main(){
    char tmp;
    while (cin>>tmp && tmp != '\n'){//这里解决所有的右括号错误匹配
        //第一步，所有的字符入栈
        if (tmp == '(' || tmp == '['){
            s.push(tmp);
        }else{
            char top = s.top();
            if (top == '(' && tmp == ')' || top == '[' && tmp == ']'){
                //括号匹配则直接入栈
                s.push(tmp);
            }else{//括号不匹配，则优先补充当前括号需要的值
                if (tmp == ']'){
                    s.push('[');
                }else{
                    s.push('(');
                }
                s.push(tmp);
            }
        }
    }
    //将栈s的内容存到out栈中，并且处理没有匹配的左括号
    while(!s.empty()){
        char s_top = s.top();
        if (s_top == ']' || s_top == ')'){
            out.push(s_top);
            s.pop();
        }else if (s_top == '(' || s_top == '['){
            if (s_top == '('){
                out.push(')');
            }else if (s_top == '['){
                out.push(']');
            }
            out.push(s_top);
            s.pop();
        }
    }
    //出栈输出
    while (!out.empty()){
        printf("%c", out.top());
        out.pop();
    }
    return 0;
}