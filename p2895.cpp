#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;

struct node
{
    int x,y,T;// xy为该节点的坐标，T为当前的时间
}p;
int m;// 输入的数字m
int time1[310][310];// 存储每个位置流星降落的最早时间
bool _time1[310][310];// 代表该位置是否被走过
int x,y,t;// x,y代表坐标，t代表当前坐标位置陨石降落的时间
int nx,ny;// 作为临时变量使用
int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1}};
queue <node> q;
int main()
{
    // cin>>m;// 输入m的值
    scanf("%d", &m);
    // 初始化地图
    for (int i = 0;i <= 309;++i)
    {
        for (int j = 0;j <= 309;++j)
        {
            time1[i][j] = -1;
        }
    }
    // 输入地图数据
    for (int i = 1;i <= m;++i)
    {
        // cin>>x>>y>>t;
        scanf("%d %d %d", &x, &y, &t);
        // 如果这个位置陨石降落的时间比它变成焦土的时间早，或者它还没有陨石降落或者变成焦土
        if (t < time1[x][y] || time1[x][y] == -1)
        {
            time1[x][y] = t;
        }
        // 枚举陨石降落波及的位置
        for (int j = 0;j < 4;++j)
        {
            nx = x + dir[j][0];
            ny = y + dir[j][1];
            // 陨石降落波及四个方向,变成焦土的前提，1:没越界，2:不能之前变过焦土或被陨石砸过
            if (nx >= 0 && ny >= 0 && (time1[nx][ny] == -1 || t < time1[nx][ny]))
            {
                time1[nx][ny] = t;
            }
        }
    }
    // 开始进行广搜的步骤
    p.x = 0,p.y = 0, _time1[0][0] = 1,p.T = 0;
    q.push(p);
    while (!q.empty())
    {
        // 获取队首元素，然后出队
        p = q.front();
        q.pop();
        // 再次枚举当前地点的四个方向
        for (int i = 0;i < 4;++i)
        {
            nx = p.x + dir[i][0],ny = p.y + dir[i][1];
            // 如果当前要去的位置没有流星，或者人物去的时候流星还没下落也没有焦土
            if (nx >= 0 && ny >= 0 && !_time1[nx][ny] && (time1[nx][ny] == -1 || p.T + 1 < time1[nx][ny]))
            {
                // nx >= 0 && ny >= 0 && c[nx][ny] == 0 && ( time1[nx][ny]== -1|| p.time + 1 < time1[nx][ny])
                node tmp;// 临时用的入队点
                // 获取当前走到这个位置的信息
                tmp.x = nx, tmp.y = ny, tmp.T = p.T + 1;
                // 标记该节点被走过
                _time1[nx][ny] = 1;
                // 节点入队
                q.push(tmp);
                // 如果找到了绝对安全的位置
                if (time1[nx][ny] == -1)
                {
                    // cout<<tmp.T<<endl;
                    printf("%d\n", tmp.T);
                    return 0;
                }
            }
        }
    }
    // 没有找到绝对安全的位置，输出-1
    // cout<<-1<<endl;
    printf("-1\n");
    return 0;   
}
