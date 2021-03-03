#include<iostream>
#include<cstring>
using namespace std;

#define MAXIN 75
char board[MAXIN+2][MAXIN+2];// 定义矩形板
int minStep, w, h, to[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
bool mark[MAXIN+2][MAXIN+2];// 定义标记数组
void Search (int currentX, int currentY, int endX, int endY, int step, int f) {
  // 当路径数大于minStep，返回优化策略
  if (step > minStep) return;
  // 到达终点
  if (currentX == endX && currentY == endY) {
    if (minStep < step) { // 更新最小路径数
      minStep = step;
    }
    return;
  }
  for (int i = 0;i < 4;i++) {// 美剧下一步的方向
    int x = currentX + to[i][0];
    int y = currentX + to[i][1];
    // 如果新的位置有效
    if ((x > -1) && (x < w + 2) && (y > -1) && (y < h + 2)
      && (((board[y][x] == ' ') && (mark[y][x] == false)) || ((x == endX) && (y == endY) && (board[y][x] == 'X')))
    ) {
      mark[y][x] = true;// 标记当前位置已经经过
      // 上一步方向和当前方向想通过，则递归搜索时step不变，否则step+1
      if (f == i) Search(x, y, endX, endY, step, i);
      else Search(x, y, endX, endY, step + 1, i);
      mark[y][x] = false; 
    }
  }
}

int main() {

  return 0;
}

