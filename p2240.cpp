#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct gold{
    int weight, value;// 重量，价值
    double per_value;// 单位价值
}arr[110];
int n;// n堆金币
int bag;// 背包大小
double ans;// 背包的总价值
bool cmp(gold a, gold b){
    return a.per_value > b.per_value;
}
int main(){
    scanf("%d %d", &n, &bag);// 输入n
    for (int i = 1;i <= n;++i){
        scanf("%d %d", &arr[i].weight, &arr[i].value);// 输入重量和价值
        arr[i].per_value = (double)arr[i].value / (double)arr[i].weight;
    }
    // 排序
    sort(arr + 1, arr + 1 + n, cmp);
    // 开始往背包里面塞
    int i = 1;
    while (bag > 0 && i <= n){
        // 按照排序的顺序进行装包
        if (bag >= arr[i].weight){
            ans += arr[i].value;
            bag -= arr[i].weight;
        }else{
            ans += bag * arr[i].per_value;
            break;
        }
        ++i;
    }
    printf("%.2lf", ans);
    return 0;
}