#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;


struct Entry {
  char english[11];
  char foreign[11];
}entries[100005];

int Cmp(Entry entry1, Entry entry2) {
  return strcmp(entry1.foreign, entry2.foreign) < 0;
}

int main() {
  int num = 0;
  char word[11];// 要查找的字符串
  while (true) {
    // 读入英语和对应的翻译
    scanf("%s%s", entries[num].english, entries[num].foreign);
    num++;
    cin.get();
    if (cin.peek() == '\n') break;
  }
  sort(entries, entries+num, Cmp);
  while (scanf("%s", word) != EOF) {
    int left = 0, right = num - 1;
    int n = 0;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      n = strcmp(entries[mid].foreign, word);
      if (n < 0) {
        left = mid + 1;
      } else if (n > 0) {
        right = mid - 1;
      } else {
        printf("%s\n", entries[mid].english);
        break;
      }
    }
    if (n) printf("eh\n");
  }
  return 0;
}