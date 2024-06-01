#include<iostream>

using namespace std;
#define int long long
/**
 * CDQ分治本质是一种“时间序”分治算法。
 * “修改不影响贡献”
 */
/**
 * 题目含义：
 * 在一个三维坐标系中，找到满足条件的指定点的个数
 * 对于一个点用(x,y,z)描述，
 * 输入描述：
 * n个点，每个点的x,y,z取值最大为k
 * 
 */
/**
 * 思路：
 * 所有数字的取值范围是2e5以内，提示用权值记录每个数字出现的次数
 * 先对所有的点进行按x排序，
 * 然后使用归并排序的思路，把序列分成左右两半。(先按照x排序)
 * 此时对于右一半的序列来说，肯定都比左一半的序列的x坐标要大。
 * 那么此时再将左右两半的数据再度按照y值进行排序。
 * 进而确定是否满足 yl <= yr,
 * 双指针维护左右两半
 * 再然后，yl <= yr的情况下，将zl的贡献加入到树状数组中。
 * 若yl > yr，则查询树状数组中有多少个数<=zr,及累计小于等于r的元素个数，计算当前的f(l)
 * 最后清空树状数组，并对当前的l到r区间按y进行排序，回溯原始状态
 */
const int N = 1e5 + 10, M = 2e5 + 10;//N是元素个数，M是k值上限
int n, k;// n个点，最大值是k
struct Node {
  int x, y, z;// 坐标值
  int cnt, s;// cnt是重复点个数，s是比该点“小”的点数目
  // 假设该点的下标是i，则f(i)的值应当为s，但是由于有重复点。
  // 所以结果是 s + cnt - 1
  // 重定义比较运算
  bool operator == (const Node &ant) {// 为了判断重复的点使用的比较
    return x == ant.x && y == ant.y && z == ant.z;
  }
} arr[N];
bool cmpx(const Node a, const Node b);// 按x升序
bool cmpy(const Node a, const Node b);// 按y升序
// 树状数组套装
int lowbit(int x) {return x & -x;};
int tree[M], // 权值树状数组 logn
    ans[N];// 记录答案数组，ans[i] = k d=k的情况下的值 = f(i)的结果
void change(int x, int k) {// 修改函数，向后修改自身的贡献
  while (x <= M) {// 树状数组的点修改。
    tree[x] += k;
    x += lowbit(x);
  }
}
int query(int x) {// 查找，比自己小的元素个数
  int cnt = 0;// 查询
  while (x) {
    cnt += tree[x];
    x -= lowbit(x);
  }
  return cnt;
}
// 
void cdq(int l, int r) {// cdq分治，考虑成归并排序，由于树状数组是权值的树状数组，所以这里l和r也代表权值
  if (l == r) return;// 单点
  int mid = (l + r) >> 1;
  cdq(l, mid);
  cdq(mid + 1, r);// 按照x排序进行分裂
  int i = l, j = mid + 1;// 左右指针
  // 此处左一半x比右一半的x小，
  // 左一半和右一半均按照y升序
  while (i <= mid && j <= r) {// 统计左右两半中，符合题目要求的个数
    if (arr[i].y <= arr[j].y) {// 此时确认，左边的点比右边点的x和y都小
      // 那么把该点的z坐标放进去
      change(arr[i].z, arr[i].cnt);// 把左侧点的z坐标存到权值树状数组中。
      i++;// 左边指针右移
    } else {// 否则不满足左边的y小于当前右边的y
      // 此处右指针指向的元素，加上左侧所有比我小的元素的个数
      arr[j].s += query(arr[j].z);// 累计小于等于点j的点个数
      j++;
    }
  }
  while (i <= mid) {change(arr[i].z, arr[i].cnt);i++;};// 处理左一半
  while (j <= r) {arr[j].s += query(arr[j].z);j++;};// 处理右一半
  // 清空树状数组 -> 为什么？为了去掉重复贡献
  for (int t = l;t <= mid;t++) {
    change(arr[t].z, -arr[t].cnt);
  }
  sort(arr + l, arr + r + 1, cmpy);// 按y升序排列
}
bool cmpx(const Node a, const Node b) {// 优先按x排序
  if (a.x != b.x) return a.x < b.x;
  else if (a.y != b.y) return a.y < b.y;
  return a.z < b.z;
}
bool cmpy(const Node a, const Node b) {// 按y排序
  return a.y < b.y;
}
signed main() {
  scanf("%lld%lld", &n, &k);
  for (int i = 1;i <= n;i++) {// 输入每个点
    scanf("%lld%lld%lld", &arr[i].x, &arr[i].y, &arr[i].z);
    arr[i].cnt = 1;
  }
  // 先排序,先按照x升序排序
  sort(arr + 1, arr + 1 + n, cmpx);
  // 重复点变成一个，去重
  int k = 1;// k代表不重复的点的个数
  for (int i = 2;i <= n;i++) {
    if (arr[i] == arr[k]) {// 如果和上一个点相同
      arr[k].cnt++;// 则重复点个数增加
    } else {// 否则是一个新点，则直接加入到数组中
      arr[++k] = arr[i];// 思考一下
    }
  }
  cdq(1, k);// cdq分治+权值树状数组
  for (int i = 1;i <= k;i++) {// 计算所有的d值方案数，f(i)
    // 比点i小的点数是s个，点i有arr[i].cnt个
    ans[arr[i].s + arr[i].cnt - 1] += arr[i].cnt;
  }
  for (int i = 0;i < n;i++) {
    printf("%lld\n", ans[i]);
  }
  return 0;
}
/**
DDDDD           IIIIII        OOOOOOOO
DD  DD            II          OO    OO
DD   DD           II          OO    OO
DD    DD          II          OO    OO
DD    DD          II          OO    OO
DD    DD          II          OO    OO
DD   DD           II          OO    OO
DD  DD            II          OO    OO
DDDDD           IIIIII        OOOOOOOO
*/