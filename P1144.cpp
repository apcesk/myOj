#include<iostream>
#include<cstdio>
#include<queue>
#include<math.h>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
const int N = 1e6 + 5, M = 2e6 + 5, MOD = 100003;
int n, m;
struct Node {
  int num, step;
};
vector<int> G[N];
int dist[N], ans[N];
bool vis[N];
queue<Node> q;
int main() {
  ios::sync_with_stdio(0);
  cin.tie();
  cin >> n >> m;
  for (int i = 1;i <= m;i++) {
    int f, t;
    cin >> f >> t;
    G[f].push_back(t);
    G[t].push_back(f);
  }
  memset(dist, 0x3f, sizeof dist);
  q.push((Node){1, 0});
  dist[1] = 0, vis[1] = 1;
  ans[1] = 1;
  while (!q.empty()) {
    int now = q.front().num, step = q.front().step;
    for (int i = 0;i < G[now].size();i++) {
      int to = G[now][i];
      if (!vis[to]) {// 首次到达
        dist[to] = step + 1; // 记录到该点的最少步数
        ans[to] = ans[now] % MOD;// 到该点的方案数
        vis[to] = 1;// 标记到过该点
        q.push((Node){to, step + 1});
      } else if (vis[to] && step + 1 == dist[to]) {// 该点被访问过，且再次到达该点刚好和最近的相等
        ans[to] += ans[now];// 方案数加等于来到now的方案数！
        ans[to] %= MOD;
      }
    }
    q.pop();
  }
  for (int i = 1;i <= n;i++) printf("%d\n", ans[i]);
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