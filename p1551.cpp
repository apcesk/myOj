#include<iostream>
#include<cstdio>
using namespace std;
int n,m,p;// n代表有n个人物，m个亲戚关系，p个查找目标
int f[5010];// 存放每个对应编号的祖先是谁
int findParent(int x)// 找到编号为x的祖先
{
    if (f[x] == x)
    {
        // 此时说明x没有比自身更高级的祖先，即为x为自身的祖先
        return x;
    }
    else
    {
        // 递归寻找自己的祖先
        return f[x] = findParent(f[x]);
    }
}

void together(int a, int b)
{
    // 基于两个编号元素具有亲戚关系，则将二者进行祖先合并
    // 也就是把b的祖先的爸爸设置为a的祖先
    f[findParent(b)] = findParent(a);
    return;
}

int main()
{
    // 输入数据
    scanf("%d %d %d", &n, &m, &p);
    // 初始化每个人的祖先都为自己
    for (int i = 1;i <= 5000;++i)
    {
        f[i] = i;
    }
    // 读入亲戚关系数据
    int n1, n2;
    for (int i = 1;i <= m;++i)
    {
        scanf("%d %d", &n1, &n2);
        // 由于输入的二者存在亲戚关系，则合并他们的祖先
        together(n1, n2);
    }
    // 查找两个人之间是否存在亲戚关系
    for (int i = 1;i <= p;++i)
    {
        scanf("%d %d", &n1, &n2);
        if (findParent(n1) == findParent(n2))
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
        
    }
    return 0;
}
