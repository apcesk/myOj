#include<cstdio>
#include<algorithm>
using namespace std;
int sum1[16000005], sum2[16000005];
int a[4005],b[4005],c[4005],d[4005];
int n = 0, t= 0; // t = n^2;

int BinarySearch(int target) {
  int num = 0;
  int left = 0,right = t - 1;
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (target <= sum2[mid])
      right = mid;
    else 
      left = mid + 1;
  }
  while (sum2[left] == target && left < t) {// left < t 防止越界
    num++;
    left++;
  }
  return num;
}

int main() {
  while (scanf("%d", &n) != EOF) {
    t = 0;
    for (int i = 0;i < n;i++) 
      scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
    for (int i = 0;i < n;i++) {
      for (int j = 0;j < n;j++) {
        sum1[t] = a[i] + b[j];
        sum2[t] = c[i] + d[j];
        t++;
      }
      sort(sum1, sum1 + t);
      sort(sum2, sum2 + t);
      int num = 0;
      for (int i = t - i;i >= 0;i--){
        num += BinarySearch(-sum1[i]);
      }
      printf("%d\n", num);
    }
  }
}