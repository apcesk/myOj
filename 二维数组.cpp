#include <iostream>
#include<iomanip>
using namespace std;
const int n = 3, m = 5;

int main(){
  int a[n + 1][m + 1], b[101][4], k = 0;
  for (int i = 1; i <= n; ++i) //矩阵初始
    for (int j = 1; j <= m; ++j) 
      cin >> a[i][j];
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (a[i][j] != 0) //找到非零值，存储
      {
        ++k;
        b[k][1] = i;
        b[k][2] = j;
        b[k][3] = a[i][j];
      }
  for (int i = 1; i <= k; ++i) //输出
  {
    for (int j = 1; j <= 3; ++j)
      cout<< setw(3) << b[i][j];
    cout << endl;
  }
    return 0;
}
