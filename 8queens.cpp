#include<iostream>
using namespace std;


int arr[8][8];
int jie[92][8][8];
int start = 0;

int dir[8][2] = {
  {-1, 0}, // 上
  {-1, 1}, // 右上
  {-1, -1}  // 左上
};
bool can_put_queen(int row, int column) {
  // 只需要判断arr[row][i] = 1的话，是否可行
  for (int i = 0;i <= 2;i++) {
    int _x = row;
    int _y = column;
    // 顺着当前的方向走到“底”
    // 1、出界了
    // 2、遇到皇后了
    while (_x <= 7 && _x >= 0&& _y <= 7 && _y >= 0) {
      if (arr[_x][_y]) {
        return false;
      }
      _x = _x + dir[i][0];
      _y = _y + dir[i][1];
    }
  }
  return true;
}

void dfs(int row, int count) {
  // 已经放好八个皇后，则把放好的棋盘保存起来
  if (count == 8) {
    // 说明放好的八个皇后
    for (int i = 0;i < 8;i++) {
      for (int j = 0;j < 8;j++) {
        jie[start][i][j] = arr[i][j];
      }
    }
    start++;
    return;
  }
  for (int i = 0;i < 8;i++) {
    // 在当前的行，能否放皇后
    if (can_put_queen(row, i)) {
      arr[row][i] = 1;// 摆放
      dfs(row + 1, count + 1);// 递归
      arr[row][i] = 0;// 回溯
    }
  }
}


int main() {
  // 两步，摆
  // 判断
  dfs(0, 0);
  // 输出jie
  for (int i = 0;i < 92;i++) {
    for (int m = 0;m < 8;m++) {
      for (int n = 0;n < 8;n++) {
        cout<<jie[0][m][n]<<' ';
      }
      cout<<endl;
    }
    cout<<endl;
  }
  return 0;
}