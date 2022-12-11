#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define all(x) x.begin(),x.end()

const int N=2e5+3,mod=1e9+7;
int n,m,k;
vector<vector<int>> a;
vector<pii> e[N];
inline void adde(int x,int y,int z){
	e[x].push_back(pii(y,z));
	e[y].push_back(pii(x,(k-z)%k));
}
int dis[N];
bool vis[N],flag=1;
void dfs(int u,int f){
	vis[u]=1;
	for(auto&[v,w]:e[u])if(v^f){
		if(!vis[v])dis[v]=(dis[u]+w)%k,dfs(v,u);
		else{
			if(dis[v]!=(dis[u]+w)%k)flag=0;
		}
	}
}
int solve(){
	cin>>n>>m>>k;
	a.resize(n);
	for(int i=0;i<n;++i){
		a[i].resize(m);
		for(int j=0;j<m;++j)cin>>a[i][j];
	}
	if(n>m){
		vector<vector<int>> b;
		b.resize(m);
		for(int i=0;i<m;++i){
			b[i].resize(n);
			for(int j=0;j<n;++j)b[i][j]=a[j][i];
		}
		swap(a,b);
		swap(n,m);
	}
	int num0=0, num1=0;
	for(int i=0;i<n;++i){
		int num=0;
		for(int j=0;j<m;++j) num+=a[i][j]!=-1;
		if(num==0) ++num0;
		if(num==1) ++num1;
	}
	cerr<<num0<<" "<<num1<<endl;
	if(num1+num0==n) {
		int aans=1;
		for(int i=1;i<=num0+m-1;++i) aans=aans*k%mod;
		return aans;
	}
	flag=1;
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			if(~a[i][j])flag=0;
	if(flag){
		ll ans=1;
		for(int i=0;i<m+n-1;++i)ans=ans*k%mod;
		return ans;
	}
	for(int i=0;i<m;++i)e[i].clear();
	for(int i=0;i<n;++i){
		int p=-1;
		for(int j=0;j<m;++j)if(~a[i][j]){
			if(!~p)p=j;
			else adde(p,j,(a[i][j]-a[i][p]+k)%k);
		}
	}
	memset(vis,0,sizeof(bool)*m);
	memset(dis,0,sizeof(int)*m);
	int cnt=0;
	flag=1;
	for(int i=0;i<m;++i)if(!vis[i]){
		dfs(i,-1);
		if(!flag)return 0;
		++cnt;
	}
	ll ans=1;
	for(int i=1;i<cnt;++i)ans=ans*k%mod;

	return ans;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--)cout<<solve()<<'\n';
}