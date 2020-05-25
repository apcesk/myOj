/*
* 思路
* 使用映射建立每个数字出现的次数
* 然后让这些数字一次减去c
* 会得到一组全新的数字，再看这组全新的数字
* 在映射中出现的次数，就是总共可以组合出来的数对了
*/
#include<cstdio>
#include<map>
using namespace std;
long long arr[200001];// 存放所有出现过的数字
map<long long, long long> M;// 存放每个数字出现次数的映射
// map<number, times> 代表number数字对应出现的times次数
long long ans;// 存放答案
int main()
{
    // 题目 a - b = c
    // 将之转化为 a - c = b
    int n;
    long long c;
    // 输入数据
    scanf("%d %lld", &n, &c);
    for (int i = 1;i <= n;++i){
        scanf("%lld", &arr[i]);// 数字输入到数组中去
        // 将该数字对应的映射值进行+1
        M[arr[i]]++;
        // 为了找到对应的值
        // 用已知a的值减去c
        // 得到的即为b
        arr[i] -= c;
    }
    // 以上做完之后，可以进行统计。
    for (int i = 1;i <= n;++i){
        // 从映射中找到b出现的值即可
        if (arr[i] <= 0) continue;
        ans += M[arr[i]];
    }
    printf("%lld\n", ans);
    return 0;
}