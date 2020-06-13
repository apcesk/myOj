#include<cstdio>
#include<iostream>

using namespace std;
const int N=111;
struct node
{
    int x,y;// 记录搜索需要输出点的路径
}path[N];
char fz[N][N];
char stand[]="yizhong";// 保存要比对的标准答案
bool vis[N][N];// 保存需要走的点
int dir[8][2]={{1, 0}, {1, -1}, {1, 1}, {0, 1},{0, -1}, {-1, 1}, {-1. -1}, {-1, 0}};// 八个方向
/*
 * @param
 * x:横坐标位置
 * y:纵坐标位置
 * p:存放路径的数组
 * k:搜索的方向
 * cur:目对应的stand中的第几个字母(下标)
*/
void dfs(int x, int y, node p[],int k, int cur){
    if (cur == 7){
        //如果找到了7个字母，则说明找到了一个完整的路径
        for (int i = 0;i < 7;++i)
        {
            vis[p[i].x][p[i].y] = 1;// 保存应当输出的点
        }
    }
    else
    {
        // 搜索
        int dx = x + dir[k][0];
        int dy = y + dir[k][1];
        if (cur == 6 || fz[dx][dy] == stand[cur+1])
        {
            // 将当前的点保存起来
            p[cur].x = x, p[cur].y = y;
            dfs(dx, dy, p, k, cur+1);
        }
    }
}
int n;// 代表有n行
int main()
{
    scanf("%d", &n);// 输入n的值
    // 输入数据
    for (int i = 0;i < n;++i)
    {
        scanf("%s", &fz[i]);
    }
    // 由于要搜寻一个方向的字符串，所以要先确定两点，y和i确定了之后就沿着该方向进行搜索
    for (int i = 0;i < n;++i)
    {
        for (int j = 0;j < n;++j)
        {
            // 如果当前的字母是y，则看周围八个方向是否有i，有的话就进行搜索
            if (fz[i][j] == 'y')
            {
                // 寻找周围八个方向
                for (int t = 0;t < 8;++t)
                {
                    int nx = i + dir[t][0];
                    int ny = j + dir[t][1];
                    // 如果说当前的字母是i，则确定一条直线，开始进行搜索
                    if (fz[nx][ny] == 'i')
                    {
                        dfs(i, j, path, t, 0);
                    }
                }
            }
        }
    }
    // 输出结果
    for (int i = 0;i < n;++i)
    {
        for (int j = 0;j < n;++j)
        {
            if (vis[i][j]) printf("%c", fz[i][j]);
            else printf("*");
        }
        printf("\n");
    }
    return 0;
}