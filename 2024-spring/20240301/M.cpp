#include<bits/stdc++.h>
using namespace std;
const int N=5005,mo=998244353;
vector<int>e[N];
int ord[N],f[N][2],vis[N];

void dfs(int x,int fa,int lim){
    if(vis[x])return;
    vis[x]=1;
    if(ord[x]>lim){
        f[x][1]=1;
        f[x][0]=0;
      //  cout<<"info "<<x<<" "<<f[x][0]<<" "<<f[x][1]<<endl;
        return;
    }
    else{
        f[x][1]=0;
        f[x][0]=1;
    }
    for(auto v:e[x]){
        if(v==fa)continue;
        dfs(v,x,lim);
        f[x][1]=(1ll*f[x][0]*f[v][1]%mo+1ll*f[x][1]*f[v][0]%mo+1ll*f[x][1]*f[v][1]%mo*2%mo)%mo;
        f[x][0]=(1ll*f[x][0]*f[v][1]%mo*2%mo+1ll*f[x][0]*f[v][0]%mo)%mo;
     //   cout<<"info "<<x<<" "<<v<<"  "<<f[x][0]<<" "<<f[x][1]<<endl;
    }
     //   cout<<"info "<<x<<" "<<f[x][0]<<" "<<f[x][1]<<endl;
    
}
void solve(int lim){

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    for(int i=1;i<=n;i++)ord[i]=n;
    for(int i=1;i<n;i++){
        int x;
        cin>>x;
        ord[x]=i;
    }
   // dfs(1,0,1);
    
    
    for(int i=1;i<=n-1;i++){
        memset(f,0,sizeof(f));
        memset(vis,0,sizeof(vis));
        int ans=1;
        for(int j=1;j<=n;j++){
            if(!vis[j]){
            //    cout<<"round "<<i<<" root "<<j<<endl;
                dfs(j,0,i);
                ans=1ll*ans*f[j][1]%mo;
            //    cout<<"ans "<<ans<<endl;
            }
        }
        cout<<ans<<endl;
    }
    
}