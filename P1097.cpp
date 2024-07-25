#include<cstdio>
#include<map>
#include<unordered_map>
#include<set>
using namespace std;
int main() {
    unordered_map <int,int> a;  //把它看成数组
    set <int> b;
    int n,i,q;
    scanf("%d", &n);
    for(i=1; i<=n; i++) {
        scanf("%d",&q);
        a[q]++;
        b.insert(q);
    }
    for(set<int>::iterator it=b.begin(); it!=b.end(); it++) //迭代器
        printf("%d %d\n",*it,a[*it]);
    return 0;
}