#include<iostream>

using namespace std;

#define M 100+1
// shuzi[i] 代表i这个数字是否为子节点
bool shuzi[M+1];
int maxn[M+1];
struct NODE
{
  // 对于每一个节点来说，它有一个父亲，和自己的值
  int data, parent;
  // 记录左儿子的下标和右儿子的我下标
  int leftson, rightson;
};
NODE tree[M];
// i打表当前节点的下标
void xianxu(int i) {
  // 输出当前节点的下标
  cout<<i<<' ';
  if (tree[i].leftson)
    xianxu(tree[i].leftson);
  if (tree[i].rightson)
    xianxu(tree[i].rightson);
}

void houxu(int i) {
  // 输出当前节点的下标
  if (tree[i].leftson)
    houxu(tree[i].leftson);
  if (tree[i].rightson)
    houxu(tree[i].rightson);
  cout<<i<<' ';
}

void zhongxu(int i) {
  // 输出当前节点的下标
  if (tree[i].leftson)
    zhongxu(tree[i].leftson);
  cout<<i<<' ';
  if (tree[i].rightson)
    zhongxu(tree[i].rightson);
  
}

int main() {
  // n 是节点数，m是边数
  int n,m;
  cin>>n>>m;
  int x,y;
  // 找根节点，可以理解为，没有做过子节点的那个就是根节点
  for (int i = 1;i <= m;i++) {
    // 输入x和y的值
    cin>>x>>y;
    tree[y].parent = x;
    if (tree[x].leftson == 0)
      tree[x].leftson = y;
    else tree[x].rightson = y;
    maxn[x] ++;
    shuzi[y] = 1;
    // x和y代表什么， y是x的孩子
  }
  // 找根
  for(int i = 1;i <= n;i++) {
    if (shuzi[i] == 0) {
      cout<<i<<endl;
    }
  }
  int mn = -1;
  int NODE_index = -1;
  // 找到孩子节点最多的那个节点
  for (int i = 1;i <= n;i++) {
    if (maxn[i] > mn) {
      mn = maxn[i];
      NODE_index = i;
    }
  }
  // 子节点最多的那个节点
  cout<<NODE_index<<endl;
  for (int i = 1;i <= n;i++) {
    if (tree[i].parent == NODE_index) {
      cout<<i<<' ';
    }
  }
  cout<<endl<<"先序: ";
  // 输出树的先序遍历
  xianxu(4);
  cout<<endl<<"中序: ";
  zhongxu(4);
  cout<<endl<<"后序: ";
  houxu(4);
  cout<<endl;
  return 0;
}