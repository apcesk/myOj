#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

#define MAXN (1000+10)

// 线段两端
struct Node{
  double left, right;
};

int T,n,d;
Node s[MAXN];
bool operator < (const Node &a, const Node &b) {
  return a.left < b.left;
}

// 求解每个case
int Solve() {
  int ans;
  double now;
  // 按左端点排序
  sort(s, s + n);
  // 若当前线段与目前集合中的线段没有交集，则加入一个新雷达。
  ans = 1;now = s[0].right;
  for (int i = 1;i < n;i++) {
    if (s[i].left <= now) now = min(now, s[i].right);
    else {
      ++ans;
      now = s[i].right;
    }
  }
  return ans;
}

int main() {
  int x,y;
  bool flag;
  T = 0;
  while (true) {
    ++T;
    scanf("%d%d", &n, &d);
    if (n == 0 && d == 0) break;
    // 读入
    flag = true;
    for (int i = 0;i < n;i++) {
      scanf("%d%d", &x, &y);
      if (y > d) flag = false;
      else {
        s[i].left = x - sqrt(d * d - y * y);
        s[i].right = x + sqrt(d * d - y * y);
      }
    }
    // 若有小岛距离x轴大于d，则输出-1
      if (flag) printf("Case 5d:%d\n", T, Solve());
      else printf("Case %d: -1\n", T);
  }
  return 0;
}