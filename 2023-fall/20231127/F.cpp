#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500005;
int dep[N],dis[N],dfn[N],eu[N*2+10][21],dind;
vector<pair<int,int>>e[N];

void dfs(int x,int pre){
    // fa[x][0]=pre;
    dfn[x]=++dind;eu[dfn[x]][0]=x;
    // for(int i=1;i<20;i++){
        // fa[x][i]=fa[fa[x][i-1]][i-1];
    // }
    for(auto [v,w]:e[x]){
        if(v==pre)continue;
        dis[v]=dis[x]+w;
        dep[v]=dep[x]+1;
        dfs(v,x);
        eu[++dind][0]=x;
    }
}

int cmp(int x, int y) {
    if(dep[x] < dep[y]) return x;
    return y;
}

int lca(int x, int y) {
    x = dfn[x], y = dfn[y];
    if(x > y) swap(x, y);
    int o = __lg(y-x+1);
    return cmp(eu[x][o], eu[y-(1<<o)+1][o]);
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
    cin>>n>>Q;
    
    for(int i=0;i<n;i++){
        cin>>p[i].first;
        p[i].second=i+1;
    }
    for(int i=1;i<n;i++){
        int x,y,w;
        cin>>x>>y>>w;
        e[x].push_back({y,w});
        e[y].push_back({x,w});
    }
    dep[1]=1;
    dfs(1,0);
    
    for(int j = 1; j <= 20; ++j) for(int i = 1; i <= dind; ++i) if(i + (1<<j) - 1<= dind) {
        eu[i][j]=cmp(eu[i][j-1], eu[i+(1<<(j-1))][j-1]);
    }

    // while(1) {
    //     cout << ">>> ";
    //     int x, y;
    //     cin >> x >> y;
    //     cout << x << " " << y << "!!!" << "\n";
    //     cout << lca(x, y) << "\n";
    // }

    // return 0;

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
                d[i]=max(d[i-1],max(dis1,dis2));
            }
            R=i;
        }
        else{
            break;
        }
    }

    // return 0;

    while(Q--){
        int x,k;
        cin>>x>>k;
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
        cout<<res+1<<'\n';
    }
    
    


}