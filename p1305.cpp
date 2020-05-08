#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct TreeNode{
    char value;//当前节点的值
    char left_value;//左子节点的值
    char right_value;//右子节点的值
};
TreeNode Tree[30];//创建数组存储树的每一个节点
int n;//二叉树的节点数
int isTree(char c){//判断一个节点的值是不是一棵树，并且返回该树所在数组中的下标
    if (c == '*') {return -1;}
    for (int i = 0;i < n;++i){
        if (Tree[i].value == c){//找到当前树的节点
            return i;
        }
    }
    return -1;
}

void findValue(TreeNode T){
    //先序遍历，先输出根节点的值
    printf("%c", T.value);
    //递归找左子树
    if (T.left_value == T.right_value){return;}
    int left_index = isTree(T.left_value);//判断左儿子是不是一棵树
    if (left_index != -1){
        findValue(Tree[left_index]);
    }
    //递归找右子树
    int right_index = isTree(T.right_value);//判断右儿子是不是一棵树
    if (right_index != -1){
        findValue(Tree[right_index]);
    }
}
void outTree();//输出树
int main(){
    scanf("%d", &n);//输入节点数
    // getchar();//去除回车
    int i = 0;
    int t = n;
    while(t > 0){
        char str[3];//一个存储输入每一行字符串的数据
        scanf("%c%c%c", &str[0], &str[1], &str[2]);
        // if(t > 0)
            // getchar();//去除回车
        Tree[i].value = str[0];
        Tree[i].left_value = str[1];
        Tree[i].right_value = str[2];
        ++i;
        t--;
    }
    findValue(Tree[0]);
    return 0;
}

void outTree(){
    for (int i = 0;i <= 100 && Tree[i].value;++i){
        printf("value:%c left_value:%c right_value:%c\n", Tree[i].value, Tree[i].left_value, Tree[i].right_value);
    }
    return;
}