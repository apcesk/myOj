// #include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define int long long
/**
	n个矿石。每个矿石有重量w和价值v两个属性
	矿石检验的流程
	1、给定m个区间[l,r]
	2、选出一个参数W
	3、对于一个区间[l, r]计算矿石在这个区间上的检验值y
		=sum[wj](l<=j<=r && wj >= W) * sum[vj] ( l<=j<=r && wj >= W)
		这批矿石的检验结果y为各个区间的检验值之和。
		若这批狂财产的检验结果与所给的标准值s相差
		太多，就需要再去检验另一批矿产。
		想要通过调整参数W的值，
		让检验结果尽可能的靠近标准值s，
		即使得|s-y|最小，要求出最小值。
		【像二分】 
----
	先暴力 
*/
const int N = 2e5 + 10;
int n, m, s;// n个矿石，m个区间，标准值s 
int w[N], v[N], l[N], r[N];// w重量，v价值
int sumw[N], sumv[N];
// l,r是区间
int check(int mid) {
	// 前缀和走一下计算
	for (int i = 1;i <= n;i++) {
		sumw[i] = sumv[i] = 0;
		if (w[i] >= mid) {
			sumw[i] = 1 + sumw[i - 1];
			sumv[i] = v[i] + sumv[i - 1];
		} else {
			sumw[i] = sumw[i - 1];
			sumv[i] = sumv[i - 1];
		}
	}
	// 对于m个区间求和算
	int tot = 0;
	for (int i = 1;i <= m;i++) {
		tot += (sumw[r[i]] - sumw[l[i] - 1]) * (sumv[r[i]] - sumv[l[i] - 1]);
	}
	return tot - s;
}
signed main() {
//	freopen("P1314_1.in", "r", stdin);
//	freopen("01.out", "w", stdout);
	cin >> n >> m >> s;
	for (int i = 1;i <= n;i++) {
		cin >> w[i] >> v[i];
	} 
	for (int i = 1;i <= m;i++) {
		cin >> l[i] >> r[i];
	}
	int L = 0, R = 1e6, MID, ans = 0, cha = 1e12 + 10;
	while (L <= R) {
		MID = (L + R) >> 1;
		// 以MID作为W的选值，W越大，则能选的越少
		int t = check(MID);
//		printf("check: %lld\n", t);
//		printf("MID: %lld\n", MID);
		int te = abs(t);
		if (te < cha) {
			cha = te;
			ans = MID;
		}
		if (t > 0) {// t大，说明y > s，此时要让y变小，也就是 
			L = MID + 1;
		} else if (t == 0) {// y == s，最优解，一定能最优解 
			break;
		} else {// y < s
			R = MID - 1;
		}
	}
	cout << cha;
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}