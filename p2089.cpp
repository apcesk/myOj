#include<iostream>
#include<cstdio>
using namespace std;
int n;//n克调料
int tl[11];//10种调料每种所放的克数
int ans;//一共有n种方法
void outAns(){//为了输出方案
    for (int i = 1;i <= 10;++i){
        printf("%d ", tl[i]);
    }
    printf("\n");
}
void putIngredientAns(int g, int time){
    if (g == 0 && time == 11){
        //如果10次刚好放完全部调料，则总方案数+1
        ans++;
        return ;
    }else if(time > 10 || g < 0){
        return ;
    }
    for (int i = 1;i <= 3;++i){
        tl[time] = i;//把i克调料放入tl中
        putIngredientAns(g - i, time + 1);//放了其中一种调料i克，放下一种调料
        tl[time] = 0;
    }
}
void putIngredient(int g, int time){//放调料,g代表当前能够放的调料克数,time代表放的次数
    if (g == 0 && time == 11){
        //如果10次刚好放完全部调料，则输出
        outAns();
        return ;
    }else if(time > 10 || g < 0){
        return ;
    }
    for (int i = 1;i <= 3;++i){
        tl[time] = i;//把i克调料放入tl中
        putIngredient(g - i, time + 1);//放了其中一种调料i克，放下一种调料
        tl[time] = 0;
    }
}
int main(){
    
    scanf("%d", &n);
    if (n < 10 || n > 30){//没有放调料的办法
        printf("%d\n", 0);
        return 0;
    }
    //先输出配料方案数
    putIngredientAns(n,1);
    printf("%d\n", ans);
    putIngredient(n, 1);
    return 0;
}