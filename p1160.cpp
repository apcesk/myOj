#include<iostream>
#include<cstdio>
using namespace std;
//造一个节点，使得该节点具有如下三个属性
//1:编号
//2:左边的人
//3:右边的人
struct student{
    int id, left, right;//就不解释了
};
student q[100001];//存放每个学生的数组
int main(){
    //初始化第一个学生
    q[1].id = 1, q[1].left = 0, q[1].right = 0;
    int n;
    scanf("%d" , &n);//输入n的值，代表总共的学生数
    int s;//s代表插入到哪个学生的位置，lr代表左右
    int lr;//为0代表左边，为1代表右边
    for (int i = 2;i <= n;++i){//依次插入入队的学生
        scanf("%d %d", &s, &lr);//读入
        if (lr == 0){//插入到s的左边
            q[i].left = q[s].left;//i的左边是原来s的左边
            q[q[s].left].right = i;//原来s左边的值的右边变成i
            q[s].left = i;//s的左边标记为i
            q[i].right = s;//i的右边标记为s
            q[i].id = i;
        }else{//插入到s的右边
            q[i].right = q[s].right;
            q[q[s].right].left = i;//原来s右边的值的左边变成i
            q[s].right = i;//s的右边标记为i
            q[i].left = s;//i的左边标记为s
            q[i].id = i;
        }
    }
    //读入要删除学生数目
    int delete_num;//记录要删除多少个学生
    scanf("%d", &delete_num);
    int t;
    while (delete_num > 0){
        scanf("%d", &t);
        if (q[t].id){
            //t左边的值的右边指向t的右边
            q[q[t].left].right = q[t].right;
            //t的右边的值的左边指向t的左边
            q[q[t].right].left = q[t].left;
            //id为0 说明已删除
            q[t].id = 0;
        }
        delete_num--;
    }

    //输出所有的同学
    //####此处只为了找到队列最左边的那个学生####
    int start;
    for (int i = 1;i <= n;++i){
        if (q[i].id){//如果存在这个学生，从这个学生的位置找到他最左边的学生
            start = i;
            while (q[start].left){
                start = q[start].left;
            }
            break;//退出循环
        }
    }
    //####结束####
    //先输出队首学生的id
    printf("%d ", q[start].id);
    //依次输出右边学生编号
    while(q[start].right > 0){
        printf("%d ", q[start].right);
        start = q[start].right;
    }
    return 0;
}
