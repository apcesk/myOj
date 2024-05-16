#include<iostream>
using namespace std;
char word[40]; // 判断的单词
char _string[255];// 输入的语句
int string_length = 0;// 代表的是string的长度
int word_length = 0;// 代表的是word的长度
bool check_string_same_word(int start, int end) {
  if (end - start != word_length) return false;
  // 判断从start - end 之间所有的字母，一一和word对应
  for (int i = start;i < end;i++) 
    if (_string[i] != word[i - start]) return false;
  return true;
}

int main() {
  char temp_char;// 临时的字符temp_char，来保存输入的每个字符
  // 输入 word
  // 输入 _string
  int start = 0;
  int sum = 0;
  while (scanf("%c", &temp_char)) {
    // 判断当前输入的temp_char 是不是大写的，如果是，则把它变成小写的
    if (temp_char <= 'Z' && temp_char >= 'A') {
      // 把temp_char变成小写
      temp_char += 32;
    }
    // cout << a << endl;
    if (temp_char == '\n') break;
    word[word_length] = temp_char;
    word_length++;
  }
  while (scanf("%c", &temp_char) ) {
    // 判断当前输入的temp_char 是不是大写的，如果是，则把它变成小写的
    if (temp_char <= 'Z' && temp_char >= 'A') {
      // 把temp_char变成小写
      temp_char += 32;
    }
    // cout << a << endl;
    if (temp_char == '\n') break;
    _string[string_length] = temp_char;
    string_length++;
  }
  for (int j = 0;j < string_length;j++) {
    if (_string[j] == ' ') {
      // 用一个方法，判断是否找到了该单词
      if (check_string_same_word(start, j)) {
        sum++;  
      }
      start = j + 1;
    }
  }
  printf("%d\n", sum == 0 ? -1 : sum);
  return 0;
}