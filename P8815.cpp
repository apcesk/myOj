#include<iostream>
#include<string>
using namespace std;

int main() {
	string str;// 输入的表达式字符串
	int ans = 0;// 当前运算的结果 
	int and_count = 0;// 与运算的短路个数
	int or_count = 0;//或运算的短路个数
	cin >> str;// 输入字符串
	int len = str.length();
	int state = 0;// state = 0代表不处于短路状态，等于1代表处于与短路，等于2代表处于或短路 
	// 无短路的情况 1 & 0 = 0, 1 & 1 = 1, 0 | 1 = 1, 0 | 0 = 0
	// 短路的情况 0 & 1 = 0, 0 & 0 = 0, 1 | 0 = 1, 1 | 1 = 1
	// 与运算短路皆为0，或运算短路皆为1。
	// 与运算短路的逻辑是短路到第一个或运算。
	// 或运算的短路逻辑是短路到第一个右括号 
	for (int i = 0;i < len;i++) {
		if (state == 0) {// 此时属于正常计算 
			if (str[i] == '0') ans = 0;// 正常计算 
			else if (str[i] == '1') ans = 1;// 正常计算
			else if (str[i] == '&' && ans == 0) state = 1, and_count++;// 与运算短路考虑 
			else if (str[i] == '|' && ans == 1) state = 2, or_count++;// 或运算短路 
		} else {// 此时处于短路状态 
			if (state == 1 && str[i] == '&') and_count++;// 继续短路与运算
			else if (state == 2 && str[i] == '|') or_count++;// 继续短路或运算 
			else if (state == 1 && str[i] == '|') state = 0;// 结束与运算短路 
			else if (str[i] == ')') state = 0;// 结束括号内部的短路逻辑
			else if (str[i] == '(') {// 短路子集的小括号 
				int cnt = 1;// 记录当前左括号的数量 
				while (cnt != 0) {
					i++;
					if (str[i] == ')') cnt--;
					else if (str[i] == '(') cnt++;
				} 
			} 
		} 
	} 
	cout << ans << endl << and_count << ' ' << or_count;
	return 0;
}

