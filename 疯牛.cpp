#include<cstdio>
#include<algorithm>
using namespace std;

int N, L[100005], C;

// 最小距离为X时，是否可以放下C头牛。
bool Check(int X) {
  int count = 1, temp = L[0];
  for (int i = 1;i < N;i++) {
    if (L[i] - temp >= X) {
      count++;
      temp = L[i];
      if (count >= C)
        return true;
    }
  }
  return false;
}

// 由顺序遍历“最大的最小距离，改为二分查找的方式”
int BinarySearch() {
  int left = 0, right = L[N-1] - L[0];
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (Check(mid))
      left = mid + 1;
    else 
      right = mid - 1;
  }
  return left - 1;
}

int main() {
  while (scanf("%d%d", &N, &C) != EOF) {
    for (int i = 0;i < N;i++)
      scanf("%d", &L[i]);
    sort(L, L + N);
    printf("%d\n", BinarySearch());
  }
  return 0;
}
