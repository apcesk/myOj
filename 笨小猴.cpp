#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
// 4-5- 500 400 1. 2.20%
// 细 -> 第一题，手感
// 简单-复合型
char word[100];// 这是单词
int word_times[26];// word_times[i] = 1 代表'a'出现的次数
// 等于任意一个字母 - 'a'
// 字符是ASCII码， ASCII是数值
bool is_prime(int n) {
  for (int i = 2;i <= sqrt(n);i++) 
    if (n % i == 0) return false;
  return true;
}
int main() {
  // 输入单词
  scanf("%s", word);
  int maxn = -1, minn = 101;
  for (int i = 0;i < strlen(word);i++) {
    word_times[word[i] - 'a']++;
    int t = word_times[word[i] - 'a'];
    if (t > maxn) {
      maxn = t;
    }
    if (t < minn) {
      minn = t;
    }
  }
  if (is_prime(maxn - minn)) {
    printf("Lucky word\n%d\n", maxn - minn);
  } else {
    printf("No answer\n0\n");
  }
  return 0;
}