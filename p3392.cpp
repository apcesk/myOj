#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
#define MAX_LINE 51
// 创建三个数组，代表要染色的行数
// 第一行-第i行是白色(w)
// 第i+1行到第j行是蓝色(b)
// 第j+1行到第n行是红色(r)
int w[MAX_LINE],b[MAX_LINE],r[MAX_LINE];
int n,m;//n行m列
string s;
int daubBlockInline(char c){//查询当前这一行需要涂多少个
    int total = 0;
    for (int i = 0;i < m;++i){
        // 如果当前行中的块不等于所要涂的颜色，则让当前行需要的涂抹砖块数+1
        if (s[i] != c) total++;
    }
    //将本行需要染成c色的砖块数返回出去
    return total;
}
int ans = 0x7777777;//存储答案
int main(){
    //输入n和m
    cin>>n>>m;
    for (int i = 1;i <= n;++i){
        cin>>s;
        // 涂到当前行都为白色(w)所需要的涂抹的砖块总数
        w[i] = w[i-1] + daubBlockInline('W');
        // 涂到当前行都为蓝色(b)所需要的涂抹的砖块总数
        b[i] = b[i-1] + daubBlockInline('B');
        // 涂到当前行都为红色(r)所需要的涂抹的砖块总数
        r[i] = r[i-1] + daubBlockInline('R');
    }
    //求出最小答案
    for (int i = 1;i < n - 1;++i){//小于n-1是因为必须要保证有一行blue和有一行red
        for (int j = i + 1;j < n;++j){//小于n是因为必须保证有一行是red
            ans = min(ans, w[i] + b[j] - b[i] + r[n] - r[j]);
        }
    }
    cout<<ans;
    return 0;
}