#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353
#define g 3
#define invg 332748118
inline ll fpow(ll x, int m) {
    ll res=1;
    for(;m;m>>=1,x=x*x%mod) (m&1)?res=res*x%mod:0;
    return res;
}
#define MN 2097152
int N,di,pos[MN];
ll a[MN],b[MN],invN;
void NTT(ll *a,int type) {
	int i,j,p,k;
    for(i=0;i<N;++i)if(i<pos[i]) swap(a[i],a[pos[i]]);
    for(i=1;i<N;i<<=1) {
        ll wn=fpow(type>0?g:invg,(mod-1)/(i<<1));
        for(p=i<<1,j=0;j<N;j+=p) {
            ll w=1;
            for(k=0;k<i;++k,w=w*wn%mod) {
                ll X=a[j+k],Y=w*a[j+i+k]%mod;
                a[j+k]=(X+Y)%mod;a[j+i+k]=(X-Y+mod)%mod;
            }
        }
    }
}
int main() {
    string s;
    cin >> s;
    int n=s.size();
    for(int i = 0; i < n; ++i) {
        if(s[i] == 'A') a[n-i]=1;
        else b[i+1]=1;
    }
	for(N = 1; N <= n + n; N <<= 1) ++di;
    for(int i = 0; i < N; ++i) pos[i]=(pos[i>>1]>>1)|((i&1)<<(di-1));
    NTT(a, 1); NTT(b, 1);
    for(int i = 0; i < N; ++i) a[i] = a[i] * b[i] % mod;
    NTT(a, -1);
    invN = fpow(N, mod - 2);
    for(int i = 0; i < N; ++i) a[i]=a[i]*invN%mod;

    // for(int i = 1; i <= n; ++i) {
    //     cout << a[i] << " " << b[i] << "\n";
    // }

    for(int i = 1; i < n; ++i) cout << a[n-i+1] << "\n";
    return 0;
}