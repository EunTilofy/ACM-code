#include<bits/stdc++.h>
using namespace std;
const int N=200005,INF=1e9;
vector<int>e[N];
int l[N],r[N],dep[N],cnt[N];
void dfs1(int x,int fa){
    l[x]=INF;
    r[x]=0;
    for(auto v:e[x]){
        if(v==fa)continue;
        dfs1(v,x);
        l[x]=min(l[x],dep[v]+1);
        r[x]=max(r[x],dep[v]+1);
        cnt[x]++;
    }
    if(cnt[x]==0)l[x]=r[x]=0;
    if(cnt[x]==1)l[x]=0;
    if(r[x]>l[x]+1)r[x]=l[x]+1;
    dep[x]=r[x];
 //   cout<<x<<" "<<l[x]<<" "<<r[x]<<" "<<dep[x]<<endl;
}
void dfs2(int x,int fa){
    if(x!=1)dep[x]=min(dep[x],dep[fa]-1);
    
 //   cout<<x<<" "<<dep[x]<<endl;
    for(auto v:e[x]){
        if(v==fa)continue;
        dfs2(v,x);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs1(1,0);
    dfs2(1,0);
    int ans=0;
    for(int i=1;i<=n;i++){
        if(dep[i]<0)ans++;
    }
    printf("%d\n",ans);
}