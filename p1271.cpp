#include<cstdio>
#include<iostream>
using namespace std;
int stu[1000];//n<=999
int main(){
    int n,m;
    scanf("%d %d", &n, &m);//输入n个学生，m张票数
    int ticket;
    for (int i = 1;i <= m;++i){
        scanf("%d", &ticket);
        stu[ticket]++;
    }
    //输出
    for (int i = 1;i <= n;++i){
        while(stu[i]--){
            printf("%d ", i);
        }
    }
    return 0;
}