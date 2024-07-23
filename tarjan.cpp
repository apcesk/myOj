/**
 * @file tarjan.cpp
 * 强联通分量：一个有向图中任意两点都连通的极大子图，特殊：单独一个点也算强联通分量。
 */
#include<iostream>
#include<vector>
using namespace std;
#define int long long 
const int N = 1e4 + 10;
int n, m;
vector <int > G[N];
// low[i] = k代表点i通过1条边（返祖边）能够访问到的最早时间戳
int dfn[N], low[N], ti = 0;
int stk[N], top = 0;
bool instk[N];// 标志某个元素是否已经在栈中
int scc[N], siz[N], cnt = 0;// scc[i] = k代表点i属于编号为k的强联通分量
// siz[i] = k代表编号为i的强联通分量里面有k个节点
// cnt强联通分量个数
void tarjan(int now) {
  // 1、为当前点打时间戳
  dfn[now] = low[now] = ++ti;
  stk[++top] = now;// 入栈
  instk[now] = 1;
  // 2、枚举所有点now的出边（可达点）
  for (int i = 0;i < G[now].size();i++) {
    int to = G[now][i];
    if (dfn[to] == 0) {
      tarjan(to);
      low[now] = min(low[now], low[to]);
    } else if(instk[to]) {
      low[now] = min(low[now], dfn[to]);
    }
  }
  // 3、找到强联通分量的“根结点”才出栈
  if (dfn[now] == low[now]) {
    cnt++;// 找到了一个强联通分量，强联通分量的个数+1
    int node;// 临时的变量，保存出栈的节点
    do
    {
      node = stk[top--];
      scc[node] = cnt;
      siz[cnt]++;// 编号为cnt这个强联通分量多了一个点
      instk[node] = 0;
    } while (node != now);
  }
}

signed main() {
  cin >> n >> m;
  for (int i = 1;i <= m;i++) {
    int f, t;
    cin >> f >> t;
    G[f].push_back(t);
  }
  for (int i = 1;i <= n;i++) {
    if (dfn[i] == 0) tarjan(i);
  }
  // 枚举cnt个强联通分量
  int ans = 0;
  for (int i = 1;i <= cnt;i++) {
    if (siz[i] > 1) ans++;
  }
  cout << ans;
  return 0;
}
/**
DDDDD           IIIIII        OOOOOOO
DD  DD            II          OO    OO
DD   DD           II          OO    OO
DD    DD          II          OO    OO
DD    DD          II          OO    OO
DD    DD          II          OO    OO
DD   DD           II          OO    OO
DD  DD            II          OO    OO
DDDDD           IIIIII        OOOOOOOO
*/


