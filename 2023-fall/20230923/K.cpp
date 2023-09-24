#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll exgcd(ll a, ll b, ll& x, ll& y) {
    if(!b)return x=1,y=0,a;
    int d=exgcd(b,a%b,x,y),t=x;
    return x=y,y=t-a/b*y,d;
}
ll mul(ll x, ll y, ll m) {
    __int128 r=x;
    r*=y;r%=m;
    return (ll)r;
}
ll MIN(ll x, ll y, ll z) {
    __int128 yy = y, zz = z, xx = x;
    yy = yy*yy+zz*zz;
    xx = min(xx, yy);
    return (ll)xx;
}
void solve() {
    ll a, b, n;
    cin >> a >> b >> n;
    ll g1,g2,g3;
    ll l1=n/(g1=gcd(a,n)), l2=n/(g2=gcd(b,n));
    ll l3=gcd(l1,l2);
    g3=g2*gcd(n/g2,l3);
    ll K1,K2,_;
    exgcd(a,n,K1,_);
    //exgcd(b,n,K2,_);
    K1=(K1%n+n)%n;
    // K2=(K2%n+n)%n;
    ll ans=(a%n)*(a%n)+(b%n)*(b%n);
    for(int i=0;i<=200;++i) {
        //i*gcd(a,n)
        ll k1=mul(K1,i,n);
        if(k1==0) k1=n;
        ll r=n-mul(k1,b,n);
        ll nm=(r/g3)*g3;
        if(nm<r) nm+=g3;
        nm-=r;
        if(nm==0&&mul(i,g1,n)==0) nm+=g3;
        ans=MIN(ans, mul(i,g1,n), nm);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) solve();
}
