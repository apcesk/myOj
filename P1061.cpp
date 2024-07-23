#include<iostream>
#include<string>
using namespace std;
int s, t, w;// s为所使用的最小的字母序号，t是所使用的最大的字母序号，w为数字的位数
string jam;// 字符串
int main() {
  cin >> s >> t >> w >> jam;
  // cout << char(96);
  for (int i = 1;i <= 5;i++) {// 找到其后5个数字
    for (int j = w - 1;j > 0;j--) {
      if (jam[j] - 96 <= j - w + t) {// 这一位的后面还有没有字母
        jam[j]++;// 如果有，那么就让它变大
        for (int k = j + 1;k < w;k++) jam[k] = jam[k-1]+1;// 它后面的所有元素，依次排列比它大即可。
        cout << jam << endl;// 输出一种排列
        break;
      }
    }
  }
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