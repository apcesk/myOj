#include<iostream>
#include<cstdio>
using namespace std;
unsigned long long map[21][21]={1};//地图
bool _map[21][21];//标记当前位置能否行走,1为不能走
void mark_horse(int hx, int hy);//标记被马所看管的位置
void dp(int bx, int by);//解决问题的dp方程
void init_map();//初始化地图
void outMap();//输出地图函数->只是当时留作debug用的
int main(){
    //卒初始位置为0,0
    //获取b点和马的坐标
    int bx,by,hx,hy;//保存b点和马的坐标
    scanf("%d%d%d%d", &bx, &by, &hx, &hy);
    //对于不能行走的点进行标记
    mark_horse(hx, hy);
    //初始化地图
    init_map();
    //动态规划找到有几种路径
    dp(bx, by);
    //输出路径
    printf("%lld", map[bx][by]);
    // outMap();
    return 0;
}
/*
过河卒，只能够往右或者往右或者往下
给出卒(0,0)和马(n,m)的坐标，求出从卒到b的位置
*/
//标记不能走的位置
void mark_horse(int hx, int hy){
    int dir[8][2] = {{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
    _map[hx][hy] = 1;
    int i = 0;
    while (i < 8){
        if (hx + dir[i][0] <= 20 && hy + dir[i][1] <= 20
            && hx + dir[i][0] >= 0 && hy + dir[i][1] >= 0 ){
                _map[hx + dir[i][0]][hy + dir[i][1]] = 1;
            }
        ++i;
    }
    return ;
}
void dp(int bx, int by){
    for (int i = 1;i <= 20;++i){
        for (int j = 1;j <= 20;++j){
            if(!_map[i][j]){//这个点能否走到，
                //如果左侧是0
                if (_map[i-1][j] == 1) {map[i][j] = map[i][j-1];}
                else if (_map[i][j-1] == 1) {map[i][j] = map[i-1][j];}
                else {map[i][j] = map[i-1][j] + map[i][j-1];}
            }else{
                map[i][j] = 0;
            }
        }
    }
}
/**/
void outMap(){
    for (int i = 0;i <= 20;++i){
        for (int j = 0;j <= 20;++j){
            printf("%lld ", map[i][j]);
        }
        printf("\n");
    }
    return ;
}

void init_map(){
    for (int i = 0;i <= 20;++i){
        if (!_map[i][0]){
            map[i][0] = 1;
        }else{
            break;
        }
    }
    for (int i = 0;i <= 20;++i){
        if (!_map[0][i]){
            map[0][i] = 1;
        }else{
            break;
        }
    }

}