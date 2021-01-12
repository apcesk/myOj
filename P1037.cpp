#include<iostream>
#include<string>
#include<cstring>
using namespace std;

/**
 * 用于存储每个数字的变化可能性
 * 如number_change[i][j] = 1 代表i能够变换成j
 * number_change[i][j] = 0 代表i不能能够变换成j
 */ 
bool number_change[10][10];
/**
 * 记录每个数字的变换方式有几种
 * 如 map_number[3] = 5; 代表3有五种变换方式
 */ 
int map_number[10];
// 弗洛伊德算法让图进行联通
void floyd() {
  // 图联通
  for(int k = 0;k <= 9;++k) {
    for (int i = 0;i <= 9;++i) {
      for (int j = 0;j <= 9;++j) {
        number_change[i][j] = number_change[i][j] || (number_change[i][k] && number_change[k][j]);
      }
    }
  }
  // 每个数字的变换数量记录
  for (int i = 0;i <= 9;++i) 
    for (int j = 0;j <= 9;++j)
      map_number[i] = number_change[i][j] ? map_number[i]+1 : map_number[i];
}
/**
 * 存储高精度结果的数组
 * 注意初始化为一个1，方便后面进行乘法运算
 */ 
char res[50] = {'1'};
/**
 * 高精度乘法 -> 用于高精度*低精度(一个int类型数)，已知参数n是小于等于10的
 * @param {int} n 一定是一个小于等于10的数字
 */ 
void multiple(int n){
  int jw = 0, a;
  for (int i = 0;i < strlen(res);++i) {
    res[i] = (res[i] - '0') * n + jw;
    jw = res[i] / 10;
    res[i] = res[i] % 10 + '0';
  }
  if (jw != 0) {
    res[strlen(res)] = jw + '0';
  }
}

int main(){
  // 数字n，规则k
  string n;
  int k;
  cin>>n>>k;
  // 默认自己是能转变成自己的。
  for (int i = 0;i <= 9;i++) number_change[i][i] = 1;
  // 输入变换规则，同时变换规则记录下来
  for (int i = 0;i < k;i++) {
    int s,e;
    cin>>s>>e;
    // 能够从s 变成 e
    number_change[s][e] = 1;
  }
  // 使用floyed，使得数的变换得以联通。
  floyd();
  // 使用高精度乘法(高精度*低精度)，让n字符串中的每个数字变化相乘即可。
  for (int i = 0;i < n.length();++i){
    // cout<<"n[i]"<<n[i]<<endl;
    multiple(map_number[n[i] - '0']);
  }
  // 输出结果，记得倒序
  for (int i = strlen(res) - 1;i >= 0;--i) {
    cout<<res[i];
  }
  cout<<endl;
  return 0;
}