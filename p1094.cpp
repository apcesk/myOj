#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int t,n;// max_gift代表纪念品价值上限，n代表共有几组纪念品
int arr[100001];// 存放所有纪念品的数组
int ans;
bool cmp(int a, int b){
    return a < b;
}
int main(){
    // 输入上限和礼品总数
    scanf("%d", &t);
    scanf("%d", &n);
    for (int i = 1;i <= n;++i){
        scanf("%d", &arr[i]);
    }
    // 从小到大排序
    sort(arr+1, arr+1+n, cmp);
    // 开始对纪念品进行分组，大小搭配来分
    int i = 1,j = n;// 指向数组头和尾的指针
    while(i < j && n >= 2){
        // 如果当前最大值+最小值大于了最高价值，说明只能最大值自己分一组
        if (arr[j] + arr[i] > t){
            j--;
            ans++;
            n--;// 少了一个纪念品
        }else if (arr[j] + arr[i] <= t){
            j--;
            i++;
            ans++;
            n-=2;// 少了两个纪念品
        }
    }
    if (n >= 1) ans++;
    printf("%d", ans);
    return 0;
}