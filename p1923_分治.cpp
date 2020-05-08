#include<iostream>
#include<cstdio>
using namespace std;

int a[5000001],n,k;
void divide(int left, int right){//left和right分别指代
    //模拟快排的思想，核心的是找到a个比k大的，b个比k小的，c个与k相等的
    //l和r就是指向数组左侧和右侧的指针
    int l = left, r = right, mid = a[(left+right)/2];//mid为中间值，可以随便取
    while (l <= r){//快排扫描一遍
        while (a[r] > mid) --r;//如果右侧元素大于所选取的中间值，则指针回退
        while (a[l] < mid) ++l;//如果左侧元素小于所选取的中间值，则指针前进
        if (l <= r){//当发现了不合理的情况时，交换两个不合理情况的值
            swap(a[l], a[r]);//交换值，与快排相同
            ++l, --r;//交换完毕之后进行更替指针
        }
    }
    //先明确一件事情，就是当前的l,r,left,right四个值把数组分成了三个区间
    //left -> r -> l -> right;这样的一个区间
    if (k <= r){//如果k小于等于r，说明第k小的值应该在left到r之间，直接递归实现
        divide(left, r);
    }else if (k >= l){//如果k大于等于l，则说明第k小的值应该在l到right之间，递归实现。
        divide(l, right);
    }else{//否则说明当前的元素就是第k小，至于为什么是r+1？思考一下吧！并不难哦！
        printf("%d\n", a[r+1]);
    }
}
int main(){
    scanf("%d %d", &n, &k);
    for (int i = 0;i < n;++i){
        scanf("%d", &a[i]);
    }
    //分治找到第k小
    divide(0, n-1);
    return 0;

}