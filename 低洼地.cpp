#include<iostream>
using namespace std;
int arr[10001];
int main(){
    int n,sum=0;
    cin>>n;
    for (int i = 1;i <= n;i++) {
        cin>>arr[i];
    }
    for (int i = 2;i < n;i++) {
      // 能够形成低洼地，说明，左边一定比我高
      if (arr[i-1] > arr[i]) {
        while (i < n) {
          if (arr[i] < arr[i+1]) {
            sum++;
            break;
          } else if (arr[i] > arr[i+1]) break;
          i++;
        }
      }
    }
    cout<<sum<<endl;
    return 0;
}