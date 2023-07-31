#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e6+3,K=20;
int n,q,x,y,op,k,A,B,ans,f[N];
int F(int x){
	return x^(A*ans+B)^ans;
}
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
vector<int> e[N][K];
int fa[N][K];
int dep(int x){
	int res=0;
	for(int i=19;~i;--i)if(fa[x][i])x=fa[x][i],res|=1<<i;
	return res;
}
int lca(int x,int y){
	int dx=dep(x),dy=dep(y);
	if(dx<dy)swap(x,y),swap(dx,dy);
	int t=dx-dy;
	for(int i=19;~i;--i)if(t>>i&1)x=fa[x][i];
	if(x==y)return x;
	for(int i=19;~i;--i)if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
void dfs(vector<int>& res,int x,int k,int i){
	if(i<0){
		res.push_back(x);
		return;
	}
	for(int v:e[x][i])dfs(res,v,k,i-1);
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)cin>>x,f[x]=x;
	cin>>q>>A>>B;
	while(q--){
		cin>>op;
		if(op==1){
			cin>>x>>k,x=F(x),f[x]=x;
			while(k--){
				cin>>y,y=F(y),f[y]=x;
				for(int i=0;i<20;++i)
					dfs(e[x][i],y,i,i-1);
			}
			for(int i=0;i<20;++i)
				for(int v:e[x][i])
					fa[v][i]=x;
		}
		else{
			cin>>x>>y,x=F(x),y=F(y);
			if(find(x)!=find(y))cout<<"0\n";
			else{
				ans=lca(x,y);
				cout<<ans<<'\n';
			}
		}
	}
}