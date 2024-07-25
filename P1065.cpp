#include<cstdio>

using namespace std;
int m, n;
int arr[501];// 给定的安排顺序
struct Data {
  int id;// 在哪个机器上加工
  int cost;// 花费的时间
} a[25][25];// a[i][j] 代表第i个工件第j步的操作信息
int mac[21][10001];// mac[机器编号][时间]
int step[25];// step[i] 代表第i个工件加工到了第几步
int last_time[25];// last_tim[i]代表第i个工件是何时加工完成的
int ans = 0;
int main() {
  scanf("%d%d", &m, &n);
  for (int i = 1;i <= m * n;i++) {// 给定的安排顺序
    scanf("%d", &arr[i]);
  }
  // 输入每个工件在每个机器上的操作信息
  for (int i = 1;i <= n;i++) {
    for (int j = 1;j <= m;j++) {
      scanf("%d", &a[i][j].id);
    }
  }
  for (int i = 1;i <= n;i++) {
    for (int j = 1;j <= m;j++) {
      scanf("%d", &a[i][j].cost);
    }
  }
  // ---------
  for (int i = 1;i <= m * n;i++) {
    int now = arr[i];// 当前要加工的工件
    step[now]++;// 当前要加工的工件应该加工的步骤
    int id = a[now][step[now]].id,// 当前这个工件应该去哪个机器上加工
        cost = a[now][step[now]].cost;// 当前这个工件需要花费的时间
    int s = 0;// 加工该工件的时间长度
    for (int j = last_time[now] + 1;;j++) {// 从第j时刻开始加工，找到连续的符合cost长度的时间段
      if (mac[id][j] == 0) {// 该时间点没有加工
        s++;// 累计加工该工件的时间长度
      } else {
        s = 0;
      }
      if (s == cost) {// 满足了时间要求
        for (int k = j - cost + 1;k <= j;k++) {
          mac[id][k] = 1;// 把这个机器加工now这个工件的时间全部打上标记
        }
        if (j > ans) ans = j;// 更新最晚的加工完成时间
        last_time[now] = j;// 更新当前工件的加工完成时间
        break;
      }
    }
  }
  printf("%d", ans);
  return 0;
}
/**
DDDDD           IIIIII        OOOOOOOO
DD  DD            II          OO    OO
DD   DD           II          OO    OO
DD    DD          II          OO    OO
DD    DD          II          OO    OO
DD    DD          II          OO    OO
DD   DD           II          OO    OO
DD  DD            II          OO    OO
DDDDD           IIIIII        OOOOOOOO
*/