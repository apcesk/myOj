#include<bits/stdc++.h>
using namespace std;
#define int long long
/**
	前置：树的重心 

	
	树上的路径分为两种
		1、经过根节点的路径
		2、不经过根节点的路径 
	--对于经过根节点的路径，可以预处理出每个点到根的路径，
	然后dis[u,v] = dis[u,root] + dis[v,root]
	注意排除不合法的路径(u,v)两点在同一颗子树内部，先把前面子树中
	各点到根的距离存入一个队列q[i]，并且开一个布尔数组存队列中的距离judge[q[i]]
	再枚举当前子树中各点到根的距离dis[j]，若询问距离k与dis[j]的差存在，
	即judge[k-dis[j]]为真，说明此解合法。 
	
	--对于不经过根节点的路径，可以对子树不断分治，转化为经过根节点的路径。
	
	如果是一颗均衡的树，分治次数是O(logn)，每次分治后跑n个点，询问m次，
	每次判定答案是O(nm)，时间复杂度是O(nmlogn)。
	
	如果是一条链，且从链的一段开始分治的话，分治次数退化成O(n)，时间复杂度是O(n^2*m)
	
	
	解：分治前，对每颗子树先找出重心做根即可。 
	
	
	
	概括总结：
	点分治四步：
		1、找出树的重心做根 -> getroot()
		2、求出子树中的各点到根的距离 -> getdis()
		3、对当前树统计答案 -> calc()
		4、分治各个子树，重复以上操作  -> divide() 
*/
const int N = 1e4 + 10, INF = 1e7 + 10;
struct Edge {// 链式前向星存储边 
	// value是边长，to是该边的终点，next是该边的上一条边 
	int value, to, next;
} edges[N << 1];
int head[N], idx;// 加边用的数据内容，前向星存储
// del代表当前点是否被删除，siz记录以点为根的子树大小， 
int del[N], siz[N], mxs, sum, root;// 求根用
int dis[N], d[N], cnt;// 求距离
int ans[N], q[INF], judge[INF];// 求路径
int n, m, ask[N];
// 加边函数 
void add(int from, int len, int to) {
	edges[++idx].value = len;// 记录边长
	edges[idx].to = to;// 记录该边的终点 
	edges[idx].next = head[from];// 记录该边的吓一跳边 
	head[from] = idx;// 更新以from作为起点的边的下标 
}
// 求根函数(找到重心的函数) 
void getroot(int now, int fa) {
	siz[now] = 1;// 当前now是该树上的一个节点
	int s = 0;// 统计该节点下的子树数量
	// 遍历该点下的每个子树 
	for (int i = head[now];i;i = edges[i].next) {
		int to = edges[i].to;
		// 如果是父节点，或者是已经计算过的点，则跳过 
		if (to == fa || del[to]) continue;
		getroot(to, now);// 继续递归
		siz[now] += siz[to];// 统计该树的子树个数
		s = max(s, siz[to]);// 记录以now为根节点，最大的子树个数 
	}
	// 看now是否是最大的子树，如果不是，则剩余的另一部分是最大的子树 
	s = max(s, sum - siz[now]);
	// 重心概念仔细理解：最大子树最小
	// 如果now作为数根，最大子树更下，则让now成为树根 
	if (s < mxs) mxs = s, root = now;
}
// 计算距离
void getdis(int now, int fa) {
	dis[++cnt] = d[now];
	for (int i = head[now];i;i = edges[i].next) {
		int to = edges[i].to;
		if (to == fa || del[to]) continue;
		d[to] = d[now] + edges[i].value;
		getdis(to, now);
	}
} 

// 计算答案
void calc(int now) {
	judge[0] = 1;
	int p = 0;
	// 计算经过根now的路径
	for (int i = head[now];i;i = edges[i].next) {
		int to = edges[i].to;
		if (del[to]) continue;
		// 求出子树to的各点到now的距离
		cnt = 0;
		d[to] = edges[i].value;
		getdis(to, now);
		// 枚举距离和询问，判定答案
		for (int j = 1;j <= cnt;j++) {
			for (int k = 1;k <= m;k++) {
				if (ask[k] >= dis[j]) {
					ans[k] = ans[k] || judge[ask[k] - dis[j]];
				}
			}
		} 
		// 记录合法距离
		for (int j = 1;j <= cnt;j++) {
			if(dis[j] < INF) {
				q[++p] = dis[j], judge[q[p]] = 1;
			}
		} 
	} 
	// 清空距离数组
	for (int i = 1;i <= p;i++)
		judge[q[i]] = 0; 
} 
// 分治
void divide(int now) {
	// 计算经过根节点的路径
	calc(now);
	// 对当前节点的子树进行分治
	del[now] = 1;// 删除该点
	for (int i = head[now];i;i = edges[i].next) {
		int to = edges[i].to;
		if (del[to]) continue;
		mxs = sum = siz[to];
		getroot(to, 0);// 求根
		divide(root);// 分治
	} 
}

signed main() {
	// step 1、读题、声明变量
	// step 2、输入
	scanf("%lld%lld", &n, &m);
	for (int i = 1;i < n;i++) {
		int from, to, value;
		scanf("%lld%lld%lld", &from, &to, &value);
		add(from, value, to);
		add(to, value, from);
	} 
	for (int i = 1;i <= m;i++) {
		scanf("%lld", &ask[i]);
	}
	// step 3、处理
	mxs = sum = n;// 找重心最准备
	getroot(1, 0);// 找到整颗树的重心
	getroot(root, 0);// 重新计算siz数组
	divide(root);// 根节点开始分治
	// step 4、输出
	for (int i = 1;i <= m;i++)
		if (ans[i]) cout << "AYE" << endl;
		else cout << "NAY" << endl;
	return 0;
}
