#include<iostream>

using namespace std;
// 对于一个数组，其中都是数字
// 如果1个数字，比后面其中一个数字小，则后面那个数字的上升序列长度，等于前一个比它小的
// 且上升序列长度最大的数字上升序列长度+1
// [1,3,6,7,6,3,]
// 1,2,3,4,4,2
// a[n] -> 代表下标为n的数字的上升序列长度
// a[n+1] = max(a[1 - n]) + 1 (当n[n+1] > n[i])
int arr[10]= {1,5,6,7,6,3};
// [1,2,3,4,3,2]
int a[10] = {};
int main () {
  // cin>>arr;
  a[0] = 1;
  // 
  int maxn = -1;
  for (int i = 1;i < 6;i++) {
    a[i] = 1;
    // 算出每个以arr[i]为终点的上升序列长度
    for (int j = 0;j < i;j++) {
      if (arr[j] < arr[i]) {
        if (a[j] + 1 > a[i]) {
          a[i] = a[j] + 1;
          if (a[i] > maxn) {
            maxn = a[i];
          }
        }
      } else if (arr[j] == arr[i]) {
        if (a[j] > a[i]) {
          a[i] = a[j];
          if (a[i] > maxn) {
            maxn = a[i];
          }
        }
      }
    }
    // 存到a[i]中
  }
  for (int i = 0;i < 6;i++) {
    cout<<a[i]<<' ';
  }
  // 找到a数组中的最大值，即为该数组的最大上升序列长度
  // cout<<maxn;
  return 0;
}