#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
// 保存节点数的最大值
const int maxn = 1502;
// 用于进行广搜的队列
queue <int> q;
// d[i] 用于记录i节点前的最长路，mp[a][b]存储a，b间的路径长度
int d[maxn], mp[maxn][maxn];
// n个节点，m条边
int n,m;
void bfs()
{
    // 初始化为-1，用于在无解的时候输出-1
    memset(d, -1, sizeof(d));
    // 第一个节点的路径长度为0
    d[1] = 0;
    // 第一个节点入队
    q.push(1);
    while(!q.empty())
    {
        // 获取队首元素
        int t = q.front();
        for (int i = 1;i <= n;++i)
        {
            // 如果当前位置可以走到节点i，并且原来到达节点i的路径长度要小于从当前位置走到节点i的路径长度
            if(mp[t][i] && d[i] < d[t] + mp[t][i])
            {
                // 更新走到当前节点的最长路径
                d[i] = d[t] + mp[t][i];
                // 下一个节点入队
                q.push(i);
            }
        }

        // 队首元素出队
        q.pop();
    }
}
int main()
{
    cin>>n>>m;// 输入n个节点，m条边
    int a,b,l;
    // 输入m条边的信息
    for (int i = 1;i <= m;++i)
    {
        cin>>a>>b>>l;// 输入从a到b的长度l
        mp[a][b] = max(mp[a][b], l);// 如果两个点之间存在多条边，则只保留最长边
    }
    // 广搜
    bfs();
    // 输出结果
    cout<<d[n];
    return 0;
}
