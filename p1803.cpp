#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
struct speech{
    int start, end;// start是开始时间，end是结束时间
}arr[1000001];
// 排序用函数
bool cmp(speech a, speech b);
int n;// 输入共有n个比赛
int ans;// 总共可以参加ans场比赛
int main(){
    // 输入n
    scanf("%d", &n);
    // 输入每场比赛的时间
    for (int i = 1;i <= n;++i){
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }
    // 排序按照最先结束的时间从小到大进行排序，并且如果有相同的结束时间的，按参赛时间最短的进行选取
    sort(arr+1, arr+n+1, cmp);
    int last_speech = 0;// 上一次参加比赛的结束时间
    // 开始尽可能的参加比赛
    for (int i = 1;i <= n;++i){
        // 如果当前参加比赛的开始时间，大于等于上一次参加比赛的结束时间，即可参加本次比赛。
        if (arr[i].start >= last_speech){
            last_speech = arr[i].end;
            ans++;
        }
    }
    printf("%d", ans);
    // 输出检测
    // for (int i = 1;i <= n;++i){
    //     printf("开始时间:%d,结束时间:%d\n", arr[i].start, arr[i].end);
    // }
    return 0;
}
// 实现cmp
bool cmp(speech a, speech b){
    // 已结束时间最短的优先
    if (a.end < b.end){
        return true;
    }else if (a.end == b.end){// 如果结束的时间相同，耗时短的优先
        return (a.end - a.start) < (b.end - b.start);
    }
    return false;
}
