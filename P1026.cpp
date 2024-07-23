#include<iostream>
#include<string>
using namespace std;
#define int long long
int p, k, s_cnt, len;// p行单词，每行20个，k表示k个部分
// s_cnt是词典中的单词个数
// dic 是词典中的每个单词
string s = "0", dic[10];// dis是
// dp[i][j] 代表下标i的位置切j个部分的结果
// sum[i][j] 代表从i到j包含多少个单词。
int dp[255][50], sum[255][255];
bool check(int l, int r) {// 判断此字符串是否是一个单词
  string x = s.substr(l, r - l + 1);
  for (int i = 1;i <= s_cnt;i++) {
    if (x.find(dic[i]) == 0) return true;
  }
  return false;
}
signed main() {
  cin >> p >> k;
  string temp;
  for (int i = 1;i <= p;i++) {
    cin >> temp;
    s += temp;
  }
  // cout << s << endl;
  len = s.length() - 1;
  cin >> s_cnt;
  for (int i = 1;i <= s_cnt;i++) cin >> dic[i];
  for (int i = len;i >= 1;i--) {
    for (int j = i;j >= 1;j--) {
      sum[j][i] = sum[j + 1][i];
      if (check(j, i)) sum[j][i]++;
    }
  }
  dp[0][0] = 0;
  for (int i = 1;i <= k;i++) {
    dp[i][i] = dp[i - 1][i - 1] + sum[i][i];
  }
  for (int i = 1;i <= len;i++) dp[i][1] = sum[1][i];
  for (int i = 1;i <= len;i++) {
    for (int j = 1;j <= k && j < i;j++) {
      for (int l = j; l < i;l++) {
        dp[i][j] = max(dp[i][j], dp[l][j - 1] + sum[l + 1][i]);
      }
    }
  }
  cout << dp[len][k];
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