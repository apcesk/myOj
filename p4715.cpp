#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
//打比赛
//思路，由于相邻两人进行打比赛。
//则说明第一名和第二名分别出在整个学列的前半段和后半段。
struct player{
    int id;
    int key;
}arr[300];
bool cmp(player a, player b){
    return a.key > b.key;
}
int main(){
    int n;
    scanf("%d", &n);
    n = pow(2, n);
    for (int i = 0;i < n;i++){
        scanf("%d", &arr[i].key);
        arr[i].id = i+1;
    }
    sort(arr, arr + n / 2 + n % 2, cmp);
    sort(arr + n / 2 + n % 2, arr + n, cmp);
    //输出
    if (arr[n/2 + n%2].key > arr[0].key){
        printf("%d", arr[0].id);
    }else{
        printf("%d", arr[n/2 + n%2].id);
    }
    return 0;
}