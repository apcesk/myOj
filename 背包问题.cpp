/*
 * @Author: apcesk
 * @Date: 2021-02-20 09:53:41
 * @LastEditTime: 2021-02-20 10:39:33
 * @LastEditors: Please set LastEditors
 * @Description: 例题
 * @FilePath: 背包问题.cpp
 */
/**
 * 物品 w[i] 代表第i件物品的重量
 * 价值 v[i] 代表第i件物品的价值
 * 包裹的容积是V
 * 物品的数量是N
 * f[i][v](表示前i件物品恰放入一个容量为v的背包可以获得的最大价值)
 * f[i][v] = max{f[i - 1][v], f[i - 1][v + w[i]] + v[i]} 状态转移方程
 * 压缩空间 
 * f[v] = max{f[v], f[v - w[i]] + v[i]}
 */
#include<cstdio>
#include<algorithm>
using namespace std;
// a每场考试答题的数目，b每场考试题目总数
int a[1005], b[1005], n, k;
// y每场考试的平均分。
double y[1005];
/**
 * @description: 
 * @param {double} v
 * @return {*}
 */
bool Check(double v) {
  // v代表平均分，通过v*b[i]就可得知，想要达到该平均分，需要答对几道题
  // 而 a[i] - v * b[i] 则意味着距离v这个平均分，差距是多少道题，可能是正数可能是负数
  for (int i = 0;i < n;i++)
    y[i] = a[i] - v * b[i];
  sort(y, y + n);
  double sum = 0;
  // 将以v为平均分的总和进行累加，得出实际得分可以比这个平均分更大，或者比这个平均分更小
  // 然后使得v更贴近最大值
  for (int i = k;i < n;i++) 
    sum += y[i];
  // 如果sum > 0 则说明平均分可以更高，反之则说明达不到该平均分。
  if (sum >= 0) return true;
  return false;
}
/**
 * @description: 
 * @param {double} left
 * @param {double} right
 * @return {*}
 */
double BinarySearch(double left, double right) {
  while (right - left > 1e-4) {
    double mid = left + (right - left) / 2;
    if (Check(mid))
      left = mid;
    else 
      right = mid;
  }
  return left;
}

int main(){
  while (scanf("%d%d", &n, &k)) {
    if (n == 0 && k == 0) break;
    for (int i = 0;i < n;i++)
      scanf("%d", &a[i]);
    for (int i = 0;i < n;i++)
      scanf("%d", &b[i]);
    printf("%.0lf\n", 100 * BinarySearch(0, 1));
  }
  return 0;
}