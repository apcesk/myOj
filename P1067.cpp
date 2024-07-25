#include<iostream>

using namespace std;
// xs 是系数，n是次方 
bool first = true;// 是否是第一项 
void func(int xs, int n) {
	if (xs == 0) return;// 系数为0，什么也不做
	if (xs > 0 && !first) cout << '+';// 系数>0，且不是第一项，由加号链接
	if (xs != 1 && xs != -1) cout << xs;// 系数不是1，输出系数的值
	else {// 此时系数为1
		if (xs == -1 && n != 0) cout << '-';// 系数是-1，给出负号
		else if(n == 0 && xs == 1) cout << 1;// 常数项切系数为1
		else if(n == 0 && xs == -1) cout << -1;// 常数项切系数为-1
	}
	if (n != 0 && n != 1) {
		cout << "x^" << n;
	} else if (n == 1) {
		cout << "x";
	}
	first = false;
	
}
int main() {
	int n, t;
	cin >> n;
	for (int i = 0;i <= n;i++) {
		cin >> t;
		func(t, n - i);
	}

	return 0;
}

