#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

string arr[21];
// bool cmp(string s, string t){
//   int len1 = s.length();
//   int len2 = t.length();
//   for (int i = 0;i < len1 && i < len2;++i) {
//     if (s[i] > t[i]) {
//       return true;
//     } else if (s[i] < t[i]) {
//       return false;
//     } else {
//       continue;
//     }
//   }
//   if (len1 > len2) {
//     return false;
//   } else {
//     return true;
//   }
// }
bool cmp(string s, string t) {
  return s+t>t+s;
}
int main(){
  int n;
  cin>>n;
  for (int i = 0;i < n;i++) {
    cin>>arr[i];
  }
  // for (int i = 0;i < n;i++) {
  //   cout<<arr[i]<<endl;
  // }
  sort(arr+0,arr+n,cmp);


  for (int i = 0;i < n;i++) {
    cout<<arr[i];
  }
  return 0;
}