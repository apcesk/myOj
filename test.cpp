#include<iostream>
#include<queue>
using namespace std;
#define M 1000
struct node {
  int data, parent;
  int leftson, rightson;
};
node tree[M];
queue<int> q;

int main() {
  int n;
  cin>>n;// 节点数目
  int min = 0x7777777;
  for (int i = 1;i <= n;i++) {
    // 在点i创建医院，获取其它所有点到医院的距离
    int k = 1;
    int sum = 0;// 总距离
    q.push(i);
    while (!q.empty()) {
      node now = tree[q.front()];
      // 让当前这个点，的父与子节点全部入队列
      q.push(now.parent);
      q.push(now.leftson);
      q.push(now.rightson);
      sum += now.data * k;
      k++;
      q.pop();
    }
    // 找到最小的sum
    if (sum < min) min = sum;
  }
  cout<<min;
  return 0;
}