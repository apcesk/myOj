#include<cstdio>
#include<cctype>
#include<algorithm>
#define N 10000008
#define R register
using namespace std;

int n,w[28],mid,head[N];
struct cod{int u,val;}e[200008],edge[N];
int v[N],ans,tot,ttt,sta,cnt;
bool vis[2500000];
void dfs1(int dep,int sum,int state)
{
	if(dep>mid)
	{
		edge[++tot].u=head[state];
		edge[tot].val=sum;
		head[state]=tot;
		return;
	}
	dfs1(dep+1,sum,state);
	dfs1(dep+1,sum+w[dep],state|(1<<(dep-1)));
	dfs1(dep+1,sum-w[dep],state|(1<<(dep-1)));
}
void dfs2(int dep,int sum,int state)
{
	if(dep>n)
	{
		e[++ttt].u=state;
		e[ttt].val=sum;
		return;
	}
	dfs2(dep+1,sum,state);
	dfs2(dep+1,sum+w[dep],state | (1<<(dep-1)));
	dfs2(dep+1,sum-w[dep],state | (1<<(dep-1)));
}
inline bool ccp(const cod&a,const cod&b)
{
	return a.val<b.val;
}
int main()
{
	cin >> n;
  mid=(n+1)>>1;
  sta=(1<<n)-1;
	for(R int i=1;i<=n;i++)cin >> w[i];
	dfs1(1,0,0);
  dfs2(mid+1,0,0);
	sort(e+1,e+ttt+1,ccp);
	for(R int i=0;i<=(1<<mid);i++)
	{
		R int cnt=0;
		for(R int j=head[i];j;j=edge[j].u)
			v[++cnt]=edge[j].val;
		sort(v+1,v+cnt+1);
		R int pos=1;
		if(v[1]>e[ttt].val)break;
		for(R int j=1;j<=ttt;j++)
		{
			while(pos<=cnt and v[pos]<e[j].val)pos++;
			if(pos>cnt)break;
			if(v[pos]==e[j].val)
				vis[i|e[j].u]=true;
		}
	}
	for(R int i=1;i<=sta;i++)
		if(vis[i])ans++;
	printf("%d",ans);
}
