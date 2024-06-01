#include<iostream>
#include<vector>
using namespace std;
const int N = 1e5 + 10;
int n;
vector <int> E[N];// E[i] = {j, k, l}代表点i到点j、k、l存在一条边
// ans代表重心的最大子树节点个数
// cog[0]代表重心的子树节点个数
int siz[N], cog[3] = {N}, cog_cnt; // siz[i] = k代表点i作为根结点树的节点个数。
void dfs(int now, int father) {
  siz[now] = 1;
  // printf("当前的树根为: %d\n", now);
  int maxn = 0;// 代表now这个树的最大子树的节点个数
  // for (int to : E[now]) {// 遍历从now出发的每一条边（返祖除外）
  for (int i = 0;i < E[now].size();i++) {
    int to = E[now][i];
    if (to == father) continue;
    // printf("从%d到%d存在边\n", now, to);
    dfs(to, now);
    // printf("%d作为根,子节点%d的个数为: %d\n", now, to, siz[to]);
    siz[now] += siz[to];
    maxn = max(maxn, siz[to]);
  }
  maxn = max(maxn, n - siz[now]);
  // printf("离开树根%d, 最大子树节点个数为: %d\n", now, maxn);
  if (maxn < cog[0]) {
    cog[0] = maxn;
    cog[1] = now;
    cog_cnt = 1;
  } else if (maxn == cog[0]){
    cog[2] = now;
    cog_cnt = 2;
  }
}
int main() {
  cin >> n;
  for (int i = 1;i < n;i++) {
    int f, t;
    cin >> f >> t;
    E[f].push_back(t);
    E[t].push_back(f);
  }
  // 从任意一点出发
  dfs(1, 0);
  for (int i = 1;i <= cog_cnt;i++) {
    printf("树的重心为: %d\n", cog[i]);
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