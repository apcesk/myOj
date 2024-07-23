#include<bits/stdc++.h>
using namespace std;
#define int long long
// scc[i] = cnt;// 代表点i所属的强连通分量是cnt
// 已知a到b有一条边
// scc[a] = k
// scc[b] = l
// k -> l 
// 对于边P, 其起点为a, 终点为b
// 若scc[a] != scc[b]
// 此时可以建立从scc[a] 到scc[b] 的边
const int N = 1e4 + 10, M = 5e4 + 10;
int n, m;// n头牛，m条边
// head[i] = k代表点i作为起点的首个边的下标
// edge_cnt代表当前要存储的边的下标 
int head[N], edge_cnt = 0;
struct Edge {
	int to, next;// to是该边的终点，next是该边的上一条同起点的边的下标 
} edges[M];
// 链式前向星加边过程 
void add_edge(int from, int to) {// 加边函数 
	edges[++edge_cnt].to = to;
	edges[edge_cnt].next = head[from];
	head[from] = edge_cnt;
}
int scc[N], siz[N], cnt = 0, stk[N], top = 0, dfn[N], low[N], ti = 0;
bool instk[N];
void tarjan(int now) {
	// 1、时间戳操作
	dfn[now] = low[now] = ++ti;
	stk[++top] = now;// 
	// 标记在栈中
	instk[now] = 1;
	// 2、深搜枚举其它点 
	for (int i = head[now]; i ;i = edges[i].next) {
		int to = edges[i].to;
		if (dfn[to] == 0) {
			tarjan(to);
			low[now] = min(low[now], low[to]);
		} else if (instk[to]) {
			low[now] = min(low[now], dfn[to]);
		}
	}
	// 3、出栈标记每个点所属的强连通分量
	if (dfn[now] == low[now]) {
		int node;
		++cnt;
		do {
			node = stk[top--];
			instk[node] = 0;
			scc[node] = cnt;
			siz[cnt]++;
		} while(node != now);
	} 
}
int du[N];// du[i] = k代表编号为i的强连通分量的出度 
signed main() {
	// step 1、读题、声明变量
	// step 2、输入
	cin >> n >> m;
	for (int i = 1;i <= m;i++) {
		int fr, to;
		cin >> fr >> to;
		add_edge(fr, to);// 加边 
	}
	// step 3、处理
	for (int i = 1;i <= n;i++) {
		if (!dfn[i]) tarjan(i);
	}
	// 以下内容实际的时间复杂度为O(n + m) 
	for (int i = 1;i <= n;i++) {// 枚举每一个点 
		// 枚举每个点的出边，如果该出边的到达点和该点不属于同一个强连通分量
		// 则该点所属的强连通分量的出度+1
		for (int j = head[i];j;j = edges[j].next) {
			if (scc[i] != scc[edges[j].to]) {
				du[scc[i]]++;// 该点所属的强连通分量的出度+1 
			}
		} 
	}
	// now_cnt代表出度为0的强连通分量有几个 
	int ans = 0, now_cnt = 0;
	for (int i = 1;i <= cnt;i++) {// 有cnt个强连通分量 
		if (du[i] == 0) {// 编号为i的强连通分量的出度为0 
			ans = siz[i];
			now_cnt++;
		}
	}
	// step 4、输出
	if(now_cnt == 1) cout << ans;
	else cout << 0;
	return 0;
}
