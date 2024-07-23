#include<cstdio>

using namespace std;
const int N = 1e6 + 10;
int n, y, z;// 两个长度为n的数组，y是要变换的数字
int a[N],b[N], c[N << 1];
int main() {
  scanf("%d%d%d", &n, &y, &z);
  for (int i = 1;i <= n;i++) {scanf("%d", &a[i]); a[i] = a[i] == y;}
  for (int i = 1;i <= n;i++) {scanf("%d", &b[i]); b[i] = b[i] == y;}
  // 希望y尽可能挨在一起
  bool now = true;// 标记现在的状态，是y还是非y,true为y，false 为非y
  // 把两个数组合并, diff表示不同的段数
  int idx_a = 0, idx_b = 0, diff = 0;
  while(1) {
    if(!now) diff++;
    while(a[idx_a + 1] == now && idx_a + 1 <= n) idx_a++;
    while(b[idx_b + 1] == now && idx_b + 1 <= n) idx_b++;
    // 此时二者把自己相同的部分已经尽可能的提出来
    if (idx_a == n && idx_a == idx_b) break;// 合并完毕
    // 下一段要合并的内容
    now = !now;
  }
  if (!diff) {
    // cout << 0;
    printf("0\n");
  } else if (diff - 1 >= z) {
    printf("%d\n", diff - z);
  } else {
    printf("1");
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