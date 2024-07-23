#include<iostream>

using namespace std;
#define int long long 
const int N = 5e5 + 10;
int n, m, s;// n个点，m个查询，根结点是s
int head[N], cnt = 0;
int phead[N], pcnt = 0;
int f[N];// 并查集
int Find(int x) {
  if (x == f[x]) return f[x];
  return f[x] = Find(f[x]);
}
void Union(int a, int b) {
  int fa = Find(a), fb = Find(b);
  if (fa != fb) f[fa] = fb;
}
struct Edge{
  int to, next;
} edges[N<<1];
struct Problem {
  int to, next;
} problems[N << 1];
void add_problem(int from, int to) {
  problems[++pcnt].to = to;
  problems[pcnt].next = phead[from];
  phead[from] = pcnt;
}
void add_edge(int from, int to) {
  edges[++cnt].to = to;
  edges[cnt].next = head[from];
  head[from] = cnt;
}
bool vis[N];// 代表该点访问过没有
void tarjan(int now, int fa) {
  vis[now] = 1;
  // 往下走
  for (int i = head[now];i;i = edges[i].next) {
    int to = edges[i].to;
    if (to != fa) {
      tarjan(to, now);
      Union(now, to);// 合并
    }
  }
  // 处理问题
  for (int i = phead[now];i;i = problems[i].next) {
    
  }
}
signed main() {
  cin >> n >> m >> s;
  for (int i = 1;i <= n;i++) {
    f[i] = i;
  }
  for (int i = 1;i < n;i++) {
    int fr, to;
    cin >> fr >> to;
    add_edge(fr, to);
    add_edge(to, fr);
  }
  for (int i = 1;i <= m;i++) {
    int fr, to;
    cin >> fr >> to;
    add_problem(fr, to);
    add_problem(to, fr);
  }
  tarjan(s, 0);
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