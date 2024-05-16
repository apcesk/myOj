#include<iostream>
using namespace std;
// 输入n个地毯
// 每个地毯，有四个数据，x坐标，y坐标，地毯的边长长和宽
// 最后一个指定的点(a,b)
// 下标则代表地毯的编号
int x[10001], // 代表地毯的x坐标
		y[10001], // 代表地毯的y坐标
		l[10001], // 代表地毯的长度
		w[10001]; // 代表地毯的宽度
// 抽象
int main () {
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> x[i] >> y[i] >> l[i] >> w[i];
	}
	int j,k;
	cin >> j >> k;// 指定的点
	int number = -1;
	// 从第一块地毯开始，到最后一块地毯进行判断
	for (int i = 1;i <= n;i++) {
		// 判断编号为i的地毯，是否覆盖了指定的点j,k
		if (x[i] <= j && j <= x[i] + l[i] &&
				y[i] <= k && k <= y[i] + w[i]) {
					number = i; 
				}
	}
	cout << number << endl;
	return 0;
}