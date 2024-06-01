#include<iostream>
#include<algorithm>
using namespace std;
int n, k;// n个点，k个可以填补的点
struct point {
	int x, y;// x,y坐标 
} arr[1010]; 
bool cmp(point a, point b) {
	if (a.x != b.x) {
		return a.x < b.x;
	} else {
		return a.y < b.y;
	}
}
// dp[i][j] = k代表第i个点借助j个填补点可以形成的最大长度为k 
int dp[555][200];
int main() {
	cin >> n >> k;
	for (int i = 1;i <= n;i++) {
		cin >> arr[i].x >> arr[i].y;
	}
	sort(arr + 1, arr + 1 + n, cmp);
	// 考虑边界，任意一个点借助k个填补点，都能够成为k+1长度的序列
	for (int i = 1;i <= n;i++) 
		for (int j = 0;j <= k;j++) 
			dp[i][j] = 1 + j;
	// 排序完成过后，初始化也完成，接下来考虑状态转移过程
	for (int i = 1;i <= n;i++) {// 从第二个点开始 
		for (int j = 1;j < i;j++) {// 前方所有的点 
			// 考虑点i和点j能否构成上升点列
			int dis = arr[i].x + arr[i].y - arr[j].x - arr[j].y;// 点i到点j的欧几里得距离
			if (!(arr[i].x < arr[j].x || arr[i].y < arr[j].y)) {
				// 此时是能构成上升点列的 
				for (int p = 0;p <= k;p++) {
					if (dis == 1) { // 此时两点之间不需要借助点
						dp[i][p] = max(dp[i][p], dp[j][p] + 1); 
					} else if (dis - 1 <= p){// 此时说明可以借助p个点进行连接 
						dp[i][p] = max(dp[j][p - dis + 1] + dis, dp[i][p]);
					} 
				}
			} 
		}
	} 
	// 找到最大值
	int ans = 0;
	for (int i = 1;i <= n;i++) {
		ans = max(ans, dp[i][k]);
	} 
	cout << ans;
	return 0;
}

