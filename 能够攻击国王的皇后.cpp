#include<iostream>
using namespace std;
// arr[i][j] = true; 说明在位置i，j上有皇后
bool arr[8][8] = {};

// 每找到一个可以攻击国王的皇后，则把其下标放入到q这个数组中
int q[8][2] = {};
int start = 0;
int main() {
  // 是先输入
  int n;
  int x,y;
  cin>>n;
  for (int i = 1;i <= n;i++) {
    cin>>x>>y;
    arr[x][y] = true;
  }
  cin>>x>>y;
  // 顺着国王所在的位置，去找周围八个方向上面是否有皇后
  int dir[8][2] = {
    {-1, 0}, // 上
    {-1, 1}, // 右上
    {0, 1},  // 右
    {1, 1},  // 右下
    {1, 0},  // 下
    {1, -1}, // 左下
    {0, -1}, // 左
    {-1, -1}  // 左上
  };
  int sum = 0;
  for (int i = 0;i <= 7;i++) {
    int _x = x;
    int _y = y;
    // 顺着当前的方向走到“底”
    // 1、出界了
    // 2、遇到皇后了
    while (_x <= 7 && _x >= 0&& _y <= 7 && _y >= 0) {
      if (arr[_x][_y]) {
        q[start][0] = _x;
        q[start][1] = _y;
        start++;
        sum++;
        break;
      }
      _x = _x + dir[i][0];
      _y = _y + dir[i][1];
    }
  }
  cout<<sum<<endl;
  for (int i = 0;i < sum;i++) {
    cout<<"x: "<<q[i][0]<<",y: "<<q[i][1]<<endl;
  }
  return 0;
}