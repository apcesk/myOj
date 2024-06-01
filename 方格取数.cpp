#include<iostream>
#include<cstring>
using namespace std;
//int up[1010][1010];
//int down[1010][1010];
long long up[1010],down[1010];
long long arr[1010][1010];
//int dp[1010][1010]; 压缩
long long dp[1010];//  
int n, m;
int main() {
	cin >> n >> m;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			cin >> arr[i][j];
		}
	}
	dp[1] = arr[1][1];
	for (int i = 2;i <= n;i++) dp[i] = dp[i-1]+arr[i][1];
	for (int j = 2;j < m;j++) {
		memset(down, 0, sizeof down);
		memset(up, 0, sizeof up);
		down[1] = dp[1] + arr[1][j];
		up[n] = dp[n] + arr[n][j];
		for (int i = 2;i <= n;i++) down[i] = max(dp[i], down[i - 1]) + arr[i][j];
		for (int i = n - 1;i >= 1;i--) up[i] = max(dp[i], up[i + 1]) + arr[i][j];
		for (int i = 1;i <= n;i++) dp[i] = max(down[i], up[i]);
	}
	dp[1] += arr[1][m];
	for (int i = 2;i <= n;i++) dp[i] = max(dp[i], dp[i-1]) + arr[i][m];
	cout << dp[n];
	return 0;
}

