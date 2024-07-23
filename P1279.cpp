#include<iostream>
#include<cmath>
#include<string>
using namespace std;
string s1, s2;
int k;
int dp[2222][2222];

int main() {
  cin >> s1 >> s2 >> k;
  int len1 = s1.length();
  int len2 = s2.length();
  dp[0][0] = 0;
  for (int i = 1;i <= len1;i++) {
    dp[i][0] = dp[i - 1][0] + k;
  }
  for (int i = 1;i <= len2;i++) {
    dp[0][i] = dp[0][i - 1] + k;
  }
  for (int i = 1;i <= len1;i++) {
    for (int j = 1;j <= len2;j++) {
      dp[i][j] = min(min(dp[i - 1][j] + k, dp[i][j - 1] + k), dp[i - 1][j - 1] + abs(s1[i - 1] - s2[j - 1]));
    }
  }
  cout << dp[len1][len2];
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