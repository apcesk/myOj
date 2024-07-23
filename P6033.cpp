#include<cstdio>
#include<queue>
using namespace std;
#define int long long 
const int MAXN = 1e5 + 10, N = 1e7 + 10;
const int INF = 1e12 + 10;
// 数字的个数n = 1e7
// 数字的范围ai = 1e5
// 桶排序效率更高
int tong[MAXN], n;
// 合并过程考虑blash数集
// int arr1[MAXN], arr2[MAXN];// 爆内存，得用队列
queue <int> q1;// 初始排好序的
queue <int> q2;// 用来把合并的果子放进去的（合并过后的果子一定能有序）
// 不加快读过不去(-_-!!)
void read(int &x) {
  int f = 1; x = 0; char s = getchar();
  while(s < '0' || s > '9') {if (s == '-') f = -1;s=getchar();}
  while(s >= '0' && s <= '9') {x = x * 10 + s - '0';s = getchar();}
  x *= f;
}

signed main() {
  // scanf("%lld", &n);
  read(n);
  int temp, limit = 0;
  for (int i = 1;i <= n;i++) {
    // scanf("%lld", &temp);
    read(temp);
    tong[temp]++;
    limit = max(limit, temp);
  }
  // 排好序，需要O(n)的时间完成合并动作
  for (int i = 1;i <= limit;i++) {
    while(tong[i]--) q1.push(i);
  }
  int ans = 0;
  int min1 = INF, min2 = INF, q1_max = limit, q2_max = 0;
  while (--n) {
    min1 = INF, min2 = INF;
    // 找两个最小的
    if (!q1.empty() && !q2.empty()) {
      if (q1.front() < q2.front()) {
        min1 = q1.front();
        q1.pop();
      } else {
        min1 = q2.front();
        q2.pop();
      }
    } else if (q1.empty()) {
      min1 = q2.front();
      q2.pop();
    } else if (q2.empty()) {
      min1 = q1.front();
      q1.pop();
    }
    if (!q1.empty() && !q2.empty()) {
      if (q1.front() < q2.front()) {
        min2 = q1.front();
        q1.pop();
      } else {
        min2 = q2.front();
        q2.pop();
      }
    } else if (q1.empty()) {
      min2 = q2.front();
      q2.pop();
    } else if (q2.empty()) {
      min2 = q1.front();
      q1.pop();
    }
  // printf("...\n");
    ans += min1 + min2;
    if (min1 + min2 > q1_max) {
      q1.push(min1 + min2);
      q1_max = min1 + min2;
    } else {
      q2.push(min1 + min2);
      q2_max = min1 + min2;
    }
    // printf("min1: %lld, min2: %lld\n", min1, min2);
  }
  printf("%lld", ans);
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