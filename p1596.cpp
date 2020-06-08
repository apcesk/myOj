#include<cstdio>
#include<iostream>

using namespace std;
char map[101][101];// 水洼地图
int N,M;// N * M 大小的地图
int ans;// 保存答案
int dir[8][2] = {{1,1}, {1,-1},{1,0},{-1,1},{-1,-1},{-1,0},{0,1},{0,-1}};// 标记八个方向
// 深搜
void dfs(int sx, int sy)// 开始的坐标
{
    // 将该点的水洼变成平地。
    map[sx][sy] = '.';
    // 对该水洼的八个方向进行搜索
    int dx,dy;
    for (int i = 0;i < 8;++i)
    {
        dx = dir[i][0];
        dy = dir[i][1];
        if (sx + dx >= 0 && sx + dx < N &&
            sy + dy >= 0 && sy + dy < M &&
            map[sx + dx][sy + dy] == 'W')
        {
            dfs(sx+dx,sy+dy);
        }
    }
    return;
}
int main()
{
    scanf("%d %d", &N, &M);// 输入N和M
    // 开始输入地图,循环变量从0开始是因为有换行的原因。
    for (int i = 0;i < N;++i)
    {
        scanf("%s", map[i]);
    }
    // 对于每一处的水洼进行搜索
    for (int i = 0;i <= N;++i)
    {
        for (int j = 0;j <= M;++j)
        {
            if (map[i][j] == 'W')
            {
                dfs(i,j);
                ans++;
            }
        }
    }
    printf("%d", ans);
    return 0;
}
