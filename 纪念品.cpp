#include<iostream>
#include<cstring>
using namespace std;
int t, n, m;// 未来的天数t，纪念品数量n，初始金币数量m
int price[105][105];// price[i][j] = k代表第i件物品在第j天的价格是k 
//int dp[105][105][105];// dp[i][j][k] = l代表前i天，考虑到第j个物品的时候，
// 手里有k个金币的情况下获得的收益最大值 
int dp[100050]; 
int main() {
	cin >> t >> n >> m;
	for (int i = 1;i <= t;i++) {
		for (int j = 1;j <= n;j++) {
			cin >> price[i][j];// 输入每个纪念品每天的价值 
		}
	}
	int ans = m;// 初始手里有m元
	for (int i = 1;i < t;i++) {// t天每天的最大收益 
		memset(dp, ~0x3f, sizeof dp);
		dp[ans] = ans;
		// 仔细思考一下，如果我知道每天我能够拥有的金币数量
		// 其实等同于确定了每天的背包大小，也能够知道最终获得的最大价值
		// 言外之意：既是把该问题拆成一个t次的完全背包问题。 
		// 枚举j个物品 
		for (int j = 1;j <= n;j++) {
			for (int k = ans;k >= price[i][j];k--) {// 完全背包空间压缩 
				// k-price[i][j]代表在第i天持有第j个纪念品
				// 由于它在第i天的价值是price[i][j]，所以持有它的时候，背包的空间就会缩小
				//  dp[k - price[i][j]]显然是在第i天仍保持持有第j件纪念品的最大收益
				//  dp[k] + price[i + 1][j] - price[i][j] 则是在第i+1天卖掉所持有的第j件纪念品所能获得的最大收益 
				dp[k - price[i][j]] = max(dp[k - price[i][j]], dp[k] + price[i + 1][j] - price[i][j]);
			}
		}
		// 经过上面的循环，此时我们要找到一个最大的收益，
		// 作为明天的背包容积
		int maxn = 0;
		for (int j = 0;j <= ans;j++) {
			maxn = max(dp[j], maxn);
		} 
		ans = maxn;// 重新规划背包大小 
	}
	cout << ans; 
	return 0;
}

