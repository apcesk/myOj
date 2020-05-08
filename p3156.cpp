#include<iostream>
#include<cstdio>
using namespace std;
int num[2000002];//存放学号
int main(){
    int n,m;
    //输入学生个数和询问次数
    scanf("%d %d", &n, &m);
    //输入学号
    for (int i = 1;i <= n;++i){
        scanf("%d", &num[i]);
    }
    for (int i = 1;i <= m;++i){
        //询问m次
        int t;
        scanf("%d", &t);
        printf("%d\n", num[t]);
    }

    return 0;
}