#include<iostream>
#include<cstdio>
using namespace std;
int a[5000001];
void Qsort(int a[], int start, int end){//快排
    if (start >= end){
        return;
    }
    int k = a[start];//随便取一个值，进行左右的快速排序
    int i = start, j = end;//循环变量
    while (i != j){
        //末尾指向的元素，只要当前元素比k大，就不管，继续向左移动
        while (j > i && a[j] > k)j--;
        //头部指向的元素，只要当前元素不比k小，就不管，继续向右移动
        while (i < j && a[i] <= k)i++;
        //以上两个循环执行完成之后，说明找到了一对不符合的元素
        swap(a[i], a[j]);//交换两个值
    }
    //处理左半部分
    Qsort(a, start, i-1);
    //处理右半部分
    Qsort(a, i + 1, end);

}

int main(){
    int n,k;//n个数字，找第k大
    scanf("%d %d", &n, &k);
    for (int i = 0;i < n;++i){
        scanf("%d", &a[i]);
    }
    Qsort(a, 0, n-1);
    printf("%d", a[k+1]);
    return 0;
}