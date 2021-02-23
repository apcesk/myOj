#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int n, maxV, tot;

int main() {
  int v;
  while (scanf("%d", &v) != EOF) {
    maxV = 0;tot = 0;
    for (int i = 0;i < n;i++) {
      scanf("%d", &v);
      maxV = max(maxV, v);
      tot += v;
    }
    // 直接判断最大值是偶大于剩余电池电量之和
    // 如果是，则答案为剩余电池电量之和
    // 否则，则为总和的一半
    if (maxV  > tot - maxV) printf("%.1lf\n", double(tot - maxV));
    else printf("%.1lf\n", tot/2.0);
  }
}