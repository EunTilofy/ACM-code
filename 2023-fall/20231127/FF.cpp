#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500005;
int fa[N][20],dep[N],dis[N];
vector<pair<int,int>>e[N];
void dfs(int x,int pre){
    fa[x][0]=pre;
    for(int i=1;i<20;i++){
        fa[x][i]=fa[fa[x][i-1]][i-1];
    }
    for(auto [v,w]:e[x]){
        if(v==pre)continue;
        dis[v]=dis[x]+w;
        dep[v]=dep[x]+1;
        dfs(v,x);
    }
}
int lca(int x,int y){
    if(dep[x]<dep[y])swap(x,y);
    for(int i=19;i>=0;i--){
        if(dep[fa[x][i]]>=dep[y]){
            x=fa[x][i];
        }
    }
    if(x!=y){
        for(int i=19;i>=0;i--)
            if(fa[x][i]!=fa[y][i]){
                x=fa[x][i];
                y=fa[y][i];
            }
        x=fa[x][0],y=fa[y][0];
    }
    return x;
}
int get_dis(int x,int y){
    int z=lca(x,y);
    return dis[x]+dis[y]-2*dis[z];
}
pair<int,int>p[N];
int s[N],t[N],d[N];
int R;
signed main(){
    int n,Q;
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    n=5e5,Q=5e5;
    
    for(int i=0;i<n;i++){
        p[i].first=i;
        p[i].second=i+1;
    }
    for(int i=2;i<=n;i++){
        int x,y,w;
        x=i,y=rand()%(i-1)+1,w=rand();
        e[x].push_back({y,w});
        e[y].push_back({x,w});
    }
    dep[1]=1;
    dfs(1,0);
    sort(p,p+n);
    
    for(int i=0;i<=n;i++){
        int x=p[i].second;
        if(p[i].first==i){
            if(i==0){
                s[0]=t[0]=x;
                d[0]=0;
            }
            else {
                int dis1=get_dis(s[i-1],x);
                int dis2=get_dis(t[i-1],x);
                if(dis1>=dis2&&dis1>=d[i-1]){
                    s[i]=x;t[i]=s[i-1];
                }
                else if(dis2>=dis1&&dis2>=d[i-1]){
                    s[i]=x;t[i]=t[i-1];
                }
                else {
                    s[i]=s[i-1];t[i]=t[i-1];
                }
            }
            R=i;
        }
        else{
            break;
        }
    }
    while(Q--){
        int x=rand()%n+1,k=rand();
        int l=0,r=R,res=-1;
        while(l<=r){
            int mid=(l+r)/2;
            int dis=max(get_dis(x,s[mid]),get_dis(x,t[mid]));
            if(dis<=k){
                res=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
      //  cout<<res+1<<'\n';
    }
    
    


}