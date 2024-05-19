#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
// void cmax(int &x, int y) {x  = std::max(x, y);}
const int mod = 998244353;
typedef long long ll;
int inc(int x, int y) {return x+y>=mod?x+y-mod:x+y;}
int dec(int x, int y) {return x-y<0?x-y+mod:x-y;}
int mul(int x, int y) {return (ll)x*y%mod;}
int qpow(int x, int y)
{
    int res = 1;
    for(;y;y>>=1) res=y&1?mul(res,x):res,x=mul(x,x);
    return res;
}
int inv(int x) {return qpow(x, mod-2);}
const int N=1<<20;
namespace NTT{
int re[N], w[2][N];
int getre(int n)
{
    int len=1, bit=0;
    while(len<n)len<<=1,++bit;
    for(int i=1;i<len;++i) re[i]=(re[i>>1]>>1)|((i&1)<<(bit-1));
    w[0][0]=w[1][0]=1;w[0][1]=qpow(3,(mod-1)/len),w[1][1]=inv(w[0][1]);
    for(int o=0;o<2;++o)for(int i=2;i<len;++i) w[o][i]=mul(w[o][i-1], w[o][1]);
    return len;
}
void NTT(int *a, int n, int o=0)
{
    for(int i=1; i<n; ++i) if(i<re[i])swap(a[i],a[re[i]]);
    int R;
    for(int k=1;k<n;k<<=1)
        for(int i=0,t=k<<1,st=n/t;i<n;i+=t)
            for(int j=0,nw=0;j<k;++j,nw+=st)
                R=mul(a[i+j+k],w[o][nw]), a[i+j+k]=dec(a[i+j],R),a[i+j]=inc(a[i+j],R);
    if(o){
        R=inv(n);
        for(int i=0;i<n;++i)a[i]=mul(a[i],R);
    }
}
int t0[N], t1[N], t2[N];
void multi(const int*a, const int*b, int* c, int n, int m)
{
    if(n+m<=32)
    {
        memset(c,0,sizeof(int)*(n+m+1));
        for(int i=0;i<=n;++i)for(int j=0;j<=m;++j)c[i+j]=inc(c[i+j],mul(a[i],b[j]));
        return;
    }
    int len=getre(n+m+1);
    memset(t0,0,sizeof(int)*(len)), memcpy(t0,a,sizeof(int)*(n+1));
    memset(t1,0,sizeof(int)*len),memcpy(t1,b,sizeof(int)*(m+1));
    NTT(t0,len);NTT(t1,len);
    for(int i=0;i<len;++i)t0[i]=mul(t0[i],t1[i]);
    NTT(t0,len,1);
    memcpy(c,t0,sizeof(int)*(n+m+1));
}
void inver(const int*a, int *b, int n)
{
    int len=1;
    while(len<=n) len<<=1;
    memset(t0, 0, sizeof(int)*len), memcpy(t0, a, sizeof(int)*(n+1));
    memset(t1, 0, sizeof(int)*(len<<1));
    memset(t2, 0, sizeof(int)*(len<<1));
    t2[0]=inv(t0[0]);
    for(int k=1; k<=len; k<<=1) {
        memcpy(t1, t0, sizeof(int)*k);
        getre(k<<1);
        NTT(t1,k<<1), NTT(t2, k<<1);
        for(int i=0;i<(k<<1);++i) t2[i]=mul(t2[i], dec(2, mul(t1[i], t2[i])));
        NTT(t2, k<<1, 1);
        for(int i=k;i<(k<<1);++i) t2[i]=0;
    }
    memcpy(b, t2, sizeof(int)*(n+1));
}
} // namespace NTT
struct poly:public vector<int>
{
    int time() const {return size()-1;};
    poly(int tim=0,int c=0){
        resize(tim+1);
        if(tim>=0) at(0)=c;
    }
    poly operator%(const int&n) const {
        poly r(*this);
        r.resize(n);
        return r;
    }
    poly operator*(const poly&p) const {
        poly r(time()+p.time());
        NTT::multi(&((*this)[0]), &p[0], &r[0], time(), p.time());
        return r;
    }
    poly operator+(const poly& p) const {
        int n = time(), m = p.time();
        poly r(*this);
        if(n<m) r.resize(m+1);
        for(int i=0;i<=m;++i) r[i]=inc(r[i], p[i]);
        return r;
    }
    poly operator-(const poly& p) const {
        int n = time(), m = p.time();
        poly r(*this);
        if(n<m) r.resize(m+1);
        for(int i=0;i<=m;++i) r[i]=dec(r[i], p[i]);
        return r;
    }
};
poly der(const poly& a){
    int n=a.time();
    poly r(n-1);
    for(int i=1;i<=n;++i) r[i-1]=mul(a[i], i);
    return r;
}
poly inv(const poly& a){
    poly r(a.time());
    NTT::inver(&a[0], &r[0], a.time());
    return r;
}
int _[N];
poly itr(const poly& a){
    int n=a.time();
    poly r(n+1);
    _[1]=1;
    for(int i=2;i<=n+1;++i) _[i]=mul(_[mod%i], mod-mod/i);
    for(int i=0;i<=n;++i) r[i+1]=mul(a[i], _[i+1]);
    return r;
}
poly ln(const poly& a) {
    return itr(der(a)*inv(a)%a.time());
}
poly Exp(const poly& a){
    poly r(0,1);
    int n=a.time(),k=1;
    while(r.time()<n)
        r=r%k,r=r*(a%k-ln(r)+poly(0,1))%k,k<<=1;
    return r%(n+1);
}
poly qpow(const poly& a, int k) {
    return Exp(ln(a)*k);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int i, N, M;
    cin >> N >> M;

    poly a(N*M);
    vector<int> fac((N*M)+1), inv((N*M)+1);
    for(inv[0]=fac[0]=fac[1]=inv[1]=1,i=2;i<=(N*M);++i)
        fac[i]=mul(fac[i-1], i), inv[i]=mul(inv[mod%i],mod-mod/i);
    for(i=2;i<=(N*M);++i) inv[i]=mul(inv[i-1],i);
    for(i=0;i<=M;++i) a[i]=inv[M-i];
    // for(i=0;i<=N*M;++i) cerr << a[i] << " "; cerr << "\n";
    // a=qpow(a, N);
    a=qpow(a, N);
    int ans=0, fMN=qpow(fac[M], N);
    // for(i=0;i<=N*M;++i) cerr << a[i] << " "; cerr << "\n";
    for(int i=0;i<=N*M;++i)
    {
        int v=mul(fac[N*M-i], mul(a[i], fMN));
        if(i&1) ans=dec(ans, v);
        else ans=inc(ans, v);
        // cout << ans << "\n";
        // cout<<ans<<"\n";
    }
    cout << ans << "\n";

    return 0;
}