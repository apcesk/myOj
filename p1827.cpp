#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
//求后序遍历
void printAft(string mid, string pre){
    if (mid.length() > 0){
        //由于是后序遍历，所以说最后输出根，（左右根），分左右之前，先找到根
        int k = mid.find(pre[0]);
        //先递归左边
        printAft(mid.substr(0, k), pre.substr(1, k));//1的原因是因为跟节点最后被输出了
        //递归右边
        printAft(mid.substr(k+1), pre.substr(k+1));
        //输出根，根必然在先序遍历的第一个
        printf("%c", pre[0]);
    }
}
int main(){
    string str1, str2;
    cin>>str1;
    cin>>str2;
    printAft(str1, str2);

    return 0;
}