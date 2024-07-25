#include<string>
#include<iostream>
#include<iomanip>
using namespace std;
char c, a;
// x代表当前输入的系数的值 
int f = 1, now = 1, k, b, x;// f代表当前的系数
// now代表当前输入相对于等号的位置，等于1代表输入的是
// 等号左边
bool r;// 标识是否有数字的读入，主要为了处理+0x、-0x的情况
 
int main() {
    while (cin >> c) {
    	if (c == '-') {// 当前输入的是负号 
    		b += now * f * x;// 默认是常数项的值 
    		x = 0;// 重新计算系数的值 
    		f = -1;// 由于输入的是负号，则f 
    		r = 0;// 重置是否有数字输入的值 
      } else if (c == '+') {// 当前输入的是正号 
        b += now * f * x;
        x = 0;
        f = 1;
        r = 0;
      } else if (c == '=') {// 输入的是等号 
        b += now * f * x;
        x = 0;
        f = 1;
        now = -1;
        r = 0;
      } else if (c >= 'a' && c <= 'z') {
        if (r) {// 此前有数字输入，说明一次项有系数。 
          k += now * f * x;
          x = 0;// 重置系数 
        } else {// 无系数输入，则说明是1
          k += now * f; 
        }
        a = c;
        r = 0;
      } else if (c >= '0' && c <= '9') {
        // 输入的是数字
        x = x * 10 + c - '0'; 
        r = 1;
      }
    }
	// 处理最后的输入
	b += now * f * x;
	double ans = double(-b * 1.0 / k);
	if (ans == -0.0) ans = 0;
	cout << a << '=' << fixed << setprecision(3) << ans;
    return 0;
}