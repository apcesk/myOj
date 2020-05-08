#include<iostream>
#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;
stack <int> s;//创建一个栈s
int a[100001];//存放入栈顺序的数组
int b[100001];//存放出栈顺序的数组
int main(){
    
    int q;//询问次数
    scanf("%d", &q);//输入q的值
    while (q > 0){//询问q次
        
        int s_len;//每个序列的长度
        scanf("%d", &s_len);
        memset(a, 0, sizeof(int) * s_len);
        int tmp;
        for (int i = 1;i <= s_len;++i){
            scanf("%d", &a[i]);//入栈的顺序保存下来
        }
        for (int i = 1;i <= s_len;++i){
            scanf("%d", &b[i]);//出栈的顺序保存下来
        }
        int b_now = 1;
        //所有元素入栈之后，开始检验出栈
        for (int i = 1;i <= s_len;++i){
            s.push(a[i]);//入栈
            while (s.top() == b[b_now]){//栈顶元素和出栈元素相同
                //出栈
                s.pop();
                b_now++;
                if(s.empty()) break;
            }
            
        }
        if (s.empty()){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
        while(!s.empty())s.pop();
        q--;
    }
    return 0;
}