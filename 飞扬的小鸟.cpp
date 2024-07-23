#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int N = 1e4 + 10;
const int INF = 0x3f3f3f3f;
// 长为n，高为m，k个管道。
// up[i]代表在第i个点上升高度。
// down[i]代表在第i个点下降高度
// low[i],high[i]代表在x坐标为i的情况下，最低和最高的可达高度 
int n, m, k, up[N], down[N], low[N], high[N];
int dp[N][2024];
bool flag[N];
int main() {
	// step 1、读题、声明变量
	// step 2、输入
	cin >> n >> m >> k;
	// step 3、处理
	for (int i = 1;i <= n;i++) 
		cin >> up[i] >> down[i];
	// 处理初始化所有的位置均为能通过 
	for (int i = 1;i <= n;i++) {
		high[i] = m;
		low[i] = 1;
	} 
	// 输入处理所有的管道
	int p, l, h;
	for (int i = 1;i <= k;i++) {
		cin >> p >> l >> h;// p位置的管道 
		flag[p] = 1;// p位置有管道 
		low[p] = l + 1;// p位置能够最低的位置 
		high[p] = h - 1;// p位置能够最高的位置 
	}
	memset(dp, 0x3f, sizeof dp);
	for (int i = 1;i <= m;i++) dp[0][i] = 0;// 初始可以在任意位置 
	for (int i = 1;i <= n;i++) {// 枚举所有的x坐标 
		// 上升：可以多次点击，完全背包 
		for (int j = up[i] + 1;j <= up[i] + m;j++)// 要在x坐标为i的时候，上升到j为止 
			dp[i][j] = min(dp[i - 1][j - up[i]] + 1, dp[i][j - up[i]] + 1);
		// 注意飞越界的情况，飞越界处理 
		for (int j = m + 1;j <= up[i] + m;j++) dp[i][m] = min(dp[i][m], dp[i][j]);
		// 下降，因为最高是m，那么最多下降到m-y[i] 
		for (int j = 1;j <= m - down[i];j++) dp[i][j] = min(dp[i][j], dp[i - 1][j + down[i]]);
		// 处理被管道挡住的情况
		for (int j = 1;j < low[i];j++) dp[i][j] = INF;
		for (int j = high[i] + 1;j <= m;j++) dp[i][j] = INF;
	}
	// step 4、输出
	int ans = INF;
	for (int i = 1;i <= m;i++) ans = min(ans, dp[n][i]);
	if (ans < INF) {// 能通过就直接输出答案 
		cout << 1 << endl << ans << endl;
		return 0;
	}
	ans = 0;// 统计能够通过多少管道
	int i, j;
	for (i = n;i >= 1;i--) {
		for (j = 1;j <= m;j++)
			if (dp[i][j] < INF) break;// 找到能飞到最远的位置
		if (j <= m) break;
	}
	for (j = 1;j <= i;j++) 
		if (flag[j]) ans++;
	cout << 0 << endl << ans;
	return 0;
}


/**
* @runId: 3338884
* @language: C++
* @author: cdtzhangyc
* @submitTime: 2024-04-17 14:07:37
*/

/**
* @runId: 4144501
* @language: C++
* @author: cdtzhangyc
* @submitTime: 2024-06-07 20:12:19
*/