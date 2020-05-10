#include<cstdio>
#include<iostream>
#include<cmath>

using namespace std;
struct node{
    double x, y;//x，y代表点的坐标
}map[16];//1个足够存放15个点的坐标的地图；
//标记改点是否访问过
bool _map[16];
int n;//总共有n个点，老鼠出发的点是0,0
double dis;//总的最短距离
//题解思路，选择走的点尽可能选取当前距离最近的点，
int main(){
    scanf("%d", &n);
    //输入n个点的坐标
    double tmpx, tmpy;
    for (int i = 1;i <= n;++i){
        scanf("%lf %lf", &tmpx, &tmpy);
        //记录当前点的x坐标和y坐标
        map[i].x = tmpx;
        map[i].y = tmpy;
    }
    // 求出一个点到其他所有点中最近的点的距离
    double minDis = 0x7fffffff;
    int minDisPoint = -1;
    for(int j = 0;j <= n; j++){
        for (int i = 1;i <= n;++i){
            if (j == i) continue;
            double tmpDis;
            if (!_map[i]){
                // 如果当前点没有访问过
                tmpDis = sqrt(pow(map[j].x - map[i].x, 2) + pow(map[j].y - map[i].y, 2));
                if (tmpDis < minDis){
                    minDis = tmpDis;
                    minDisPoint = i;//代表从j点到i点的最小距离
                }
            }
        }
        printf("此时minDis:%lf\n", minDis);
        dis += minDis;
        minDis = 0x7fffffff;
        _map[minDisPoint] = 1;
        minDisPoint = -1;
    }
    printf("%.2lf", dis);
    return 0;
}
/*
思路：
    点结构: x,y,n;xy为坐标，n为入队时的编号，改点作为第几个访问的点。
    1:从当前点出发，将所有可以去到的点进行入队。
    2:在所有入队的点中找到距离最小的点，将到达该点所需要的距离进行加和。
    3:如果存在多个最小距离最小的点，则将所有最小距离的点入队，并打上标记，标明是第几个点(说明改点后序还有可访问点)
    4:如果改点是访问的第n个点则说明总距离计算完毕。
    -------
    通过以上步骤求出所有走法中的距离最短的那一个。
    看上去像是"广搜+贪心"。
    核心：每一步走最近的。
*/