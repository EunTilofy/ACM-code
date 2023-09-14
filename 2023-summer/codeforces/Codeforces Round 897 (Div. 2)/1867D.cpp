#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define all(x) x.begin(),x.end()

const int N=1e5+3;
int n,k,a[N],d[N];
bool vis[N];
bool solve(){
	cin>>n>>k;
	memset(d+1,0,sizeof(int)*n);
	for(int i=1;i<=n;++i)cin>>a[i],++d[a[i]];
	if(k==1){
		for(int i=1;i<=n;++i)if(a[i]!=i)return 0;
		return 1;
	}
	queue<int> q;
	for(int i=1;i<=n;++i)if(!d[i])q.push(i);
	while(!q.empty()){
		int u=q.front();q.pop();
		if(!--d[a[u]])q.push(a[u]);
	}
	memset(vis+1,0,sizeof(bool)*n);
	for(int i=1;i<=n;++i)if(d[i]&&!vis[i]){
		int len=0,u=i;
		while(!vis[u])++len,vis[u]=1,u=a[u];
		if(len!=k)return 0;
	}
	return 1;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--)cout<<(solve()?"YES":"NO")<<'\n';
}