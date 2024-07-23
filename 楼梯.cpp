#include<iostream>

using namespace std;

long long a[5050][5050];
long long n, k;
int main() {
    cin >> n >> k;
    for (int i = 1;i <= k;i++) a[i][0] = a[i][1] = 1;
    for (int i = 2;i <= n;i++) {
        a[i][0] = a[i - 1][0];
        for (int j = i - 1;j >= max(1ll, i - k);j--) {
            //a[i] += a[j];
            int x = 0;
            for (int k = 1;k <= a[i][0];k++) {
                a[i][k] += a[j][k] + x;
                x = a[i][k] / 10;
                a[i][k] %= 10;
            }
            if (x) a[i][++a[i][0]] += x;
        }
    }
    // for (int i = 1;i <= n;i++) {
    //     for (int j = a[i][0];j >= 1;j--) {
    //         cout << a[i][j];
    //     }
    //     cout << endl;
    // }
    
    return 0;
}