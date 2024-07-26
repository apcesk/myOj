#include<iostream>
#include<cstdio>
using namespace std;
#define int long long 
const int maxn=1010;
int n,H,K;//n个怪物，H的生命值，K的体力值
int dp[310][310];// dp[j][k] = l代表生命限定为j，体力限定为k所获得金币的最大值
signed main(){
	cin>>n>>H>>K;
	--H;
	for(int i=1;i<=n;++i){// 枚举每个任务
		int x,y,z;// 消耗x生命值和k的体力值，获得z的金币
		scanf("%lld%lld%lld",&x,&y,&z);
		for (int j = H;j >= x;j--) {
			for (int k = K;k >= 0;k--) {
				if (k >= y) {// 此时直接消耗体力值即可
					dp[j][k] = max(dp[j][k], dp[j][k - y] + z);
				}
				if (k < y && j>= x + y - k ) {// 体力值不够
					dp[j][k] = max(dp[j][k], dp[j - (x + y - k)][0] + z);
				}
			}
		}
	}
	cout << dp[H][K];
	return 0;
}
