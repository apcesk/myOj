#include<cstdio>
#include<iostream>
using namespace std;
#define MAX 100001
int n,x;// n颗糖果，任意相邻两组糖果不能超过x
long long eat;// 存储一共吃的糖
int candy[MAX];// 存放总的糖果数
int main(){
    // 输入n和x
    scanf("%d %d", &n, &x);
    // 输入数据
    for(int i = 1;i <= n;++i){
        scanf("%d", &candy[i]);
    }
    // 开始吃糖
    int tmp;
    for (int i = 1;i < n;++i){
        if (candy[i] > x){
            // 如果当前盒子的糖果就多过标准，则必须吃掉多余的部分
            tmp = candy[i] - x;
            eat += tmp;
            candy[i] -= tmp;
        }
        // 如果当前位置的糖果和下一个位置糖果相加还是大于x，则把candy[x+1]中多的糖果吃掉
        if (candy[i] + candy[i+1] > x){
            tmp = (candy[i] + candy[i+1]) - x;
            candy[i+1] -= tmp;
            eat += tmp;
        }
    }
    printf("%lld", eat);
    return 0;
}