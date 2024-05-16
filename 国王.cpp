#include<iostream>
using namespace std;
// B R .
// .是空位
// B是主教，R是战车
int arr[9][9];
int dir[4][2] = {{-1, -1}, {1, 1}, {1, -1}, {-1, 1}};// 给B
int dir2[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};// 给R
int main() {
  // 输入棋盘的样子
  for (int i = 1;i <= 8;i++) {
    for (int j = 1;j <= 8;j++) {
      cin>>arr[i][j];
    }
  }
  for (int i = 1;i <= 8;i++) {
    for (int j = 1;j <= 8;j++) {
      if (arr[i][j] == int('B')) {
        // 把斜对角上面所有的格子都变成-1
        int tmpi = i,tmpj = j;
        for (int t = 0;t < 4;t++) {
          while(tmpi + dir[t][0] >= 1 && tmpj + dir[t][1] >= 1 
            && tmpi + dir[t][0] <= 8 && tmpj + dir[t][1] <= 8 
            && arr[tmpi+dir[t][0]][tmpj+dir[t][1]] != 'B' && arr[tmpi+dir[t][0]][tmpj+dir[t][1]] != 'R') {
            arr[tmpi+dir[t][0]][tmpj+dir[t][1]] = -1;
            tmpi = tmpi+dir[t][0];
            tmpj = tmpj+dir[t][1];
          }
          tmpi = i,tmpj = j;
        }
      }
      if (arr[i][j] == int('R')) {
        // 把斜对角上面所有的格子都变成-1
        int tmpi = i,tmpj = j;
        for (int t = 0;t < 4;t++) {
          while(tmpi +dir2[t][0] >= 1 && tmpj + dir2[t][1] >= 1
            && tmpi +dir2[t][0] <= 8 && tmpj + dir2[t][1] <= 8
            && arr[tmpi+dir2[t][0]][tmpj+dir2[t][0]] != 'B' && arr[tmpi+dir2[t][10][tmpj + dir2[t][1]] != 'R') {
            arr[tmpi-1][tmpj] = -1;
            tmpi = tmpi+dir2[t][0];
            tmpj = tmpj+dir2[t][1];
          }
          tmpi = i,tmpj = j;
        }
      }
    }
  }
  // 输出地图
  for (int i = 1;i <= 8;i++) {
    for (int j = 1;j <= 8;j++) {
      if (arr[i][j] == int('.')) {
        cout<<0<<' ';
      } else {
        cout<<1<<' ';
      }
    }
    cout<<endl;
  }
  return 0;  
}