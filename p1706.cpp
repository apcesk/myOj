#include<iostream>
#include<cstdio>
using namespace std;
// n个数字，1-n，n<=9
int n;
bool num[10];//标记每个数字是否用过
int outNum[10];//存储输出的数字
//输出
void outPut(){//当前是第t个格子
    for (int i = 0;i < n;++i){
        printf("%5d", outNum[i]);
    }
    printf("\n");
}
//递归处理全排列问题
void dfs(int t){
    if (t == n){
        //如果已经摆放了n个数字，则输出
        outPut();
        return;
    }
    for (int i = 1;i <= n;++i){
        if (!num[i]){//如果当前这个格子没用过
            outNum[t] = i;
            num[i] = 1;
            dfs(t+1);//递归查找下一个格子
            //回溯时
            outNum[t] = 0;
            num[i] = 0;
        }
    }
}
int main(){
    //全排列问题
    scanf("%d", &n);
    dfs(0);
    return 0;
}