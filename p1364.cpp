#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
bool map[101][101];//邻接表用来存放两个节点之间的距离
bool vertex[101];//广搜时候用到的标记该点是否访问过。
int n, num[101], ans = 0x7777777;//num数组存放当前节点的人数
struct node{
    int this_point,step;//u代表当前节点，step代表到这个节点所需要的步数
};
//初始化vertex数组
void reset(){
    for (int i = 0;i <= n;++i) vertex[i] = 0;
}
//广搜解决问题
int bfs(int v){//找当前医院为v的时候，所有人到达医院的总距离
    reset();//初始化vertex数组
    queue<node> q;//创建一个node队列
    vertex[v] = 1;
    q.push((node){v, 0});//将v这个节点入队，并且步数为0
    int sum = 0;//所有人到达医院的总距离
    while (!q.empty()){//队列中只要仍有元素，说明还没有计算完成
        node now = q.front();//声明一个当前节点
        q.pop();//当前节点出队
        for (int i = 1;i <= n;++i){
            //如果当前的节点能够到达i，并且i没有被访问过，主要防止反复横跳
            if (map[now.this_point][i] && !vertex[i]){
                node next = {i, now.step+1};//下一次的起始点，并记录到达该点需要的步数
                sum += num[i] * next.step;//累加步数。
                vertex[i] = 1;//当前点被访问过了
                q.push(next);//当前节点入队
            }
        }
    }
    return sum;//将总步数返回出去
}

int main(){
    scanf("%d", &n);//输入n
    for (int i = 1;i <= n;++i){
        int a,l,r;
        scanf("%d %d %d", &a, &l, &r);
        num[i] = a;//存放当前节点的人数
        if(l) map[i][l] = map[l][i] = 1;//如果有左儿子，则到左儿子的距离为1
        if(r) map[i][r] = map[r][i] = 1;//同上， 变成右儿子。
    }
    
    for (int i = 1;i <= n;++i){
        ans = min(ans, bfs(i));//使用广搜来进行查找每一个点都设立为医院，最小的那一个
    }
    printf("%d\n", ans);
    return 0;
}