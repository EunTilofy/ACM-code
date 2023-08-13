#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
#define int long long
const int mo=998244353;
int vs[N], pr[N], sz[N], nm[N];

void init() {
  for(int i = 2; i < N; ++i) {
    if(!vs[i]) pr[++pr[0]] = i, vs[i] = i, nm[i] = pr[0];
    for(int j = 1; j <= pr[0] && i * pr[j] < N; ++j) {
      vs[i * pr[j]] = pr[j];
      if(i % pr[j] == 0) break;
    }
  }
}

int qpow(int a,int b){
  int res=1;
  for(;b;b>>=1,a=a*a%mo){
    if(b&1){
      res=res*a%mo;
    }
  }
  return res;
}
int vis[N],c[N],a[N];
void dfs(int x,int &cnt){
  vis[x]=1;
  cnt++;
  if(!vis[a[x]])
  dfs(a[x],cnt);
}
mt19937 rnd(0);
signed main(){
  init();
  int n;
  scanf("%lld",&n);
  for(int i=1;i<=n;i++){
    a[i]=i;
  }
  for(int i=1;i<=n;i++){
    scanf("%lld",&a[i]);
  }
  /*
  shuffle(a+1,a+1+n,rnd);
  vector<int>s,t;
  s.push_back(0);
  t.push_back(0);
  for(int i=1;i<=n;i++){
    s.push_back(a[i]);
    t.push_back(a[i]);
  }
  cout<<endl;
  int cntt=0;
  map<vector<int>,int>mp;
  while(1){
    if(mp[s]==1)break;
    cntt++;
    mp[s]=1;
    for(int i=1;i<=n;i++){
      t[i]=s[s[i]];
    }
    s=t;
  }
  cout<<cntt<<endl;
  */
  int cnt=0;
  for(int i=1;i<=n;i++){
    if(!vis[i])dfs(i,c[++cnt]);
  }
  int ans=0,gc=-1,mul=1;
  for(int i=1;i<=cnt;i++){
    int res=0;
    while(c[i]%2==0){
      c[i]/=2;
      res++;
    }
    ans=max(ans,res);
 //   cout<<"yes "<<c[i]<<endl;
    if(c[i]!=1){
  //     if(gc==-1)gc=mul=c[i]-1;
  //     else {gc=gcd(gc,c[i]-1);
	// mul=mul*(c[i]-1)%mo;
	// mul=mul*qpow(gc,mo-2)%mo;
  //     }
  //
      int x=1;
      int k=2;
      while(k!=1){
	k=k*2%(c[i]);
	x++;
      }
   //    cerr << x << " ";
      for(; vs[x]; ) {
        int pos = 0, tmp = vs[x];
        for(; vs[x] == tmp; x /= vs[x]) ++pos;
        // cerr << tmp << " " << pos << "\n";
        sz[nm[tmp]] = max(sz[nm[tmp]], pos);
      }
    //  cout<<gc<<' '<<mul<<endl;
    }
  }
  for(int i = 1; i <= pr[0]; ++i) mul = 1ll * mul * qpow(pr[i], sz[i]) % mo;
  ans = (ans + mul) % mo;
  printf("%lld\n",ans);
}
