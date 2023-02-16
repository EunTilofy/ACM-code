#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define all(x) x.begin(),x.end()

const int N=2.5e5+3;
int n,q,x[N],y[N],z[N],d[N],a[N];
vector<pii> e[N];
vector<pii> g[N];
inline void adde(int x,int y,int i){
	e[x].emplace_back(y,i),++d[y];
}
vector<int> tmp; int ttmp;
bool fix = 0;
int dis[N];
bool vis[N],o[N];
int p[N];
void dfs(int u,int f){
	vis[u]=1;
	for(auto &[v,w]:g[u])if(v^f){
		if(vis[v]){
			if(dis[v]^dis[u]^w){
				cout<<"No\n";
				exit(0);
			}
			continue;
		}
		dis[v]=dis[u]^w;
		dfs(v,u);
	}
    if(!fix){
        if(d[u]&1) ++ttmp;
        tmp.push_back(u);
    }
}
int mx[N],siz[N],top[N],fa[N],dep[N];
void Dfs1(int x,int f){
    siz[x]=1;fa[x]=f;dep[x]=dep[f]+1;
    for(auto &[y,i]:e[x])if(y^f){
        Dfs1(y,x);siz[x]+=siz[y];
        siz[y]>siz[mx[x]]?mx[x]=y:0;
    }
}
void Dfs2(int x,int f,int tp){
    if(mx[x])Dfs2(mx[x],x,tp);
    for(auto &[y,i]:e[x])if((y^f)&&(y^mx[x])) Dfs2(y,x,y);
}
int LCA(int x,int y){
    while(top[x]^top[y]){
        if(dep[top[x]]>dep[top[y]]) swap(x,y);
        y=fa[top[y]];
    }
    return dep[x]<dep[y]?x:y;
}
int ans[N],anss=0;
void dfs2(int u,int f,int id){
	for(auto& [v,i]:e[u])if(v^f){
		ans[i]=dis[u]^dis[v];
		anss^=ans[i];
		dfs2(v,u,i);
        a[u]+=a[v];
	}
    if(u!=1&&a[u]==0) p[id]=1;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>q;
    vector<pii> edg;
	for(int i=1,x,y;i<n;++i){
		cin>>x>>y;
		adde(x,y,i),adde(y,x,i);
        edg.push_back({x,y});
	}
    Dfs1(1,0);Dfs2(1,0,1);
	for(int i=1;i<=q;++i){
		cin>>x[i]>>y[i]>>z[i];
		g[x[i]].emplace_back(y[i],z[i]);
		g[y[i]].emplace_back(x[i],z[i]);
		o[x[i]]=o[y[i]]=1;
        --a[x[i]];--a[y[i]];a[LCA(x[i],y[i])]+=2;
	}
	for(int i=1;i<=n;++i){
        if(!vis[i])dfs(i,0);
        if(!fix&&ttmp&1)fix=1;
        if(!fix) tmp.clear();
    }
	cout<<"Yes\n";
	dfs2(1,0,0);
    if(anss&&fix){
        for(auto x:tmp){
            dis[x]^=anss;
        }
        anss=0;
    }
    // cerr << anss << endl;
	int pos=0;
	for(int i=1;i<=n;++i)if(!o[i]&&(d[i]&1)){pos=i;break;}
	if(pos){
		for(int i=0;i<30;++i)if(anss>>i&1){
			for(auto &[v,j]:e[pos])ans[j]^=1<<i;
            anss^=(1<<i);
		}
	}
    for(int i=1;i<n;++i)if(p[i]){
        ans[i]^=anss;
        anss=0;
    }
	for(int i=1;i<n;++i)cout<<(dis[edg[i-1].first]^dis[edg[i-1].second])<<' ';
	cout<<'\n';
}