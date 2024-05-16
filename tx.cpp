#include<algorithm>
#include<iostream>
using namespace std;

char arr[100001];
int main() {
  int sum = 0;
  cin >> arr;
  // cout << arr;
  int i = 0;
  if (arr[0] == '0') {
    for (;i < strlen(arr);i++) {
      if (arr[i] == '0') {
        arr[i] = '1';
      }
    }
    sum++;
  } 
  for (;i < strlen(arr);i++) {
    // 记录1出现的地方
    if (arr[i] == '1') {
      int start = i;
      while (arr[start] == arr[start+1]) {
        start = start + 1;
      }
      sum+=2;
    }
  }
  cout << sum;
  return 0;
}


