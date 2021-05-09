
#include<iostream>
using namespace std;
bool arr[101][101];
int main(){
  int n;
  int huoba;
  int yingshi;
  cin>>n>>huoba>>yingshi;
  for (int i = 1;i <= huoba;i++) {
    int x,y;
    cin>>x>>y;
    // 火把点亮的位置，包括自身及周围共9个
    // 以及横竖都各多两个
    for (int t = -1; t <= 1;t++) {
      for (int k = -1; k<= 1;k++) {
        if (x+t >= 1 && x+t <= n && y+k >= 1 && y+k <= n)
          arr[x+t][y+k] = 1;
      }
    }
    if (x-2 >= 1)
      arr[x-2][y] = 1;
    if (x+2 >= n)
      arr[x+2][y] = 1;
    if (y-2 >= 1)
      arr[x][y-2] = 1;
    if (y+2 <= n)
      arr[x][y+2] = 1;
  }
  for (int i = 1;i <= yingshi;i++) {
    int x,y;
    cin>>x>>y;
    // 火把点亮的位置，包括自身及周围共9个
    // 以及横竖都各多两个
    for (int t = -2; t <= 2;t++) {
      for (int k = -2; k<= 2;k++) {
        if (x+t >= 1 && x+t <= n && y+k >= 1 && y+k <= n)
          arr[x+t][y+k] = 1;
      }
    }
  }
  int sum = 0;
  for (int i = 1;i <= n;i++) {
    for (int j = 1;j <= n;j++) {
      if (arr[i][j] == 0) {
        sum++;
      }
    }
  }
  cout<<sum;
  return 0;
}