#include<iostream>
#include<cmath>
using namespace std;

int main() {
  long long n;
  cin>>n;
  for (long long i = 1, l = sqrt(n);i <= l;i++) cout<<i*i<<endl;
  return 0;
}