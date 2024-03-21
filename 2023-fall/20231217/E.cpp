#include<bits/stdc++.h>
#define ljc 998244353
//#define ljc 1000000007
#define int long long
#define ll long long
#define gc getchar
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
inline ll read(){
    ll x=0,f=1;char ch=gc();
    while (!isdigit(ch)){if (ch=='-') f=-1;ch=gc();}
    while (isdigit(ch)){x=x*10ll+ch-'0';ch=gc();}
    return x*f;
}
inline void file(){
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
}
inline ll fast_pow(ll a,ll b,ll p){
    ll t=1;a%=p;
    while (b){
        if (b&1ll) t=t*a%p;
        b>>=1ll;a=a*a%p;
    }
    return t;
}
//struct edge{
//	int to,nxt,dis;
//}g[2010101];
//int tot,head[1010101];
//inline void made(int from,int to,int dis){
//	g[++tot].to=to;g[tot].nxt=head[from];head[from]=tot;g[tot].dis=dis;
//}
//ll inv[1000002],fac[1000002],_inv[1000002];
//inline ll getC(ll n,ll m){
//	if (n<m||n<0||m<0) return 0;
//	return fac[n]*_inv[m]%ljc*_inv[n-m]%ljc;
//}
//inline void init(){
//	fac[0]=inv[0]=inv[1]=_inv[0]=1;
//	for (ll i=1;i<=1000000;i++) fac[i]=fac[i-1]*i%ljc;
//	for (ll i=2;i<=1000000;i++) inv[i]=(ljc-(ljc/i)*inv[ljc%i]%ljc)%ljc;
//	for (ll i=1;i<=1000000;i++) _inv[i]=_inv[i-1]*inv[i]%ljc;
//}
int n,m,ans[1010101],op[1010101],a[1010101],c[1010101],b[1101010]; 
// op 0 无 
// op 1 无12
// op 2 球1 
struct node{
    int b,c;
}s[1010101];
int sum[1010101];
int cmp(node a,node b){
    return min(a.b,a.c+1)>min(b.b,b.c+1);
}
int id[1010101];
signed main(){
    int cnt1=0;
    int n=read();
    for (int i=1;i<=n;i++) a[i]=read();
    for (int i=1;i<=n;i++) b[i]=read();
    for	(int i=1;i<=n;i++) c[i]=read();
    int can=0,news=0,all=0;
    for (int i=1;i<=n;i++) {
        all+=a[i];
        if (a[i]){
            news+=c[i];
            a[i]+=c[i];
            c[i]=0;
            if (b[i]){
                op[i]=2;
                can+=min(b[i],a[i]);
            }
        }else{
            if (b[i]&&c[i]) op[i]=1,s[++cnt1]=(node){b[i],c[i]},id[i]=cnt1;
        }
    }
    for (int i=1;i<=cnt1;i++) sum[i]=sum[i-1]+min(s[i].b,s[i].c+1);
    int ANS0=0;
    if (can) ANS0=sum[cnt1]-cnt1+can;
    
    for (int i=1;i<=n;i++){
        if (op[i]==0){
            printf("%lld ",ANS0?(a[i]+c[i]+ANS0):(a[i]?a[i]+c[i]:a[i]));
        }else if (op[i]==1){
            int now=sum[cnt1]-cnt1-(min(s[id[i]].b,s[id[i]].c+1)-1)+can;
            if (can==0) now=0;
            else news+=c[i];
            printf("%lld ",now?(now+a[i]+c[i]):0ll);
        }else{
            printf("%lld ",ANS0+max(0ll,a[i]-b[i]));
        }
    }
    puts("");
    vector<int> vec;
    for (int i=1;i<=n;i++){
        if (op[i]==0) vec.pb(c[i]);
    }
    sort(vec.begin(), vec.end());
    for (int j=vec.size()-1;j>=0;j--){
        if (ANS0){
            ANS0--;
            news+=vec[j];
        }		
    }
    cout<<news+all;
    return 0;
}
/*



3
0 0 0
2 2 2
2 2 2

*/