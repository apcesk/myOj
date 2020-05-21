#include<cstdio>
#include<iostream>
using namespace std;
#define MAX 0x7fffffff;
int n;// n个果堆
int fruits[20001];// 桶排序的桶，将输入的数据放入这里面
int tmp;// 用来保存临时输入的果堆果子数目
long long ans;// 保存答案
// 两个果堆用来
int first_heap[20001];
int first_ptr;// 指向第一个堆的伪指针
int second_heap[20001];
int second_ptr;// 指向第二个堆的伪指针
int tmp_sum;// 用来临时保存两个堆只和
int main(){
    // 初始化第一个堆和第二个堆
    for (int i = 1;i <= 20000;++i){
        first_heap[i] = MAX;
        second_heap[i] = MAX;
    }
    // 输入n
    scanf("%d", &n);
    // 输入
    for (int i = 1;i <= n;++i){
        scanf("%d", &tmp);
        fruits[tmp]++;
    }
    // 将桶中所有的元素，按顺序放入第一个果堆中
    for (int i = 1;i <= 20000;++i){
        while (fruits[i]){
            // printf("i:%d\n", i);
            first_heap[++first_ptr] = i;
            fruits[i]--;
        }
    }
    // 开始进行合并，一共n堆，合并次数n-1次
    // 变量k代表合并的次数
    // i代表第一个堆的元素，j代表第二个堆的元素
    for (int i = 1,j = 1,k = 1;k < n;++k){
        // 第一次：取得两个堆中最小的那个进行合并
        // j > second_ptr说明第二个堆中尚无元素
        if (first_heap[i] < second_heap[j]){
            // 最小的数字先存放到临时的变量中
            tmp_sum = first_heap[i];
            i++;
        }else{
            // 说明第二堆中的元素更小
            tmp_sum = second_heap[j];
            j++;
        }
        // 重复上面的步骤再取一次最小的
        if (first_heap[i] < second_heap[j]){
            // 最小的数字先存放到临时的变量中
            tmp_sum += first_heap[i];
            i++;
        }else{
            // 说明第二堆中的元素更小
            tmp_sum += second_heap[j];
            j++;
        }
        // printf("tmp_sum:%d", tmp_sum);
        // 把合并完的新堆放入第二个堆中，由于每次合并都是从最小的开始的，所以第二个堆的顺序也自然是从小到大的
        second_heap[++second_ptr] = tmp_sum;
        // printf("当前存入第二堆中%d个元素，值为%d\n",second_ptr,second_heap[second_ptr]);
        // 将合并所需的力气合并进ans中
        ans += tmp_sum;
    }
    // 输出答案
    printf("%lld", ans);
    return 0;
}