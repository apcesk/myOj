#include<iostream>
#include<iomanip>
using namespace std;


// n个同学，传球m次，每个人可以向左或者向右传 

// 问经过m次传球后，回到1号人手里有多少种传递方法 

/**

为了确保第m次传球能够回到1号人手里。
那么在第m-1次时候球应该在n号人或者2号人手里。
f(1,m) = f(n,m-1) + f(2,m-1);状态转移方程
f(x,m) = f(n-x+1, m-1) + f(x+1, m-1);
f(1,0) = 0;
f(2,1) = 1;
f(n,1) = 1;

 
记忆化的递归 

*/ 
int n,m;

int F[31][31];

int main() {
  cin >> n >> m;
  F[2][1] = 1;
  F[n][1] = 1;
	for (int parse_number = 1;parse_number <= m;parse_number++) {// 外层循环传递球的次数 
		for (int man_index = 1;man_index <= n;man_index++) {// 内层循环每个人到手的方法 
			F[man_index][parse_number] = max( F[n-man_index + 1][parse_number - 1] + F[man_index + 1 > n ? 1 : man_index + 1][parse_number - 1], F[man_index][parse_number]);
		}
	}
	cout << F[1][m];
  return 0;
}