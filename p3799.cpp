#include<iostream>
#include<cstdio>
using namespace std;
// 要用四根木棒做一个正三角形
// 则其中两根必然长度一致，另外两根相加长度等于
// 每根木棒长度不超过5000，数据可以用桶来存下
int n;//总共又n根木棒
int stick[5001];//存放个长度的木棒数量
int mod = 1e9+7;//取余的数字
// 存储最长的棍子和最短的棍子，方便确定选取组合的边界
int max_stick = -0x7fffffff, min_stick = 0x7fffffff;
long long ans;
int main(){
    // 输入n
    scanf("%d", &n);
    int stick_long;//保存当前棍子的长度
    for (int i = 1;i <= n;++i){
        scanf("%d", &stick_long);
        stick[stick_long]++;// 对应长度的棍子+1
        max_stick = max(max_stick, stick_long);
        min_stick = min(min_stick, stick_long);
    }
    // 开始进行选取组合,选取组合的开始是从最小长度的棍子下一个开始
    // 因为如果选取了两根最小长度的棍子作为两条边，那么说明第三条边是不能够选出来的
    // (剩下的所有棍子任意两个组合都比已经选好的棍子长)
    for (int i = min_stick + 1;i <= max_stick; ++i){
        if (stick[i] <= 1){
            // 如果当前的棍子只有1个或没有，则无法组成复合要求的正三角形
            continue;
        }
        // 否则说明当前的长度棍子是有两个以上的, j<=i/2 的原因是因为如果量
        for (int j = min_stick; j <= i / 2;++j){
            if (stick[j] && stick[i-j]){
                // 如果存在两个棍子相加长度等于j，则说明能够组成正三角形
                if (j * 2 != i){
                    // 如果说当前的棍子并不是2根一样的
                    // 则组合的方式要加的是
                    // (stick[i] * (stick[i] - 1) / 2) 从至少拥有2个相等长度的木棍中任意取两个总方法数
                    // stick[j] * stick[i-j] 从长度为j和长度为i-j的长度中能够取出的组合数
                    // 二者相乘再对mod进行取余，然后加到ans中
                    ans += ((stick[i] * (stick[i] - 1) / 2) * stick[j] * stick[i-j] % mod) % mod;
                }else {
                    // 说明当前选取的两根棍子长度是一样的
                    ans += ((stick[i] * (stick[i] - 1) / 2) * stick[j] * (stick[j]-1) / 2 % mod) % mod;
                }
            }
        }
    }
    printf("%lld", ans%mod);
    return 0;
}