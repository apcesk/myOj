#include<cstdio>
#include<iostream>
using namespace std;
const int MAX = 1e6+1;
int n,k;// 输入的n个数字
int arr[MAX];// 存放所有数字的数组
int find(int num){
    int l = 1, r = n;
    while (l < r){
        int mid = (l+r)/2;
        if (arr[mid] >= num){
            r = mid;
        }else{
            l = mid+1;
        }
    }
    if (arr[l] == num) return l;
    else return -1;
}
int main()
{
    scanf("%d %d", &n, &k);// 输入n和k的值
    for (int i = 1;i <= n;++i){
        scanf("%d", &arr[i]);// 输入当前的数字
    }
    int ans;
    while (k > 0){
        int t;
        scanf("%d", &t);
        ans = find(t);
        // 查找指定的数字t
        printf("%d ", find(t));
        k--;
    }
    return 0;
}