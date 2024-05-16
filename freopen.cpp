#include<iostream>
#include<cstdio>


using namespace std;
struct a{
  int number;
  char ch;
  int arr[10];
};
int main() {
  // f file 文件
  // re redirect 定向
  // open 打开
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
  int n,m;
  cin >> n >> m;
  cout << n * m;
  fclose(stdin);
  return 0;

}