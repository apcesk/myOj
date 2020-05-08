#include<iostream>
#include<cstdio>

using namespace std;

struct Tree{
    int people, left, right, father;//当前节点人数，左子树和右子树的编号
}tree[101];
int ans = 0x7777777;//标记一个值，用来存放最短的路径答案
int dis(int j, int i, int people){//传入节点j的位置和节点i的位置
    if (j == i || tree[j].left == 0 && tree[j].right == 0){
        return 0;
    }else{
        
    }
}
int main(){
    /*
        思路:
            假设每一个点作为建设医院的点，然后计算出总路径
            最终求出总路径中最小的那一个
    */
    //输入数据
    int n;
    scanf("%d", &n);
    for (int i = 1;i <= n;++i){
        scanf("%d %d %d", &tree[i].people, &tree[i].left, &tree[i].right);
        tree[i].father = i-1;
    }
    for (int i = 1;i <= n;++i){//假设当前的这个节点简历医院
        //求解每个节点到达该节点的距离
        for (int j = 1;j <= n;++j){
            if (i == j) {continue;}
            else{
                //找到当前节点j到达i节点的距离
            }
        }
    }
    return 0;
}