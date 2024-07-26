#include<cstdio>
#include<iostream>
#include<cmath>
#define ll long long
using namespace std;
#define int long long 
const int maxn=1000010;
int n,xl,xr,yl,yr;
signed main(){
	cin>>n;
	cin>>xl>>yl>>xr>>yr;// 矿场的左下角和右上角
	double ans=1e9;
	int ansid=0;
	for(int i=1;i<=n;++i){// 枚举每个矿车
		int x,y;// 矿车的位置
		scanf("%lld%lld",&x,&y);
		double dis;// 最近的距离
		if(xl<=x&&x<=xr)dis=min(abs(y-yl),abs(y-yr));// 矿车的x坐标介于两个x之间，那么距离就是到y边的距离
		else if(yl<=y&&y<=yr)dis=min(abs(x-xl),abs(x-xr));// 矿车的y坐标介于两个y之间，那么距离就是到x边距离
		else 	// 计算矿车距离矩形矿场的4个点哪个最近。
					dis=min(
									min(sqrt((x-xl)*(x-xl)+(y-yl)*(y-yl)),
											sqrt((x-xl)*(x-xl)+(y-yr)*(y-yr))),
									min(sqrt((x-xr)*(x-xr)+(y-yl)*(y-yl)),
											sqrt((x-xr)*(x-xr)+(y-yr)*(y-yr)))
					);
		if(dis<ans)ans=dis,ansid=i;// 更新最小值
		printf("%.9lf ",dis);
	}
	cout<<endl;
	cout<<ansid<<endl;
	return 0;
}
