#include<iostream>

using namespace std;
#define int long long
/**
 * 思考S(k) 是基于S(k-1)衍生的字符串，那么其长度也是有规律的才对
 * len(S(k)) = len(S(k - 1) * 2 + 1 + (k + 2)【m和o的个数】
 * len(S(k - 1)) * 2 + k + 3;
 * 题目询问第n个下标是什么内容。
 * 先把字符串分3部分，左一半(S(k - 1))，右一半(S(k-1)),中间部分("m(k+2)o")
 * 1:下标n在左一半中，递归
 * 2:下标n在右一半中，递归
 * 3:下标n在中间部分中 (都是moo)
 *  3-1:如果是下标1，则是m
 *  3-2:否则是o
 */
int n;
// string s[N];// s[k] = s[k - 1] + 'm' + string(k + 2, 'o') + s[k - 1];
string S(int k) {// 构造字符串（暴力x），同样可以处理出字符串长度（直接处理即可）
  if (k == 0) return "moo";
  else {
    return S(k - 1) + 'm' + string(k + 2, 'o') + S(k - 1);
  }
}
// len是符合要求的字符串长度,至少>=n
int len = 0, s0 = 3;// s0是基本的字符串长度
void get_len() {// 获取构造出的字符串长度
  while (len <= n) {// 
    len = len * 2 + s0;
    s0 = s0 + 1;// 多补一个o进去
  }
}
signed main() {
  cin >> n;
  // cout << S(2) << endl;
  get_len();
  // cout << string(10, '0') << endl;
  // 开始找n在字符串中的位置，已知现在字符串长度为len
  s0--;// 处理最后一次的增加，回到真实最后一次的长度
  while (len > 0) {// len目前是S(k)的长度
    len = (len - s0) / 2;// 这是S(k-1)的长度
    if (n > len) {// 在右边，那也就是在后面的S(k-1)之间或者是在中间部分中
      if (n <= len + s0) {// 在S(k)的中间部分
        if (n == len + 1) {// n是中间部分第一个
          cout << 'm';
        } else {
          cout << 'o';
        }
      } else {// 没在中间部分，说明在右边部分S(k-1)，此时和在左边一部分是一致的
        n = n - (len + s0);// 思考一下
      }
    }
    s0--;// 去除一个o
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