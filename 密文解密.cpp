#include<iostream>
#include<cstring>
using namespace std;

char secret_key[100];// 密钥
char secret_word[1000];// 密文


int main() {

  // 输入密钥
  scanf("%s", secret_key);
  // 输入密文
  scanf("%s", secret_word);
  // 得到明文
  for (int i = 0;i < strlen(secret_word);i++) {
    // 明文[i] = 密文[i] - (密钥[i % 密钥的长度] - 'a') // 注意成环 %
    // 根据密钥计算出当前的密文所对应的明文
    int temp = secret_key[i % strlen(secret_key)] - 'a';
    char temp_char = secret_word[i] - temp;
    if (secret_word[i] >= 'A' && secret_word[i] <= 'Z') {
      // 补
    }
    if (secret_word[i] >= 'a' && secret_word[i] <= 'z') {
      // 补
    }
    printf("%c");
  }
  // printf("%s\n",secret_key);
  

  return 0;
}