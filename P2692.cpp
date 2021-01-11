/**
 * 核心思路
 * 如果开一个很大的数组(5000*5000)，使用暴力的算法，可能会超时。
 * 对于结果的统计，只要该格子所在的行被男生打扫过或者所在的列被女生打扫过，则说明这个格子是被打扫过的。
 * 因此只需要行数组和列数组即可。
 * 具体代码在下面
 */
#include<iostream>

using namespace std;
// 男生打扫的行
bool hang[5001];
// 女生打扫的列
bool lie[5001];
int main() {
  // 输入操场总大小和男女生数量
  int N,M,B,G;
  cin>>N>>M>>B>>G;
  int s,e;
  // 男生进行打扫
  for (int i = 1;i <= B;++i) {
    cin>>s>>e;
    while (s<=e) {
      hang[s] = 1;
      s++;
    }
  }
  // 女生进行打扫
  for (int i = 1;i <= G;++i) {
    cin>>s>>e;
    while (s<=e) {
      lie[s] = 1;
      s++;
    }
  }
  // 没打扫的数量
  int cnt = 0;
  for (int i = 1;i <= N;++i) {
    for (int j = 1;j <= M;++j) {
      // 如果行列都没有被标记，则说明没打扫。
      if (!hang[i] && !lie[j]) {
        cnt++;
      }
    }
  }
  // 输出：总量 - 没打扫的量 = 打扫的量
  cout<<N*M-cnt<<endl;
}