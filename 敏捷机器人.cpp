#include<iostream>
#include<cmath>

using namespace std;
#define int long long
const int N = 1e5 + 10;
int n, k;
int stmax[N][21], stmin[N][21];
signed main() {
    cin >> n >> k;
    for (int i = 1;i <= n;i++) {
        cin >> stmax[i][0];
        stmin[i][0] = stmax[i][0];
    }
    for (int j = 1;j <= 20;j++){
        for (int i = 1;i + (1 << j) - 1 <= n;i++) {
            stmax[i][j] = max(stmax[i][j - 1], stmax[i + (1 << (j - 1))][j - 1]);
            stmin[i][j] = min(stmin[i][j - 1], stmin[i + (1 << (j - 1))][j - 1]);
        }
    }
    int len = log2(k);
    for (int i = 1;i <= n - k + 1;i++) {
        cout << max(stmax[i][len], stmax[i + k - (1 << len) - 1][len]) << ' '
             << min(stmin[i][len], stmin[i + k - (1 << len) - 1][len]) << endl;
    }
    return 0;
}