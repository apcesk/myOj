#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
int n;// 位置总数
map <int, int> a;// 使用map来保存每个位置的球数，map[i]=j -> 代表在j处有i个球
int ball;// 某个位置球的数量
int shootTime;
int main()
{
    scanf("%d", &n);
    for (int i = 1;i <= n;++i)
    {
        scanf("%d", &ball);
        a[ball] = i;
    }
    // 输入要发球的次数
    scanf("%d", &shootTime);
    for (int i = 1;i <= shootTime;++i)
    {
        scanf("%d", &ball);// 输入想要击倒球的数量
        printf("%d\n", a[ball]);// 输出答案，不存在默认为0
    }
    return 0;
}
