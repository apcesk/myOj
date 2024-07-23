#include<iostream>
#include<cmath>

using namespace std;

#define int long long
const int N = 1e5 + 10;
int n, q;
int arr[N], st[N][21], value[N][21];

signed main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> arr[i];
        value[i][0] = arr[i];
    }
    // for (int i = 1;i <= n;i++) {
    //     st[i][1] = arr[i] + arr[i + 1] >= 10;
    //    	value[i][1] = (arr[i] + arr[i + 1]) % 10;
    // }
    for (int j = 1;j <= 20;j++) {
        for (int i = 1;i + (1 << j) - 1<= n;i++) {
            st[i][j] = st[i][j - 1] + st[i + (1 << (j - 1))][j - 1];
            // for (int k = 1;k < j;k++) {
                // st[i][j] += st[i][k] + st[i + (1 << (j - 1))][k];
            // }
            value[i][j] = value[i][j - 1] + value[i + (1 << (j - 1))][j - 1];
            st[i][j] += value[i][j] >= 10;
            // st[i][j] += value[i][j - 1] % 10 + value[i + (1 << (j - 1))][j - 1] % 10 >= 10;
            value[i][j] %= 10;
        }
    }
    cout << endl;
    for (int i = 1;i <= n;i++) {
        for (int j = 0;j <= log2(n);j++) {
            // cout << st[i][j] << ' ';
            cout << value[i][j] << ' ';
        }
        cout << endl;
    }
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        int len = log2(r - l + 1);
        cout << st[l][len] << endl;
    }
    return 0;
}