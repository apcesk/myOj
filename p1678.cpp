#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int m,n;// 学校数量和学生数量
int school[100001];// 存放所有学校所需要的分数
int student[100001];// 存放每个学生的分数
bool cmp(int a, int b){
    return a < b;
}
long long ans;// 存放答案
int main(){
    // 输入学校数量和学生数量
    scanf("%d %d", &m, &n);
    // 输入每一所学校所需要的分数
    for (int i = 1;i <= m;++i){
        scanf("%d", &school[i]);
    }
    // 输入每一个学生的分数
    for (int i = 1;i <= n;++i){
        scanf("%d", &student[i]);
    }
    
    // 把所有的学校分数进行排序
    sort(school + 1, school + 1 + m, cmp);
    // for (int i = 1;i <= m;++i){
    //     printf("%d ", school[i]);
    // }
    // printf("\n");
    // 查找每一个学生最满意的学校
    for (int i = 1;i <= n;++i){

        int l = 0, r = m+1;// 定义二分查找的左右边界
        // 找到最理想的学校
        while (l < r){
            int mid = (l + r) / 2;
            
            if (school[mid] <= student[i]){
                // 如果当前学校的录取分数小于等于学生的分数
                l = mid + 1;// 左边界右移；
            }else{
                // 如果当前学校的分数大于学生的分数
                // 右边界左移
                r = mid;
            }
        }
        if(student[i]<=school[1])//这里需要特判断一下，不然只能得70分
		{
			ans+=school[1]-student[i];
		}
		else
		{
			ans+=min(abs(school[l-1]-student[i]),abs(school[l]-student[i]));//加上两个绝对值中最小
		}
    }
    printf("%lld\n", ans);
    return 0;
}
