/**
	1、多个树上的问题，森林。
	2、处理每颗树的直径。
		2-1、 怎么表示每颗树。用并查集描述每个节点所属的树。
		2-2、 针对每颗树算一遍直径。
	3、对于询问1点问题。
		3-1、找到该点所属的树，直接输出该树的直径。
	4、对于链接2点问题。
		4-1、怎么计算链接后形成的新树的直径。
			假设树a的直径是r1
				树b的直径是r2
				合成的新树的直径应该是多少？
			得出：两颗树的直径中间点连起来。
				rn = max(ceil(1.0*r1/2) + ceil(1.0*r2/2) + 1, r1, r2)。 
        合成的新树的直径长度。
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5 + 10;
// n个点，m条边，q次询问 
int f[N], R[N], n, m, q, far_node, far_node_deep;// f并查集数组，R[i]代表点i所在树的直径 
vector <int> E[N];// 边 
int Find(int x) { // 查找x点所属的集合 
	if (x == f[x]) return x;
	return f[x] = Find(f[x]); 
}
void Union(int a, int b) {// 合并 
	int fa = Find(a), fb = Find(b);
	if (fa != fb) f[fa] = fb;
	return;
}
void dfs(int now, int father, int deep) {// 求树的直径 
	if (deep > far_node_deep) far_node = now, far_node_deep = deep;
	for (int to : E[now]) 
		if (to != father) 
			dfs(to, now, deep + 1);
	return;
}
void compute(int now) {// 计算点now所在树的直径
	far_node = far_node_deep = 0;
	dfs(now, 0, 0);
	dfs(far_node, 0, 0);
	R[now] = far_node_deep;
}
signed main() {
	cin >> n >> m >> q;
	for (int i = 1;i <= n;i++) f[i] = i;
	for (int i = 1;i <= m;i++) {
		int fr, to;
		cin >> fr >> to;
		E[fr].push_back(to);
		E[to].push_back(fr);
		Union(fr, to);
	}
	// 计算每个树的直径
	for (int i = 1;i <= n;i++) {
		if (f[i] == i) {
			compute(i);
		}
	}
	// q次询问
	int opt, x, y;
	while (q--) {
		cin >> opt;
		if (opt == 1) {
			cin >> x;
			cout << R[Find(x)] << endl;
		} else {
			cin >> x >> y;
			if (Find(x) != Find(y)) {
				int r1 = R[Find(x)];
				int r2 = R[Find(y)];
				Union(x, y);
				R[Find(x)] = max((int)ceil(1.0 * r1 / 2) + (int)ceil(1.0 * r2 / 2) + 1, max(r1, r2));
			}
		}
	} 
	return 0;
}
