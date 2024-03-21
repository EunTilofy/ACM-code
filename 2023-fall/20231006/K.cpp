#include<bits/stdc++.h>
const int N=200001;
#define int long long
using namespace std;
int fa[N],c[N][2],st[N],val[N],X[N];
bool rev[N];
#define get(x) (c[fa[x]][1]==x)
bool nrt(int x){
    return c[fa[x]][0]==x||c[fa[x]][1]==x;
}
void Rev(int x){
    rev[x]^=1;swap(c[x][0],c[x][1]);
}
void down(int x){
    if(x&&rev[x])Rev(c[x][0]),Rev(c[x][1]),rev[x]=0;
}
void rotate(int x){
    int y=fa[x],z=fa[y],l=get(x),r=l^1;
    if(nrt(y))c[z][get(y)]=x;fa[x]=z;
    c[y][l]=c[x][r];
    fa[c[x][r]]=y;
    c[x][r]=y;
    fa[y]=x;
}
void splay(int x){
    static int top,q[N];
    q[top=1]=x;
    for(int i=x;nrt(i);i=fa[i])q[++top]=fa[i];for(;top;--top)down(q[top]);
    for(;nrt(x);rotate(x))if(nrt(fa[x]))rotate(get(fa[x])^get(x)?x:fa[x]);

}
void access(int x){
    for(int i=0;x;x=fa[i=x])splay(x),c[x][1]=i;
}

void mkrt(int x){
    access(x);
    splay(x);
    Rev(x);
}


int fdrt(int x){
    access(x);
    splay(x);
    for(;c[x][0];down(c[x][0]),x=c[x][0]);
    splay(x);
    return x;
}
void link(int x,int y){
    mkrt(x);
    if(fdrt(y)!=x){
        fa[x]=y;
    }
    else{
        assert(0);
    }
}
void split(int x,int y){
    mkrt(x);
    access(y);
    splay(y);
}
void cut(int x,int y){
    split(x,y);
    if(c[y][0]==x&&!c[x][1])c[y][0]=fa[x]=0;
}
bool check(int x,int y){
    mkrt(x);
  //  cout<<"check "<< x<<' '<<y<<endl;
    return fdrt(y)==x;
}
using ll = long long;
struct Bit{
    int n;
    ll a[N],b[N];
    void mdf(int l,int r,int dt){
        int i;
        ++r;
        int j=dt*l;
        a[l]+=dt;b[l]+=j;
        while((l+=l&-l)<=n){
            a[l]+=dt;
            b[l]+=j;
        }
        if(r<=n){
            j=dt*r;
            a[r]-=dt;
            b[r]-=j;
            while((r+=r&-r)<=n){
                a[r]-=dt;
                b[r]-=j;
            }
        }
    }
    ll presum(int x){
        ll r=a[x],rr=b[x];
        int y=x;
        while(x^=x&(-x)){
            r+=a[x];
            rr+=b[x];
        }
        return r*(y+1)-rr;
    }
    int sum(int l,int r){
        return presum(r)-presum(l-1);
    }
}bit;
signed main(){
    int n,m;
    scanf("%lld%lld",&n,&m);
    bit.n=m;
    vector<pair<int,int>>p(m+1);
    vector<int>lim(m+1);
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%lld%lld",&x,&y);
        p[i]={x,y};
    }
    int cur=1;
    for(int i=1;i<=m;i++){
    //    cout<<i<<endl;
        while(check(p[i].first,p[i].second)){
            cut(p[cur].first,p[cur].second);
            ++cur;
        }
        lim[i]=cur;
        link(p[i].first,p[i].second);
    }
    
    int q;
    scanf("%lld",&q);
    vector<int>ans(q+1);
    vector<vector<pair<int,int>>>que(m+1);
    for(int i=1;i<=q;i++){
        int x,y;
        scanf("%lld%lld",&x,&y);
        que[y].push_back({x,i});
    }
    for(int i=1;i<=m;i++){
        bit.mdf(lim[i],i,1);
        for(auto [v,id]:que[i]){
            ans[id]=bit.sum(v,i);
        }
    }
    for(int i=1;i<=q;i++){
        printf("%lld\n",ans[i]);
    }
}