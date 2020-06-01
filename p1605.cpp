#include<iostream>
#include<cstdio>
using namespace std;
int map[6][6];//地图
bool _map[6][6];//走过的标记
int dx[4]={0,0,1,-1};// 打表
int dy[4]={-1,1,0,0};// 打表
int ans; // 代表走到目的地共有ans种走法
int fx,fy;// 终点的坐标
int sx,sy;// 起点的坐标
int T,n,m;// 障碍总数t，n*m的迷宫
int l,r;// l，r是障碍的横坐标和纵坐标
void walk(int x,int y)//定义walk；
{
    // 一旦走到了目的地，说明路径数目+1；
    if(x == fx && y == fy)//fx表示结束x坐标，fy表示结束y坐标；
    {
        ans++;// 总数增加
        return;
    }
    else
    {
        // 每一个点可以选择四个方向进行行走
        for(int i=0;i<=3;i++)
        {
            // 防止数组越界
            if (x+dx[i] >= 1 && x+dx[i] <= n && y+dy[i] >= 1 && y+dy[i] <= m)
            // 如果要走的点没有走过，并且不是障碍
            if(_map[x + dx[i]][y + dy[i]] == 0 && map[x + dx[i]][y + dy[i]] == 0)
            {
                // 前往该点
                _map[x][y]=1;//走过的地方打上标记；
                // 从该点继续出发
                walk(x+dx[i],y+dy[i]);
                // 回溯阶段还原该点的标记
                _map[x][y]=0;
            }    
        } 
    }
}
int main()
{
    scanf("%d %d %d", &n, &m, &T);//n，m长度宽度，T障碍个数 
    scanf("%d %d %d %d", &sx, &sy, &fx, &fy);//起始sx，sy, 结束分fx,fy
    for(int i=1;i<=T;++i)
    {
        scanf("%d %d", &l, &r);//l，r是障碍坐标；
        map[l][r] = 1;
        _map[l][r] = 1;
    }
    // 递归搜索
    walk(sx,sy);
    // 输出答案
    printf("%d", ans);
    return 0;
} 