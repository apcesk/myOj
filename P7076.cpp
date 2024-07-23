#include<iostream>
#include<vector>
using namespace std;
const int N = 1e6 + 10;
#define int unsigned long long
// 2^k次方重不同的动物，
// m条要求，n种动物
// 饲料一共有c种
int n, m, c, k, ans = 0, one = 1;
// int arr[N];// 存放n个动物
signed main() {
  cin >> n >> m >> c >> k;
  // n个动物的编号
  // 只需要统计每个动物的二进制位包含的1即可
  int tot = 0, t;
  for(int i = 1;i <= n;i++) {
    cin >> t;
    tot |= t;
  }
  int ask = 0;// 哪些位置有要求
  //表示的第 𝑝𝑗位为 1，则必须购买第 𝑞𝑗种饲料
  int pj, qj;
  for(int i = 1;i <= m;i++) {
    cin >> pj >> qj;
    ask |= (one << pj);
  }
  // 能够饲养某个动物的条件
  // 当且仅当该动物的二进制位上的每个数字对应的饲料，都在数字n上有体现
  for (int i = 0;i < k;i++) {
    // ask >> i 代表第i位有要求
    // tot >> i 代表数字第i位有1
    // 如果第i位上的1没有要求，
    // 或者第i位上的1有要求，且目前动物园中存在第i位上是1的动物，则说明一定养的了
    ans += !((ask >> i) & 1) || ((tot >> i) & 1);
  }
  if (ans == 64 && n == 0) cout << "18446744073709551616";
  else {
    if (ans == 64) {// 说明是2^64-n
      // 结果刚好是-n的无符号表示形式
      cout << -n;
    } else {
      cout << (one << ans) - n;
    }
  } 
  return 0;
}
/**
DDDDD           IIIIII        OOOOOOOO
DD  DD            II          OO    OO
DD   DD           II          OO    OO
DD    DD          II          OO    OO
DD    DD          II          OO    OO
DD    DD          II          OO    OO
DD   DD           II          OO    OO
DD  DD            II          OO    OO
DDDDD           IIIIII        OOOOOOOO
*/