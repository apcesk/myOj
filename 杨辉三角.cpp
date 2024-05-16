#include<iostream>
#include<iomanip>
using namespace std;

int arr[11][11];
int main () {
  // 输入第一行杨辉三角的数据
  arr[1][1] = 1;
  for (int i = 2;i <= 10;i++) {
    for (int j = 1;j <= 10;j++) {
      arr[i][j] = arr[i-1][j] + arr[i-1][j-1];
    }
  }
  for (int i = 1;i <= 10;i++) {
    for (int j = 1;j <= 10;j++) {
      if (arr[i][j] == 0) break;
      cout << setw(5) << arr[i][j];
    }
    cout << endl;
  }
  return 0;
}