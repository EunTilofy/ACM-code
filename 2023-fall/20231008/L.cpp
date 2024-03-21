#include<bits/stdc++.h>
using namespace std;
const int N=2000001;
string s[N];
int n,m;
int in[N],out[N],fa[N];
int find(int x){
    if(fa[x]==x)return x;
    else return fa[x]=find(fa[x]);
}
void merge(int x,int y){
    x=find(x);y=find(y);
    fa[x]=y;
}
using ll = long long;
const ll mo=1e9+9,B=173;
int indec=0;
 
unordered_map<ll,int>vis;
vector<int>f[N];
int bs[N];
int id(int i,int l,int r){
    int res=(f[i][r]-1ll*(l?f[i][l-1]:0)*bs[r-l+1]%mo+mo)%mo;
    if(l>r)res=0;
   // cout<<i<<" "<<l<<" "<<r<<" "<<res<<endl;
    if(!vis[res])vis[res]=++indec;
    return vis[res];
}
vector<pair<int,int>>e[N],g[N];
vector<int> path;
void dfs(int u) {
    while(e[u].size()) {
        auto [v, id] = e[u].back();
        e[u].pop_back();
        dfs(v);
        path.push_back(id);
        // cerr << u << " " << id << "\n";
    }
}
void make_path() {
    path.clear();
    dfs(1);
    reverse(path.begin(), path.end());
}
void link(int x,int y,int i){
    in[y]++;
    out[x]++;
    e[x].push_back({y,i});
    merge(x,y);
}
bool check(int len){
  //  cout<<"check "<<len<<endl;
    vis=unordered_map<ll,int>();
    indec=0;
    for(int i=1;i<=2*n;i++){
        in[i]=out[i]=0;fa[i]=i;
        e[i].clear();
    }
    for(int i=1;i<=n;i++){
        int x=id(i,0,len-1);
        int y=id(i,len,m-1);
        cout<<"link "<<x<<" "<<y<<" "<<i<<endl;
        link(x,y,i);
    }
    for(int i=n+1;i<=2*n;i++){
        int x=id(i,0,m-len-1);
        int y=id(i,m-len,m-1);
        cout<<"link "<<x<<" "<<y<<" "<<i<<endl;
        link(x,y,i);
    }  
    for(int i=1;i<=indec;i++){
        fa[i]=find(i);
     //   cout<<i<<" "<<fa[i]<<" "<<fa[1]<<" "<<in[i]<<' '<<out[i]<<endl;
        if(fa[i]!=fa[1])return 0;
        if(in[i]!=out[i])return 0;
    }
    vector<int>s1,s2;
    make_path();
    for(auto v:path)cout<<v<<" ";cout << "\n";
 //  assert(path.size()==2*n);
    for(int i=0;i<2*n;i++){
        if(i&1)s1.push_back(path[i]);
        else s2.push_back(path[i]);
    }
    for(auto v:s1){if(v>n){swap(s1,s2);break;}}
    for(auto v:s1)if(v>n)return 0;
    for(auto v:s2)if(v<=n)return 0;
    for(auto v:s1){printf("%d ",v);};puts("");
    for(auto v:s2){printf("%d ",v-n);}puts("");
  //  cout<<"ok "<<len<<endl;
    return 1;

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    bs[0]=1;for(int i=1;i<N;i++)bs[i]=1ll*bs[i-1]*B%mo;
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=2*n;i++){
            cin>>s[i];
            f[i].resize(m+1);
            f[i][0]=s[i][0]-'a'+1;
            for(int j=0;j<m-1;j++)f[i][j+1]=(1ll*f[i][j]*B%mo+(s[i][j+1]-'a'+1))%mo;
        }
        int fl=0;
        for(int len=1;len<=m;len++){
            if(check(len)){fl=1;break;}
        }
        if(!fl)puts("-1");
    }
}