#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int sz[N],dep[N],dfn[N],son[N],fa[N],top[N];
int n, a[N];
vector<int> e[N];
int indec;
int dfnr[N];
void dfs(int x,int f){
  dfn[x]=++indec;
  sz[x]=1;
  dep[x]=dep[f]+1;
  for(auto v:e[x]){
    dfs(v,x);
    sz[x]+=sz[v];
    if(sz[v]>sz[son[x]])son[x]=v;
  }
  dfnr[x]=indec;
}
// int indec;
// int dfnr[N];
// void dfs2(int x,int tp){
//   top[x]=tp;
//   dfn[x]=++indec;
//   if(son[x]){
//     dfs2(son[x],tp);
//   }
//   for(auto v:e[x]){
//     if(v!=son[x]){
//       dfs2(v,v);
//     }
//   }
//   dfnr[x]=indec;
// }

long long tag[18][N];
void C(int step, int x, int v) {
  for(;x<=n;x+=(x&(-x))) tag[step][x]+=v;
}
int G(int step, int x) {
  long long res = 0;
  for(;x;x-=(x&(-x))) res+=tag[step][x];
  return res; 
}
void modify(int step,int x,int l,int r,int L,int R,int v) {
  C(step, L, v);
  if(R<n) C(step, R+1, -v);
}
long long query(int step,int x,int l,int r,int pos){
  return G(step, pos);
}
// long long tag[18][N<<2];
// void modify(int step,int x,int l,int r,int L,int R,int v){
//   if(l==L&&r==R){
//     tag[step][x]+=v;
//     return;
//   }
//   else{
//     int mid=(l+r)/2;
//     if(R<=mid){
//       modify(step,x<<1,l,mid,L,R,v);
//     }
//     else if(L>mid){
//       modify(step,x<<1|1,mid+1,r,L,R,v);
//     } else {
//       modify(step,x<<1,l,mid,L,mid,v);
//       modify(step,x<<1|1,mid+1,r,mid+1,R,v);
//     }
//   }
// }
// long long query(int step,int x,int l,int r,int pos){
//   if(l==r){return tag[step][x];}
//   else {
//     int mid=(l+r)/2;
//     if(pos<=mid) return tag[step][x]+query(step,x<<1,l,mid,pos);
//     else return tag[step][x]+query(step,x<<1|1,mid+1,r,pos);
//   }
// }
int rbfn[N],bfn[N];
int sonl[N],sonr[N];
void bfs(){
  deque<pair<int,int>>q;
  q.push_back({1,1});
  int inded=0;
  while(!q.empty()){
    auto [x,d]=q.front();
	  bfn[x]=++inded;
	  rbfn[bfn[x]] = x;
    q.pop_front();
	  for(auto v:e[x]){
	    q.push_back({v,d+1});
	  }
  }
}
void DFS(int x){
  sonl[bfn[x]]=n+1;
  sonr[bfn[x]]=-1;
  for(auto y:e[x]){
    DFS(y);
    sonl[bfn[x]]=min(sonl[bfn[x]],bfn[y]);
    sonr[bfn[x]]=max(sonr[bfn[x]],bfn[y]);
  }
}
void add(int l,int r,int num,int k){
  if(l<1||l>n||r<1||r>n) return ;
  for(int step=0;num;num/=k,++step){
    modify(step,1,1,n,l,r,num);
  }
}


// 2nd segtree
int t[N<<2],tg[N<<2];
void pushdown(int x,int l, int r){
  int mid=(r+l)/2;
  t[x<<1]+=tg[x]*(mid-l+1);t[x<<1|1]+=tg[x]*(r-mid);
  tg[x<<1]+=tg[x];tg[x<<1|1]+=tg[x];
  tg[x]=0;
}
void MODIFY(int x,int l,int r,int L,int R,int v){
  if(l==L&&r==R){
    t[x]+=v*(r-l+1);
    tg[x]+=v;
    return;
  }
  else{
    pushdown(x,l,r);
    int mid=(l+r)/2;
    if(R<=mid){
      MODIFY(x<<1,l,mid,L,R,v);
    }
    else if(L>mid){
      MODIFY(x<<1|1,mid+1,r,L,R,v);
    } else {
      MODIFY(x<<1,l,mid,L,mid,v);
      MODIFY(x<<1|1,mid+1,r,mid+1,R,v);
    }
    t[x]=t[x<<1]+t[x<<1|1];
  }
}
long long QUERY(int x,int l,int r,int L, int R){
  if(l==L&&r==R){return t[x];}
  else {
    pushdown(x,l,r);
    int mid=(l+r)/2;
    if(R<=mid) return QUERY(x<<1,l,mid,L,R);
    else if(L>mid) return QUERY(x<<1|1,mid+1,r,L,R);
    return QUERY(x<<1,l,mid,L,mid)+QUERY(x<<1|1,mid+1,r,mid+1,R);
  }
}
signed main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  // 1 X Y K
  // 2 X
  cin >> n;
  int q;
  cin >> q;
  for(int i = 2; i <= n; ++i) {
    cin >> fa[i];
    e[fa[i]].push_back(i);
  }
  dfs(1, 0);
  // dfs2(1, 1);
  bfs();
  DFS(1);
  for(int i=2;i<=n;++i) {
    sonr[i]=max(sonr[i],sonr[i-1]);
  }
  for(int i=n-1;i;--i) {
    sonl[i]=min(sonl[i],sonl[i+1]);
  }
  // for(int i=1;i<=n;++i)cerr<<i<<" "<<bfn[i]<<" "<<sonl[i]<<" "<<sonr[i]<<endl;

  for(int i = 1; i <= q; ++i) {
    int opt;
    cin >> opt;
    if(opt == 1) {
      int x, y, k;
      cin >> x >> y >> k;
      if(k==1) {
        MODIFY(1,1,n,dfn[x],dfnr[x],y);
      } else {
        int l = bfn[x], r = bfn[x];
        l = sonl[l];
        r = sonr[r];
        long long all=0;
        all=y;
        y/=k;
        while(y) {
          add(l,r,y,k);
          all+=(r-l+1)*1ll*y;
          y/=k;
          int now = dep[rbfn[l]];
          l=sonl[l];
          r=sonr[r];
          if(l>r)break;
          if(l<1||r<1||l>n||r>n) break;
          if(dep[rbfn[l]]!=dep[rbfn[r]]) break;
          if(dep[rbfn[l]]!=now+1)break;
        }
        MODIFY(1,1,n,dfn[x],dfn[x],all);
      }
    } else {
      int x;
      cin >> x;
      long long ans=QUERY(1,1,n,dfn[x],dfnr[x]);
      int l=bfn[x],r=bfn[x];
      for(int i=0;i<18;++i){
        ans+=query(i,1,1,n,bfn[x])*(r-l+1);
        int now = dep[rbfn[l]];
        l=sonl[l];
        r=sonr[r];
        if(l>r)break;
        if(l<1||r<1||l>n||r>n) break;
        if(dep[rbfn[l]]!=dep[rbfn[r]]) break;
        if(dep[rbfn[l]]!=now+1)break;
      }
      cout<<ans<<"\n";
    }
  }
}
