#include<iostream>

using namespace std;
#define int long long
/*
  每个灯拉动开关可以按照，关-红-黄-绿-蓝-关的顺序变化，最初所有路灯都是关着的。现在有 n 次行动顺序，
  每次标出当前行动的含义以及开始和结束位置。每种行动的具体含义如下：
1 s t：把编号 s 灯到编号 t 灯之间所有的灯（包含编号 s 灯和编号 t 灯）都变成关闭状态；
2 s t：把编号 s 灯到编号 t 灯之间所有的开着的灯（包含编号 s 灯和编号 t 灯）都变成红色或绿色，只要灯变成红色或绿色时就停止拉动开关；
3 s t：把编号 s 灯到编号 t 灯之间所有的灯（包含编号 s 灯和编号 t 灯）都变成蓝色或黄色，只要灯变成蓝色或黄色时就停止拉动开关；
4 s t：把编号 s 灯到编号 t 灯之间所有的灯（包含编号 s 灯和编号 t 灯），按照是第几个灯按几下的顺序拉动开关，
本次行动中位置 s 上的灯是第一个灯，位置 t 上的灯是最后一个灯。
请计算：当所有行动顺序结束后处于关闭状态的灯的数量。
*/
// 灯的操作是五次一个循环
const int N = 1e6 + 10;
const int OFF = 0, RED = 1, YELLOW = 2, GREEN = 3, BLUE = 4;
int L, n;// 有L盏灯，n次操作
// 先暴力
int light[N];
signed main() {
  cin >> L >> n;
  int op, s, t;
  while(n--) {
    cin >> op >> s >> t;
    if (op == 1) {// 从s到t所有灯都关闭
      for (int i = s;i <= t;i++) light[i] = 0;
    } else if (op == 2) {// 从s到t所有的灯都变成红色或绿色，只要灯变成红色或者绿色时就停止拉动开关。
      for (int i = s;i <= t;i++) {
        if (light[i] && light[i] % 2 == 0) light[i] += 1;
      }
    } else if (op == 3) {// 从s到t所有的灯都变成蓝色或黄色，只要灯变成蓝色或者黄色时就停止拉动开关
      for (int i = s;i <= t;i++) {
          if (light[i] == 0 || light[i] == 1) light[i] = 2;
          else if (light[i] == 3) light[i] = 4;
      }
    } else if (op == 4) {// 从s到t之间的所有灯按照时第几个灯按几下的顺序拉动开关
        for (int i = s;i <= t;i++) {
          light[i] = (light[i] + (i - s + 1)) % 5;
        }
    }
  }
  int cnt = 0;
  for (int i = 0;i <= L;i++) {
    if (light[i]) cnt++;
    // cout << light[i] << ' ';
  }
  cout << cnt;
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