#include<cmath>
#include<iostream>
using namespace std;
// q二维数组代表八皇后的92组解
// row数组是在每一次放置皇后的解的数组
// num代表计算出八皇后的解的数量
int q[92][8], row[8], num = 0;

void queen(int i) {
  // 循环变量
  int j, k;
  // 放置好的皇后数量
  if (i == 8) {
    // 如果已经放置好8个皇后，则记录到q二维数中
    for (j = 0;j < 8;j++)
      q[num][j] = row[j];
    num++;
    return;
  }
  // 将皇后逐一的放入每一列
  for (j = 1;j <= 8;j++) {
    // 判断将皇后放入第j列，会不会和前面已经放好的皇后起冲突
    for (k = 0;k < i;k++) 
      if (row[k] == j || abs(k-i) == abs(row[k]-j)) break;
    // 如果没有问题，则记录当前皇后所放置的列
    if (k == i) {
      row[k] = j;
      queen(i+1);
    }
  }
};

int main() {
  int n,i,b,j;
  queen(0);
  cin>>n;
  for (i = 0;i < n;i++) {
    cin>>b;
    for (j = 0;j < 8;j++)
      cout<<q[b-1][j];
    cout<<endl;
  }
  return 0;
}