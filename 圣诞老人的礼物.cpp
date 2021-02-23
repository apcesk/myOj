/*
 * @Author: your name
 * @Date: 2021-02-20 13:57:27
 * @LastEditTime: 2021-02-20 13:58:39
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \myOj\圣诞老人的礼物.cpp
 */
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

#define MAXN (100+10)
// 每箱糖果
struct Box{
  int v,w;// 价值和重量
  double density;// 单位重量的价值
};
int n,w;
Box boxes[MAXN];
double totw, totv;

// 箱子按单位重量价值排序
bool operator < (const Box &a, const Box &b) {
  return a.density < b.density;
}

int main(){
  scanf("%d%d", &n, &w);
  for (int i = 0;i < n;i++) {
    scanf("%d%d", &boxes[i].v, &boxes[i].w);
    boxes[i].density = 1.0 * boxes[i].v / boxes[i].w;
  }
  sort(boxes, boxes + n);
  totw = totv = 0;
  for (int i = n - 1;i >= 0;--i) {
    if (totw + boxes[i].w <= w) {
      totw += boxes[i].w;
      totv += boxes[i].v;
    } else {
      totv += boxes[i].density * (w - totw);
      totw = w;
      break;
    }
  }
  printf("%.1lf\n", totv);
  return 0;
}
