#include<iostream>
#include<queue>
using namespace std;

int map[11][11];// 任意两点之间联通
int visited[11];// 所有节点都没有被访问过
// 深搜访问所有节点
void dfs (int now) {
  visited[now] = 1;// 标记start这个点被访问过
  cout<<"当前所在行为:"<<now<<"当前点为: "<<now<<endl;
  // start是起始节点的下标
  for (int i = 1;i <= 10;i++) {
    if (map[now][i] == 1 && visited[i] == 0)
      dfs(i);
  }
}
// 创建一个队列
queue<int> q;
// 广搜遍历图
void bfs(int start) {
  // 头节点入队
  q.push(start);
  visited[start] = 1;
  // 当队列不为空
  while (!q.empty()) {
    int tmp = q.front();
    cout<<"当前点为: "<<tmp<<endl;
    for (int i = 1;i <= 10;i++) {
      if (map[tmp][i] == 1 && visited[i] == 0) {
        cout<<"当前行为: "<<tmp<<endl;
        q.push(i);
        visited[i] = 1;
      }
    }
    q.pop();
  }
}
int main() {
  // 图初始化
  for (int i = 1;i <= 10;i++ ) 
    for (int j = 1;j <= 10;j++) 
      if (i != j) map[i][j] = 1;
  // dfs(1);
  bfs(1);
  return 0;
}