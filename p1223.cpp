#include<iostream>
#include<cstdio>
using namespace std;
struct node{
    int id,w;// 编号和等待时间
}water[1001];
int n,t;// n个人每个人等待时间t
void qSort(node a[],int s, int e)//a为被排序数组，s为排序的起点，e为排序的终点
{
	//如果起点和终点相等，则说明排序完毕
	if (s >= e)	return;
	int k = a[(s+e)/2].w;
	int i = s, j = e;
	//当两个指针没有指向同一个格子，说明要继续排序
	while (i <= j)
	{
		//先找到左边比他大的数字
		while (a[i].w < k) i++;
		//找到右边比他小的数字
		while (a[j].w > k) j--;
		if (i <= j)
		{
			swap(a[i],a[j]);
			i++;
			j--;
		}
	}
	//分治
	qSort(a, s, j);//k左边的所有元素
	qSort(a, i, e);//k右边的所有元素
}
int main(){
    scanf("%d", &n);
    for (int i = 1;i <= n;++i){
        scanf("%d", &water[i].w);
        water[i].id = i;
    }
    qSort(water, 1, n);
    double sum = 0;
    for (int i = 1;i <= n;++i){
        printf("%d ", water[i].id);
        sum += water[i].w * (n-i);
        // printf("%d ", water[i].w);
    }
    printf("\n%.2lf", sum/n);
    return 0;
}