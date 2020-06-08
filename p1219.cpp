/**
 * 皇后问题
 * 核心思想是回溯
 * 暴力的搜索找到答案的过程
 * 由于皇后之间不能同行，同列，同对角线，所以需要四个标记数组
*/
#include<iostream>
#include<cstdio>
using namespace std;
int col[200];// 同行的
int row[200];// 同列的
int main_line[200];// 主对角线，指左上到右下
int second_line[200];// 副对角线，指右上到左下
int n;// 输入一个n*n的网格
int ans;
// 按题目要求输出
void print_ans()
{
    if (ans < 3)
    {
        for (int i = 1;i <= n;++i)
        {
            printf("%d ", col[i]);
        }
        printf("\n");
    }
    ans++;
}

// 搜索方法实现
void queen(int i)// i代表当前放的是第几个皇后
{
    if (i > n)
    {
        // 放n个皇后，当i的值超过n说明已经有n个皇后放完了
        // 调用输出函数，输出结果
        print_ans();
        return;
    }
    else
    {
        // 此时没有放足够的皇后，开始挨个放
        for (int j = 1;j <= n;++j)
        {
            if ( !row[j] && !main_line[i+j] && !second_line[i-j+n])
            {
                // 满足该条件则说明这个位置还可以放皇后
                // 你要问为什么不判断同行？
                // 我们本就是按照一行一行的来放的，自然不用判断同行。
                // 开始放皇后
                col[i] = j;// 把皇后放在第i行的第j个
                // 标记列
                row[j] = 1;// 当前这一列被皇后占据
                // 标记主对角线
                main_line[i+j] = 1;
                // 标记副对角线
                second_line[i-j+n] = 1;
                // 继续搜寻下一个皇后的位置
                queen(i+1);
                // 回溯阶段标记重置，为什么不清楚col的标记？因为后续会把它给覆盖掉，毕竟你重置了代表这行需要重新放，重新放就需要重新赋值，重新赋值就会被覆盖。
                row[j] = 0;
                main_line[i+j] = 0;
                second_line[i-j+n] = 0;
            }
        }
    }
    
}
int main()
{

    scanf("%d", &n);// 输入网格大小
    // 开始摆放皇后
    queen(1);
    // 输出答案
    printf("%d", ans);
    return 0;
}
