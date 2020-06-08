#include<cstdio>
#include<iostream>
using namespace std;
int subject[5];// 保存四个学科每科题目数量
int sum;// 保存每科答完所用的时间
int t;// 保存做完全部习题所花费的时间
int timeForSubject[21];// 保存每科题目所需要的时间
int dp[3000];
int main()
{
    // 输入数据，四个科目每个科目的题数
    for (int i = 1;i <= 4;++i)
    {
        scanf("%d", &subject[i]);
    }
    // 输入每个科目所有的题目时间
    for (int i = 1;i <= 4;++i)
    {
        // 初始化该科目用的总时间
        sum = 0;
        // 输入当前科目每道题需要花费的时间
        for (int j = 1;j <= subject[i];++j)
        {
            // 当前题目所需要的时间
            scanf("%d", &timeForSubject[j]);
            // 累加到总时间中，注意->这里的总时间是指每一道题的时间相加之和，但是主角是双线程，一会后面会用到
            sum += timeForSubject[j];
        }
        // 开始做题
        // printf("第%d科:\n", i);
        for (int j = 1;j <= subject[i];++j)
        {
            // 由于主角大脑是双线程的，那么可以知道
            // 两道题两道题来做，一边大脑的做题时间肯定是小于等于另一边的。
            // 而我们找到较小的那一边，那么则说明做完该科目所花费的时间就是较大那边大脑花费的时间
            // 而为了尽可能高的效率，我们要让用总时间短的那一边大脑的总时间尽可能长。
            
            for (int k = sum / 2;k >= timeForSubject[j];--k)// 用时少的大脑所能够占用的总时间就是sum/2
            {
                // dp[k] 在k分钟的限定情况下，能够最多使用多少分钟来做题
                // 换句话来说，dp[k] 当做到第i科的第j道题时，指代着k分钟的最大利用值，如dp[7] = 4;
                // 则说明在只有7分钟的情况下，最多的利用时间为4。
                dp[k] = max(dp[k], dp[k - timeForSubject[j] ] + timeForSubject[j]);
            }
        }
        // 另外一边大脑所用的时间累加进t中
        t += sum - dp[sum/2];
        // 归零操作
        for (int j = 1;j <= sum/2;++j)
        {
            dp[j] = 0;
        }
    }
    printf("%d", t);
    return 0;
}
