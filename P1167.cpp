#include<cstdio>
#include<algorithm>

using namespace std;
#define int long long
bool check(int n) {
  return (n % 4 == 0 && n % 100 != 0) || n % 400 == 0;
}
int n;
int problem[5555];
int sy, sm, sd, sh, sf;// 年月日，时分
int ey, em, ed, eh, ef;
int month[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
signed main() {
  scanf("%lld", &n);
  for (int i = 1;i <= n;i++) {
    scanf("%lld", &problem[i]);
  }
  scanf("%lld-%lld-%lld-%lld-%lld", &sy, &sm, &sd, &sh, &sf);
  scanf("%lld-%lld-%lld-%lld-%lld", &ey, &em, &ed, &eh, &ef);
  // 计算整年带来的天数
  int tot_day = 0;
  if (sy < ey) {
    // 今年的都过去
    if (check(sy)) month[2] = 29;
    for (int i = sm + 1;i <= 12;i++) {
      tot_day += month[i];
    }
    // 明年的部分
    if (check(ey)) month[2] = 29;
    for (int i = 1;i < em;i++) {
      tot_day += month[i];
    }
  }
  for (int i = sy + 1;i < ey;i++) {
    if (check(i)) {
      tot_day += 366;
    } else {
      tot_day += 365;
    }
  }
  printf("tot_day: %lld\n", tot_day);
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