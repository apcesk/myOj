#include<iostream>

using namespace std;

int cpu[1001];
int M, N;// M代表寄存器的大小， N代表单词的长度
bool check_in(int word) {
  for (int i = 0;i < M;i++) if (word == cpu[i]) return true;
  return false;
}
int main() {
  // 有个M和N
  int word; // word代表每个单词
  int sum = 0;
  int start_cpu = 0;
  scanf("%d %d", &M, &N);
  for (int i = 1;i <= N;i++) {
    scanf("%d", &word);
    // 检查单词是否在cpu中存在
    if (!check_in(word)) {
      sum++;
      // 把查的这个单词写入cpu
      cpu[start_cpu] = word;
      start_cpu++;
      start_cpu = start_cpu % M;// 让cpu寄存成环
    }
  }
  printf("%d\n", sum);
  return 0;// 分治
}