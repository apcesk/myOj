#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4 + 10, M = 1e2 + 10, MOD = 20123;
// a[i][0] 代表第i层有多少个可以上楼的楼梯数
// a[i][j] = 1(j >= 1) 代表第i层第j个编号的房间可以上楼
// num[i][j] = k代表第i层第j个房间的编号是k 
int n, m, a[N][M], num[N][M], ans = 0, now;
signed main() {
	// step 1、读题、声明变量
	// step 2、输入
	scanf("%lld%lld", &n, &m);
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			scanf("%lld%lld", &a[i][j], &num[i][j]);
			if (a[i][j]) a[i][0]++;// 存储能够上楼的楼梯数 
		}
	}
	// step 3、处理
	cin >> now; // now代表当前的房间编号 
	now += 1;// 偏移一个单位
	for (int i = 1;i <= n;i++) {
		ans += num[i][now];// 当前所在的房间编号增加上 
		ans %= MOD;// 求余 
		int x = num[i][now] % a[i][0] + a[i][0];
		now--;// 实际所在的房间编号要-1 
		while (x) {
			now++;// 	
			if (now > m) now = 1;
			if (a[i][now]) x--;
		}
	} 
	// step 4、输出
	cout << ans % MOD;
	return 0;
}
