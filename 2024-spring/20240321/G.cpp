#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
const int N=1e6+5;
vector<int>e[N];
vector<int>g[N];
int dis[N],vis[N];
#define ll long long
ll a[N],b[N];
ll f[N],f2[N];
void bfs(){
    queue<int>q;
    q.push(1);
    dis[1]=0;
    vis[1]=1;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(auto v:g[x]){
            if(!vis[v]){
                dis[v]=dis[x]+1;
                q.push(v);
                vis[v]=1;
            }
        }
    }
}
int id[N];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    vector<pair<int,int>>l;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
        l.push_back({x,y});
    }
    bfs();
    pair<ll,int>ans={-1e18,0},rans={-1e18,0};
    for(int i=1;i<=n;i++){
        pair<ll,int>cur={a[i]-1ll*(dis[i]+1)*b[i],i};
        if(cur>=ans){
            rans=ans;
            ans=cur;
        }
        else if(cur>rans)rans=cur;
    }
  //  cout<<ans.first<<" "<<ans.second<<" "<<rans.first<<" "<<rans.second<<endl;
    for(auto [x,y]:l){
        if(dis[x]>dis[y])swap(x,y);
        if(dis[x]+1==dis[y]){
            e[y].push_back(x);
            e[y+n].push_back(x+n);
        }
        else if(dis[x]==dis[y]){
            e[y+n].push_back(x);
            e[x+n].push_back(y);
        }
    }
    for(int i=1;i<=n;i++){
        f[i]=a[i]-1ll*(dis[i]-1)*b[i];
        f[i+n]=a[i]-1ll*dis[i]*b[i];
    }
    for(int i=1;i<=2*n;i++)id[i]=i;
    sort(id+1,id+1+2*n,[&](int a,int b){
        int c=a<=n?a:a-n;
        int d=b<=n?b:b-n;
        if(dis[c]!=dis[d])return dis[c]>dis[d];
        else return a>b;
    });
    for(int i=1;i<=2*n;i++)f2[i]=-1e18;
    for(int i=1;i<=2*n;i++){
        int x=id[i];
        for(auto v:e[x]){
            f2[v]=max(f2[v],f[x]);
            f2[v]=max(f2[v],f2[x]);
        }
    }
    sort(g[1].begin(),g[1].end());
    for(auto x:g[1]){
       // cout<<x<<" "<<f[x]<<" "<<f2[x]<<endl;
        f2[x]=max(f2[x],a[1]-b[1]);
        if(ans.second!=x)f2[x]=max(f2[x],ans.first);
        else f2[x]=max(f2[x],rans.first);
        cout<<f2[x]<<" ";
    }
    cout<<endl;
}