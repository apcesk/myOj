#include<iostream>

using namespace std;

// N种菜，M元，要全部花光，共有多少种点菜方式，每种菜只有一份
int N,M;// M <= 10000, N <= 100,其中每种菜价值 <= 1000
int price[101];// 记录每个菜品的价值
int cost[10001]; // cost[i] 代表价值恰为i的时候方案的总数
/**
 * 对于任意一个目标花费来说，每一道菜，都只有两种情况，点|不点
 * 那么对于一个固定的价值M来说，N道菜都进行枚举选或者不选
 * 如果选完了某道菜之后，剩余的价值为0，则说明当前价值t的点菜方案+1
 */ 
int main() {
  cin>>N>>M;
  int i,j;
  for (i = 1;i <= N;i++) {
    // 输入每个菜品的价格
    cin>>price[i]; 
  }
  cost[0] = 1;
  // 共有N种菜，每种菜都可能选或不选
  for (i = 1;i <= N;i++) {
    // 价值共M，
    for (j = M;j >= price[i];j--) {
      if (j >= price[i]) // 如果可以点i这道菜
        cost[j] += cost[j - price[i]];
    }
  }
  cout<<cost[M];
}