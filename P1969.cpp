#include<iostream>
using namespace std;
#define int long long
/**
	1、初始高度都为0，最终每一块积木都到达给定的高度。 问最少的操作次数 
	2、每次只能选择一个L到R的区间，使得每个积木高度增加1
	-----------------
	2 3 4 1 2
	// 填充到1高度，区域个数为1个。
	// 填充到2高度，区域个数为2个
	// 填充到3高度，区域个数为1个
	// 填充到4高度，区域个数为1个。
	总操作5次 
	对于一个升序的区间，则其填充的次数一定是该区间的最大值。（易证）
	这个升序区间所带来的操作次数是
		aj - ai (j > i) && (aj > ai) 
*/
signed main() {
	int n;
	cin >> n;
	int t;
	int last = 0, // 上一个高度
		ans = 0;// 答案 
	for (int i = 1;i <= n;i++) {
		cin >> t;
		if (t > last) ans += t - last;
		last = t;
	}
	cout << ans;
	return 0;
}
