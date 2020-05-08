#include<iostream>
#include<cstdio>

using namespace std;
typedef int Deep;
struct TreeNode{
    int id,left,right;
}Tree[1000001];
int n;//n个节点
int ans;//答案
Deep t[1000001]={0,1};//每个下标所对应的是到达当前位置的深度,t[1] = 1
void dfs(int i, int father){
    if(!Tree[i].left && !Tree[i].right){
        //左右子树都是叶子节点，退出递归
        return;
    }
    t[i] = t[father] + 1;//当前节点的深度=父节点的深度 + 1
    ans = max(ans, t[i]);
    dfs(Tree[i].left, Tree[i].id);//计算左子树的深度
    dfs(Tree[i].right, Tree[i].id);//计算右子树的深度
}
int main(){
    scanf("%d", &n);//输入节点数目
    for (int i = 1;i <= n;++i){
        Tree[i].id = i;//输入根
        scanf("%d %d", &Tree[i].left, &Tree[i].right);//输入左子树和右子树
    }
    //搜索树的深度
    dfs(1, 0);//参数为节点的编号，默认从根开始
    printf("%d\n", ans+1);
    return 0;
}