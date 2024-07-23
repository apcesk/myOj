#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
#define p_int pair<int, int> 
const int N = 5e4 + 10, M = 1e6 + 10;
int b, n, m;//b头奶牛，n个农场，m条边
struct Node {
  int to, value;
};
vector <Node> G[N];
priority_queue < p_int, vector< p_int >, greater< p_int > > q;// 优先队列
int dis[N];// dis[i] = k代表点i到达点1的最短距离
void dijkstra() {// 单源最短路
  memset(dis, 0x3f, sizeof dis);
  dis[1] = 0;// 自己
  q.push((p_int){0, 1});
  while (!q.empty()) {// 队列不为空
    // 提取出最近的点
    p_int temp = q.top();
    int now = temp.second;
    int distance = temp.first;
    // 判断该点有没有松弛过
    if (dis[now] < distance) continue;// 该点被松弛过
    // 利用该点松弛其它点
    for (int i = 0;i < G[now].size();i++) {
      int to = G[now][i].to, value = G[now][i].value;
      if (dis[now] + value < dis[to]) {
        dis[to] = dis[now] + value;
        q.push((p_int){dis[to], to});
      }
    }
    q.pop();// 松弛完毕
  }
}
int main() {
  cin >> n >> m >> b;
  int f, t, v;
  for (int i = 1;i <= m;i++) {
    cin >> f >> t >> v;
    G[f].push_back((Node){t, v});
    G[t].push_back((Node){f, v});
  }
  dijkstra();
  for (int i = 1;i <= b;i++) {// b次询问
    cin >> f >> t;
    cout << dis[f] + dis[t] << endl;
  }

  return 0;
}
/**
DDDDD           IIIIII        OOOOOOOO
DD  DD            II          OO    OO
DD   DD           II          OO    OO
DD    DD          II          OO    OO
DD    DD          II          OO    OO
DD    DD          II          OO    OO
DD   DD           II          OO    OO
DD  DD            II          OO    OO
DDDDD           IIIIII        OOOOOOOO
*/