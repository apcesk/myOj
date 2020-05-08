#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
//约瑟夫环
queue<int> q;//创建一个队列q
int main(){
    int n,m;//n个人，第m个人出队
    scanf("%d %d", &n, &m);//输入n和m
    for (int i = 1;i <= n;++i){
        q.push(i);//编号为i的人入队
    }
    //开始出队
    int i = 1;
    while (!q.empty()){
        //只要队列不为空就一直进行
        if (i % m == 0){
            printf("%d ", q.front());
            q.pop();
        }else{
            int top = q.front();
            q.push(top);
            q.pop();
        }
        i++;
    }

    return 0;
}