#include<iostream>

using namespace std;
// 先序  A BFE CGD
// 中序  FBE A GCD
// 定义一个树节点类型
struct TreeNode{
  int left,right;
  char value;
};
char xian[7] = {'A', 'B', 'F', 'E',  'C', 'G', 'D'};
char zhong[7] = {'F', 'B', 'E', 'A',  'G', 'C', 'D'};
char hou[7] = {'F', 'E', 'B', 'G', 'D', 'C', 'A'};
// 后序遍历
// FEBGDCA
// F E B G D C A
// 分
// 1、在xian中找到一个“根”元素
// 2、在zhong中找到“根”元素所在的位置
// 3、把zhong找到的“根元素”左边分割成一个部分， 右边分割成一个部分
// 4、在进行上述的操作
// 直到不能分割，则输出
// 把这个方法，拆开，放入下面方法中
void devide(int index, int left, int right) {
  // index是 zhong当前从 left 到 right 中的根节点所对应的在xian中字符
  if (left == right) cout<<zhong[index]<<' ';
  if (left < 0 || right >6) return;
  // 继续分一半
  int i = left;// 代表的是在中序中，根节点的位置
  for (;i <= right;i++) {
    if (zhong[i] == xian[index]) {
      break;
    }
  }
  // 找到左区间的根节点
  // 'F'
  // 通过循环遍历找到'F'
  devide(index + 1, left, i - 1);
  // 通过循环遍历找到'E'
  devide(index + 1, i + 1, right);
  // 输出左子树的根
  cout<<xian[index]<<' ';
}
/**
 * @param index 是指，根节点在xian中的下标
 * @param  left 是指，根节点左边的节点数目，以xian为基准的
 * @param  right 是指，根节点右边的节点数目，以xian为基准的
 */ 
void build_tree(int index) {
  // 输出左子树
  // 在zhong找到root的值
  int i = 0;// i还是右极限
  for (int i = 0;i < strlen(zhong);i++) {
    if (zhong[i] == xian[index]) {
      break;
    }
  }
  for (int i = index + 1; i < strlen(xian);i++) {
    // 对中序的左一半进行分割（对中序左一半的根节点进行分割）
    if (i % 2 == 1) devide(i, 0, i-1);
    else devide(i, 0, i-1);
  }
  
  // 输出右子树

  // 输出根节点
  cout<<xian[index]<<' ';
}
// 

int main() {
  build_tree(0);
  return 0;
}