#include<iostream>

using namespace std;
#define int long long 
int n;
int arr[55], L, R;
int minn = 0, maxn = 0, sum = 0;
signed main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    cin >> L >> R;
    if (sum > n * R || sum < n * L) {
      cout << -1;
      return 0;
    }
    for (int i = 1;i <= n;i++) {
        if (arr[i] >= R) {
            maxn += arr[i] - R;
        }
        if (arr[i] <= L) {
            minn += L - arr[i];
        }
    }
    cout << max(maxn, minn);
    
    return 0;
}