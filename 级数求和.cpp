#include<iostream>


using namespace std;

int main() {
  int k;
  cin >> k;
  int Sn = 1;
  int n;
  while (Sn <= k) {
    Sn = Sn + 1 / n;
    n++;
  }
  cout << n << endl;
  return 0;
}