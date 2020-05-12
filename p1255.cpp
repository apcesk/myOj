#include<iostream>
#include<cstdio>
using namespace std;
// 数据范围比较大的一个上楼梯，
// 说白了就是 斐波那契 + 高精度加法
int n, upstair[5001][5001];// n级台阶，upstair[i][j]代表从上到i级台阶需要走的步数
int len = 1;//保存当前台阶的数字长度，用来做高精度数
void fib(int t){// t代表要上到的台阶数
    for (int i = 1;i <= len;++i){
        // 注意这里是高精度数的对位相加
        upstair[t][i] =  upstair[t-1][i] + upstair[t-2][i];
    }
    // 处理高精度数
    for (int i = 1;i <= len;++i){
        if (upstair[t][i] >= 10){
            // 下一位进行进位
            upstair[t][i+1] += upstair[t][i] / 10;
            // 当前位保留个位
            upstair[t][i] = upstair[t][i] % 10;
            // 如果有导致首位进位
            if (upstair[t][len+1]) len++;
        }
    }
}
int main(){
    scanf("%d", &n);
    upstair[1][1] = 1, upstair[2][1] = 2;
    for (int i = 3;i <= n;++i){
        fib(i);
    }
    // 输出答案
    for (int i = len;i >= 1;--i){
        // 记得输出的时候要逆序！！！！
        printf("%d", upstair[n][i]);
    }
    return 0;
}