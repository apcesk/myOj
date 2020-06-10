#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
struct node
{
    int x,y;// 该点的坐标
}t;
int n;// 输入的n数字代表n*n的方阵
int arr[31][31];// 地图大小
bool _arr[31][31];// 标记入队的点
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};// 四个方向
queue <node> q;
void bfs(int sx, int sy)
{
    // 起点入队
    t.x = sx;
    t.y = sy;
    q.push(t);
    while (!q.empty())
    {
        // 枚举该点的四个方向
        node now = q.front();
        arr[now.x][now.y] = 2;
        q.pop();
        for (int i = 0;i < 4;++i)
        {
            t.x = now.x + dir[i][0],t.y = now.y + dir[i][1];
            // 这里不加是否已经入队的判断会有TLE出现
            if (arr[t.x][t.y] == 0 && !_arr[t.x][t.y])
            {
                q.push(t);
                _arr[t.x][t.y] = 1;
            }
        }
    }
}
int main()
{
    scanf("%d", &n);// 输入n的值
    // 开始输入地图
    int sx,sy;// 第一个出现的1
    bool flag = false;
    for (int i = 1;i <= n;++i)
    {
        for (int j = 1;j <= n;++j)
        {
            scanf("%d", &arr[i][j]);
            if (!flag && arr[i][j] == 1)
            {
                flag = true;
                sx = i+1;
                sy = j+1;
            }
        }
    }
    // 找到广搜的起点(sx,sy)，在于第一个出现的1的右下角
    // 在起点的位置进行广搜
    _arr[sx][sy] = 1;
    bfs(sx,sy);
    // printf("答案:\n");
    // 输出
    // 开始输入地图
    for (int i = 1;i <= n;++i)
    {
        for (int j = 1;j <= n;++j)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
