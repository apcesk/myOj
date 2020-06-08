#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
struct node {
    int floor,step;// floor代表楼层号，step代表到达该楼层需要的步数
}tmp;
queue <node> q;// 创建一个node节点的队列
bool _map[201];// 标记每个节点是否被访问过
int map[201];// 存储每个楼层电梯可以进行上下的数字
int N,A,B;// 保存输入的数值
int main()
{   
    // 输入第一行数据
    scanf("%d %d %d", &N, &A, &B);
    // 输入每个电梯可以上下的数字
    for (int i = 1;i <= N; ++i) {scanf("%d", &map[i]);}// 带上大括号是良好的习惯
    // 开始进行广搜，初始节点入队
    q.push((node){A,0});// 将所在的楼层入队，并且需要的步数为0，内部的语法属于强制类型转换 -> (node){A,0}
    // 广搜路径特性，只要队列不为空
    while (!q.empty())
    {
        // 取出队首元素
        tmp = q.front();
        // 队首元素出队
        q.pop();
        // 如果队首元素就为想要去的楼层
        if (tmp.floor == B)
        {
            break;// 终止循环
        }
        // 如果当前楼层向上走没有越界，并且要去的楼层没去过，则将要去的楼层入队，并且标记该楼层为被访问过
        if (tmp.floor + map[tmp.floor] <= N && !_map[tmp.floor + map[tmp.floor]])
        {
            q.push( (node){tmp.floor+map[tmp.floor], tmp.step+1} );
            _map[tmp.floor+map[tmp.floor]] = 1;
        }
        // 往下走
        if (tmp.floor - map[tmp.floor] >= 1 && !_map[tmp.floor - map[tmp.floor]])
        {
            q.push( (node){tmp.floor-map[tmp.floor], tmp.step+1} );
            _map[tmp.floor-map[tmp.floor]] = 1;
        }

    }
    // 输出
    if (tmp.floor == B)// 能够到达
    {
        printf("%d", tmp.step);
    }
    else// 不能够到达
    {
        printf("-1");
    }
    
    return 0;
}
