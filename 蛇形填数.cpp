#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 10;
int a[MAXN][MAXN];
// 无返回值类型的函数
int main() // 函数返回值的类型， ()参数列表
{
  int n, x = 0, y = n - 1, tot = 1;
  cin >> n;
  a[x][y] = 1; // 初始化画笔的位置
  // 把画笔的值初始化
  while (tot < n * n)
  {
    while (x + 1 < n && !a[x + 1][y])
      a[++x][y] = ++tot;
    while (y - 1 >= 0 && !a[x][y - 1])
      a[x][--y] = ++tot;
    while (x - 1 >= 0 && !a[x - 1][y])
      a[--x][y] = ++tot;
    while (y + 1 < n && !a[x][y + 1])
      a[x][++y] = ++tot;
  }
  for (x = 0; x < n; ++x)
  {
    for (y = 0; y < n; ++y)
      printf("%3d", a[x][y]);
    printf("\n");
  }
  return 0;
}