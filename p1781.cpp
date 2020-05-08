#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
char s[21][101];//存放n个人的成绩数组
char max_n[101];
int main(){
    int n;
    scanf("%d", &n);//输入n
    for (int i = 1;i <= n;++i){
        cin>>s[i];
    }
    int president;
    //所有数字输入完毕之后，判断大小
    for (int i = 1;i <= n;++i){
        if (strlen(s[i]) > strlen(max_n)){
            strcpy(max_n, s[i]);//将大的数值拷贝到max_n中
            president = i;
        }else if(strlen(s[i]) == strlen(max_n)){
            //比较大小，从第一位开始
            int t = 0;
            while (s[i][t] == max_n[t]){//找到第一个不想等的数字
                t++;
            }
            if (s[i][t] > max_n[t]){
                strcpy(max_n, s[i]);
                president = i;
            }
        }
    }
    cout<<president<<endl<<max_n<<endl;
    return 0;
}