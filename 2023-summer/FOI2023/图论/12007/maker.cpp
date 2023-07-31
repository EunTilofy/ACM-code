#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int N=1e6+3,K=20;
int n,m,q,x,y,op,k,A,B,ans,f[N],a[N];
int F(int x){
	return x^(1ll*A*ans+B)^ans;
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

int c[N];
void mdf(int x,int y){
	for(;x<=m;x+=x&-x)c[x]+=y;
}
int qry(int x){
	int r=0;
	for(;x;x-=x&-x)r+=c[x];
	return r;
}
int kth(int x){
	int r=0;
	for(int k=19;~k;--k)
		if((r|(1<<k))<=m&&c[r|(1<<k)]<x)
			r|=1<<k,x-=c[r];
	return r+1;
}

int main(int argc,char *argv[]){
	ios::sync_with_stdio(0);cin.tie(0);
	ll sd=atoi(argv[1]);
	mt19937_64 rd(time(0));
	auto rg=[&](ll l,ll r)->ll{return l+rd()%(r-l+1);};

	n=atoi(argv[2]);
	q=atoi(argv[3]);
	m=n+q;
	int in=atoi(argv[4]);
	if(in)A=1,B=0;
	else A=rg(1,100),B=rg(1,100);

	for(int i=1;i<=m;++i)a[i]=i;
	shuffle(a+1,a+m+1,rd);

	cout<<n<<'\n';
	for(int i=1;i<=n;++i)cout<<a[i]<<" \n"[i==n],mdf(a[i],1),f[a[i]]=a[i];
	cout<<q<<' '<<A<<' '<<B<<'\n';
	int cnt=n,cur=n;
	for(int i=1;i<=q;++i){
		int op=rg(1,100);
		if(cur>=20)
			op=op<=50?1:2;
		else if(cur>=10)
			op=op<=10?1:2;
		else if(cur>=5)
			op=op<=3?1:2;
		cout<<op<<' ';
		if(op==1){
			x=a[++cnt];
			f[x]=x;
			cout<<F(x)<<' ';
			int k=rg(1,min(cur,3));
			cout<<k<<' ';
			for(int i=1;i<=k;++i){
				int t=rg(1,cur);
				int y=kth(t);
				cout<<F(y)<<" \n"[i==k];
				--cur,mdf(y,-1);
				f[y]=x;
				for(int i=0;i<20;++i)
					dfs(e[x][i],y,i,i-1);
			}
			for(int i=0;i<20;++i)
				for(int v:e[x][i])
					fa[v][i]=x;
			++cur,mdf(x,1);
		}
		else{
			x=a[rg(1,cnt)],y=a[rg(1,cnt)];
			cout<<F(x)<<' '<<F(y)<<'\n';
			if(find(x)!=find(y))ans=0;
			else ans=lca(x,y);
		}
	}
}