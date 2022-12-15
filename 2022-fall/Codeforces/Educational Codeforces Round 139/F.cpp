#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define all(x) x.begin(),x.end()

const int V=105,E=1005,inf=0x3f3f3f3f;
int S,T,e=1,fir[V],to[E],nxt[E],w[E],c[E];
inline void adde(int x,int y,int z,int t){
	//cout<<x<<' '<<y<<' '<<z<<' '<<t<<endl;
	to[++e]=y,nxt[e]=fir[x],fir[x]=e,w[e]=z,c[e]=t;
	to[++e]=x,nxt[e]=fir[y],fir[y]=e,w[e]=0,c[e]=-t;
}
int dis[V],q[E];
bool vis[V];
bool spfa(){
	memset(dis,63,sizeof(dis));
	memset(vis,0,sizeof(vis));
	int l=1,r=0;
	q[++r]=T,dis[T]=0;
	while(l<=r){
		int u=q[l++];vis[u]=0;
		for(int i=fir[u],v=to[i];i;v=to[i=nxt[i]]){
			if(!w[i^1]||dis[v]<=dis[u]+c[i^1])continue;
			dis[v]=dis[u]+c[i^1];
			if(!vis[v])vis[v]=1,q[++r]=v;
		}
	}
	return dis[S]<inf;
}
int cur[V];
int dfs(int u,int flow){
	if(u==T||!flow)return flow;
	vis[u]=1;
	int nowf=flow;
	for(int& i=cur[u];i;i=nxt[i]){
		int v=to[i];
		if(dis[v]+c[i]!=dis[u]||vis[v])continue;
		int f=dfs(v,min(w[i],nowf));
		w[i]-=f,w[i^1]+=f;
		if(!(nowf-=f))return flow;
	}
	return flow-nowf;
}
int MCMF(){
	int flow=0,res=0;
	while(spfa()){
		memcpy(cur,fir,sizeof(cur));
		memset(vis,0,sizeof(vis));
		int f=dfs(S,inf);
		flow+=f,res+=dis[S]*f;
	}return res;
}

int n,m,x,y,z[E],t[E],f[V];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		cin>>x>>y>>z[i]>>t[i];
		if(t[i]>=0){
			adde(x,y,z[i]>>1,t[i]<<1);
			if(z[i]&1)--f[x],++f[y];
		}
		else{
			adde(y,x,z[i]>>1,-t[i]<<1);
			f[x]-=z[i],f[y]+=z[i];
		}
	}
	S=n+1,T=n+2;
	if((f[1]&1)&&f[n]&1)++f[1],--f[n];
	for(int i=1;i<=n;++i){
		//cout<<f[i]<<' ';
		if(f[i]&1){
			cout<<"Impossible\n";
			return 0;
		}
		if(f[i]>0)adde(S,i,f[i]>>1,0);
		if(f[i]<0)adde(i,T,-f[i]>>1,0);
	}
	adde(n,1,inf,0);
	MCMF();
	cout<<"Possible"<<endl;
	for(int i=1;i<=m;++i){
		if(t[i]>=0)cout<<w[i*2+1]*2+(z[i]&1)<<' ';
		else cout<<z[i]-w[i*2+1]*2<<' ';
	}
	cout<<'\n';
}