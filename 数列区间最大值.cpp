#include<iostream>
#include<cmath>

using namespace std;
#define int long long
const int N = 1e5 + 10;
int n, m;
int st[N][31];

signed main() {
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        cin >> st[i][0];
    }
    for (int j = 1;j <= log2(n);j++) {
        for (int i = 1;i + (1 << j) - 1 <= n;i++) {
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
    for (int i = 1;i <= n;i++) {
      for (int j = 0;j <= log2(n);j++) {
        cout << st[i][j] << ' ';
      }
      cout << endl;
    }
    while (m--) {
        int l , r;
        cin >> l >> r;
        int len = log2(r - l + 1);
        cout << max(st[l][len], st[r - (1 << len)][len]) << endl;
    }
    return 0;
}