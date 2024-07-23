#include<iostream>

using namespace std;
#define int long long
const int N = 1e5 + 10;
int m, cnt;// 政府对商品的预期价格
int red;// red代表高于最高单价之后，每升高1元钱减少的销量
struct node {
  int price, count;// 售价price，销量count
} arr[N];
signed main() {
  cin >> m;
  int p, c;
  while (1) {
    cin >> p >> c;
    if (p == c && p == -1) {
      break;
    }
    arr[++cnt] = (node){p, c};
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