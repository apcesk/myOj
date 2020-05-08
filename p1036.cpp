// P1036 选数
#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int n,k;//n个整数，k项任意相加n,k均小于20
int num[21];
bool useNum[21];//标记当前数字是否被使用过
int ans;//总共有ans个质数
bool isPrime(int n){//判断n是否是一个质数
    if (n <= 1) return false;
    for (int i = 2;i <= sqrt(n);++i){
        if (n % i == 0) return false;
    }
    return true;
}
int tmp;//存放每k次相加的结果
void dfs(int k, int now){//递归求解
    if (k == 0){//计算了k次，结果存在于tmp中
        //判断tmp是不是一个质数，如果是则ans++
        if (isPrime(tmp)) ans++;
        return;
    }
    //k个数字相加
    for (int i = now;i <= n;++i){
        tmp += num[i];
        dfs(k-1, i+1);
        tmp -= num[i];
    }
}
int main(){
    //输入n和k
    scanf("%d %d", &n, &k);
    //录入数据
    for (int i = 1;i <= n;++i){
        scanf("%d", &num[i]);
    }
    
    dfs(k, 1);//递归求解～
    printf("%d", ans);//输出答案
    return 0;
}