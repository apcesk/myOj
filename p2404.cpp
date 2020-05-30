#include<iostream>
#include<cstdio>
using namespace std;

int n;// 输入要被拆分的数字
int arr[10];// 存放分解的数字
int ptr = 1;// arr数组中数字存放的位置的指针
void outNum();// 输出数字
void dfs(int num, int start){// num代表要被拆分的自然数
    // 如果当前这个自然数已经为0了，说明拆分完毕
    if (num == 0){
        // 输出存放在数组中的数字
        outNum();
        return;
    }
    // 递归将该数字拆分。
    for (int i = start;i <= num;++i){
        if (num - i >= 0){
            // 能够被拆分，则将这个数字存储起来
            arr[ptr++] = i;
            // 对应的num减去相应的数字
            num -= i;
            // 继续对num进行拆分
            dfs(num, i);
            // 回溯阶段将已经存放的数字进行清0
            arr[ptr--] = 0;
            // 回溯阶段数字返回原样，测试下一种组合。
            num += i;
        }
    }
}

int main(){
    scanf("%d", &n);
    dfs(n, 1);
    return 0;
}
void outNum(){
    // 不输出本身
    if (arr[1] == n) return;
    // 先输出第一个数字，方便后面的格式
    printf("%d", arr[1]);
    for (int i = 2;i <= ptr && arr[i] != 0;++i){
        printf("+%d", arr[i]);
    }
    printf("\n");
}