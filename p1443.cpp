#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
struct Point{
    int x,y,step;// x和y代表该点在棋盘的位置，step代表走到该点需要几步
};
Point arr[401][401];
bool map[401][401];// 保存每个位置是否走过
int ex,ey,sx,sy;// 保存棋盘的大小和马的坐标
// 保存能够走的八个位置
int dir[8][2] = {{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,-1},{-2,1}};
queue <Point> q;// 创建一个棋盘节点的队列
void bfs(int startx, int starty)
{
    //sx,sy代表马的初始坐标
    Point tmp;
    tmp.x = startx, tmp.y = starty,tmp.step = 0;
    arr[tmp.x][tmp.y].step = 0;
    // 起始位置入队
    q.push(tmp);
    // 标记起始位置已走过
    map[tmp.x][tmp.y] = 1;
    while(!q.empty())
    {
        // 获取处队首元素
        Point now = q.front();
        // 只要队列不为空，说明还有位置可走
        for (int i = 0;i < 8;++i){
            // 当前可走的八个方向，并且落子的位置没有走过
            if (now.x + dir[i][0] >= 1 &&
                now.x + dir[i][0] <= ex &&
                now.y + dir[i][1] >= 1 &&
                now.y + dir[i][1] <= ey &&
                !map[now.x + dir[i][0]][now.y + dir[i][1]])
            {
                // 把该点入队
                Point next;
                next.x = now.x + dir[i][0];
                next.y = now.y + dir[i][1];
                next.step = now.step + 1;
                q.push(next);
                arr[next.x][next.y].step = next.step;
                // 标记该点已走过
                map[next.x][next.y] = 1;
             
            }
        }
        // 队首元素出队
        q.pop();
    }
}
void outAnswer(){
    // 输出结果
    for (int i = 1;i <= ex;++i){
        for (int j = 1;j <= ey;++j){
            if (map[i][j]){// 该点被访问过，说明能够到达这个位置
                printf("%-5d", arr[i][j].step);
            }else{// 到不了这个位置
                printf("%-5d", -1);
            }
        }
        printf("\n");
    }
}
int main()
{
    scanf("%d %d %d %d", &ex, &ey, &sx, &sy);
    // 开始标记地图的每一个点
    bfs(sx, sy);
    // 输出答案
    outAnswer();
    return 0;
}