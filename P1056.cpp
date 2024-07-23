/**
 * 首先对所有学生按照坐标排序。
 * 然后统计每一行有多少交头接耳。
 * 再统计每一列有多少交头接耳。
 * 最终选出行交头接耳的前l个和列交头接耳的前k个即为答案
 */
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 2e3 + 10;
int n, m;// n行，m列
int d, k, l;// d对同学上课交头接耳，k条横向通道，l条纵向通道
struct stu {
  int x, y;// 一对交头接耳同学
} arr[N];
// 输出k和l的摆放
int lie[N], hang[N];// lie[i] = p 代表第i列，前后交头接耳的同学的个数
int lie_rank[N], hang_rank[N];
bool cmp_lie(int a, int b) {
  if (lie[a] != lie[b]) return lie[a] > lie[b];
  else return a < b;
}
bool cmp_hang(int a, int b) {
  if (hang[a] != hang[b])
    return hang[a] > hang[b];
  else return a < b;
}
// hang[i] = p 代表第i行，左右交头接耳的同学个数
int main() {
  cin >> n >> m >> k >> l >> d;
  int x1, y1, x2, y2;
  // for (int i = 1;i <= n;i++) hang_rank[i] = i;
  // for (int i = 1;i <= m;i++) lie_rank[i] = i;

  for (int i = 1;i <= d;i++) {
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 == x2) {
      lie[min(y1, y2)]++;
    } else if (y1 == y2){
      hang[min(x1, x2)]++;
    }
  }
  for (int i = 1;i <= k;i++) {
    int maxn = 0;
    for (int j = 0;j <= n;j++) {
      if (hang[j] > hang[maxn]) {
        maxn = j;
      }
    }
    hang_rank[maxn] = 1;
    hang[maxn] = 0;
  }
  for (int i = 1;i <= l;i++) {
    int maxn = 0;
    for (int j = 0;j <= m;j++) {
      if (lie[j] > lie[maxn]) {
        maxn = j;
      }
    }
    lie_rank[maxn] = 1;
    lie[maxn] = 0;
  }
  // sort(lie_rank, lie_rank + 1 + m, cmp_lie);
  // sort(hang_rank, hang_rank + 1 + n, cmp_hang);
  // cout << "hang_rank: " << endl;
  // for (int i = 1;i <= n;i++) {
  //   cout << hang_rank[i] << ' ';
  // }
  // cout << endl << "lie_rank: " << endl;;
  // for (int i = 1;i <= m;i++) {
  //   cout << lie_rank[i] << ' '; 
  // }
  // cout << endl;
  for (int i = 1;i <= n;i++) {
    if (hang_rank[i])
      cout << i << ' ';
  }
  cout << endl;
  for (int i = 1;i <= m;i++) {
    if (lie_rank[i])
      cout << i << ' ';
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