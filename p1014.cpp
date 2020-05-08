#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int n;
    scanf("%d", &n);//输入n的值，代表第几项
    //获取当前n的值处于Cantor表的第几列(斜向)
    int i;//存储数字在第几列
    for (i = 1;i <= n;i++){
        n -= i;
    }
    //进行循环结束之后，此时的n是说明在该列的第几个数字
    //而i代表的是处于第几列
    //奇数列和偶数列不同，分开进行处理
    int fz=0,fm=0;//分别代表分子和分母
    // printf("%d\n", i);
    if (n == 0){//如果n归零了，则说明正好是某一列的第一个。
        i -= 1;
        if (i % 2 == 1){//奇数列的第一个
            printf("1/%d\n", i);
            return 0;
        }else{//偶数列的第一个
            printf("%d/1\n", i);
            return 0;
        }
    }
    if (i % 2 == 1){//奇数列，是从下向上的，所以说分子不断减小，而分母不断增大
        //奇数行i做分子，向上查找n个
        fm = 1;
        while (n > 1){
            i--;
            n--;
            fm++;
        }
        fz = i;
    }else{
        //偶数行i做分母，向下查找n个
        fz = 1;
        while (n > 1){
            i--;
            n--;
            fz++;
        }
        fm = i;
    }
    printf("%d/%d\n", fz, fm);
    return 0;
}