#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int N=2e5+5;
struct bit
{
	const static int N=1<<18|5;
	int a[N];
	void init()
	{
		memset(a,0,sizeof a);
	}
	void add(int x,int y)
	{
		a[x]+=y;
		while ((x+=x&-x)<N) a[x]+=y;
	}
	int sum(int x)
	{
		int r=a[x];
		while (x^=x&-x) r+=a[x];
		return r;
	}
	int sum(int x,int y)
	{
		return sum(y)-sum(x-1);
	}
	int search(int r)
	{
		int x=0;
		for (int i=17; i>=0; i--) if (a[x|1<<i]<r) r-=a[x|=1<<i];
		return x;
	}
};
bit s;
int pre[N];
void fun(ll *ans,vector<int> a)
{
	int n=a.size()-1,i,j;
	s.init();
	vector<int> b(1+all(a));
	sort(all(b)); assert(unique(all(b))==b.end());
	for (i=1; i<=n; i++) a[i]=lower_bound(all(b),a[i])-b.begin()+1;
	vector<int> pos(n+1);
	vector<vector<int>> turn(n+2);
	for (i=1; i<=n; i++) pos[a[i]]=i;
	for (i=1; i<=n; i++)
	{
		int x=pos[i],y;
		assert(x);
		pre[x]=s.sum(x);
		y=i>pre[x]*2?s.search(pre[x]*2)+1:n+1;
		turn[y].push_back(x);
		s.add(x,1);
	}
	ll cur=0;
	int cnt=0;
	s.init();
	for (i=1; i<=n; i++)
	{
		int dt=i-pre[i]-1-(cnt-s.sum(a[i]));
		cur+=dt;
		ans[i]=cur;
		for (int x:turn[i]) s.add(a[x],1);
		cnt+=turn[i].size();
	}
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n,i,j;
	cin>>n;
	vector<int> a(n+1);
	for (i=1; i<=n; i++) cin>>a[i];
	static ll ans1[N],ans2[N];
	fun(ans1,a);
	for (int &x:a) x=-x;
	// for (i=1; i<=n; i++) cerr<<ans1[i]<<" \n"[i==n];
	fun(ans2,a);
	// for (i=1; i<=n; i++) cerr<<ans2[i]<<" \n"[i==n];
	for (i=1; i<=n; i++) cout<<min(ans1[i],ans2[i])<<'\n';
}