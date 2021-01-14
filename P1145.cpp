#include<iostream>
using namespace std;
/**
 * k个好人站在一起，k个坏人站在一起。
 * 从第一个好人开始宝书，要求找到一个数字m
 * 使得所有的坏人先出局
 */
/**
 * 保存约瑟夫圈的状态，0为出圈，1为坏人，2为好人
 */ 
// int arr[28];
// // 重制圈的状态
// void reset(int k){
//   for (int i = 1;i <= 2*k;++i) {
//     if (i <= k) arr[i] = 2;
//     else arr[i] = 1;
//   }
// }
// void outArr(int k) {
//   for (int i = 1;i <= 2*k;++i) {
//     cout<<arr[i]<<endl;
//   }
// }
// int main(){
//   // 输入k, 共有2k个人
//   int k;
//   cin>>k;
//   int jishu = 0;
//   // 开始找m
//   int m = k;
//   // bool first = true;
//   // cout<<m<<endl;
//   reset(k);
//   while (1) {
//     m++;
//     int i = 1; // 数组下标
//     int man = 0;// 当前报的数
//     int chuquan = 0;// 出圈的人数
//     while (i) {
//       // 判断当前这个位置有人没
//       if (arr[i] != 0) {
//         man++;// 报数
//         // first && cout<<man<<endl;
//         // first = false;
//         // 判断报的数是否是 m
//         if (man % m == 0 && arr[i] == 1) { // 是m且是坏人则出圈
//           arr[i] = 0;// 设置为出圈
//           chuquan++;// 出圈的人数+1
//           //判断出圈的人数是否为k个
//           if (chuquan == k) {// 如果为k个，则说明坏人都出圈了
//             cout<<m<<endl;
//             return 0;
//           }
//         } else if(man % m == 0 && arr[i] == 2) {// 是m但是是好人，则不能出圈，说明m这个数字不行
//           reset(k);
//           break;
//         }
//       }
//       i++;// 下标进行递增。
//       if (i == 2*k+1) { // 如果走完一个圈了
//         i = 1;
//       }
//     }
//   }
//   return 0;
// }

int main()
{
  int k,i;
  cin>>k;
  // flag作为标记是否找到了最小值m，找到了则直接退出。
  int flag=1,m=k;
  while (flag)
  {
    //m至少为k+1
    m++;
    int number=0;// 设置出圈的编号
    // 由于只有k个坏人，所以只需要执行k次出圈即可。
    for (i=0; i<k; i++)
    {
      // 计算出下一次要出圈人的编号
      /**
       * cursor代表要出圈人的编号
       * m代表指定出圈的数字，由于编号是从0开始的，所以要m-1
       * 2*k代表总人数，而i则代表已经出圈的人数 则 (2 * k - i)代表圈内剩下的人数
       */ 
      number=(number+m-1)%(2*k-i);
      // 由于编号0 -> k-1 的都是好人，所以如果出圈的编号是好人的话，则说明这个m不对。
      if (number<k)break;
      // 如果出圈的人数是k个了，则说明找到了最小的m
      if (i==k-1)flag=0;
    }
  }
  cout<<m<<endl;
  return 0;
}
