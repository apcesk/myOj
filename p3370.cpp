#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef unsigned long long ull;
ull base = 131;// Hash进制转换基数，要求质数。
ull a[10010];// 存放每个字符串的哈希值
char s[10010];// 存放输入的字符串
int n,ans=1;// 输入的n，保存答案的ans
ull hashs(char t[])
{
    // 存储字符串长度
    int len = strlen(t);
    // 存储字符串转成数字的初始值
    // 按位进行哈希值的转化，进制就是base
    ull ans=0;
    for (int i = 0;i < len;++i)
    {
        ans = ans * base + (ull)s[i];
    }
    // 一种巧妙的运算方式，等同于取余数，不懂的可以好好的百度搜索一下关于位运算的那些事
    return ans & 0x7fffffff;
}
int main() 
{
    // 输入n
    scanf("%d", &n);
    // 输入每行的字符串
    for (int i = 1;i <= n;++i)
    {
        // 这里比较特殊，数组变量本身存放的就是数组开头所在的地址，所以不用进行取地址输入
        scanf("%s", s);
        // 将该字符串转化出的hash值存放到a数组中
        a[i] = hashs(s);
    }
    // 对存放字符串哈希值的数组进行排序()
    sort(a+1, a+1+n);
    // 计算答案
    for (int i = 2;i <= n;++i)
    {
        if (a[i] != a[i-1])
        {
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
