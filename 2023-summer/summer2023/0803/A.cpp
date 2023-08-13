#include<bits/stdc++.h>
using namespace std;

int P, q;
typedef unsigned int ui;
typedef unsigned long long ll;
ui ksm(ui x, ui y, ui p) {
    ui r=1;
    while(y) {
        if(y&1) r=(ll)r*x%p;
        x=(ll)x*x%p; y>>=1;
    }
    return r;
}
vector<ui> getw(ui n){
    vector<ui> w;
    for(ui i=2;i*i<=n;++i)if(n%i==0){
        w.push_back(i);
        n/=i;
        for(ui j=n/i;n==i*j;j=n/i) n/=i;
    }
    if(n>1) w.push_back(n);
    return w;
}
int getrt(ui n){
    if(n<=2) return n-1;
    auto w=getw(n);
    ui ph=n;
    for(ui x:w) ph=ph/x*(x-1);
    w=getw(ph);
    for(ui &x:w) x=ph/x;
    for(ui i=2;i<n;++i)if(gcd(i,n)==1){
        for(ui x:w)if(ksm(i,x,n)==1)goto no;
        return i;
        no:;
    }
    return -1;
}
int exgc(int a, int b, int &x, int &y) {
    if(!b) return x=1,y=0,a;
    int d=exgc(b,a%b,x,y),t=x;
    return x=y,y=t-a/b*y,d;
}
int exgcd(int a, int b){
    // if(a==1) return 1;
    // return (1-(ll)b*exgcd(b%a,a))/a;
    int x,y;
    exgc(a,b,x,y);
    return x;
}
// int bsgs(ui a, ui b, ui p){
//     s.clear();
//     a%=p;
//     b%=p;
//     if(!a) return 1-min((int)b,2);
//     ui i,j,k,x,y;
//     x=sqrt(p)+2;
//     for(i=0,j=1;i<x;i++)
// }
// int exbsgs(ui a, ui b, ui p) {
//     a%=p;b%=p;
//     ui i,j,k,x,y=__lg(p),cnt=0;
//     for(i=0,j=1%p;i<=y;++i,j=(ll)j*a%p)if(j==b)return i;
//     y=1;
//     while(1){
//         if((x=gcd(a,p))==1) break;
//         if(b%x) return -1;
//         ++cnt;
//         p/=x;b/=x;
//         y=(ll)y*(a/x)%p;
//     }
//     a%=p;
//     b=(ll)b*(p+exgcd(y,p))%p;
//     int r=bsgs(a, b, p);
//     return r==-1?-1:r+cnt;
// }
bool in[100000000];
int main() {
    freopen("alot.in", "r", stdin);
    freopen("alot.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> P >> q;
    if(P == 2) {
        while(q--) {
            int x, y;
            cin >> x >> y;
            x %= P, y %= P;
            if(x==0 && y == 1) cout << 0 << "\n";
            if(x==1 && y == 1) cout << 0 << "\n";
            if(x==0 && y == 0) cout << 1 << "\n";
            if(x==1 && y == 0) cout << -1 << "\n";
        }
        return 0;
    }
    else {
        // unordered_set<int> S;
        vector<pair<int,int>> Q;
        for(int i = 1; i <= q; ++i) {
            int x, y;
            cin >> x >> y;
            x%=P;y%=P;
            Q.push_back({x, y});
            in[x] = in[y] = 1;
            // S.insert(x);
            // S.insert(y);
        } 
        int g = getrt(P);
        // cerr << g << "\n";
        int nw = 1, step = 0;
        unordered_map<int, int> mp;
        for(;;) {
            if(in[nw]) mp[nw] = step;
            ++step;
            nw = (nw * g) % P;
            if(nw == 1) break;
        }
        for(auto &[x,y] : Q) {
            if(x == 1) {
                if(y == 1) cout << "0\n";
                else cout << "-1\n";
            } else if(x == 0) {
                if(y == 0) cout << 1 << "\n";
                else if(y == 1) cout << "0\n";
                else cout << "-1" << "\n";
            } else if(y == 1) {
                cout << "0\n";
            } else if(y == 0) {
                if(x == 0) cout << "1\n";
                else cout << "-1\n";
            } else {
                x = mp[x];
                y = mp[y];
                // cout << x << " " << y << "\n";
                if(y % gcd(x, P-1) != 0) cout << "-1\n";
                else {
                    int gc=gcd(x,P-1);
                    y/=gc;
                    // cerr << x/gc << " " << (P-1)/gc << endl;
                    // cerr << exgcd(x/gc, (P-1)/gc) << endl;
                    int ans=1ll*y*exgcd(x/gc,(P-1)/gc)%((P-1)/gc);
                    // int ans = y/gcd(x, P-1)* 1ll * exgcd(x,P-1) % (P-1);
                    // ans = (ans + P - 1) % (P - 1);
                    ans=(ans+(P-1)/gc)%((P-1)/gc);
                    cout << ans << "\n";
                }
            }
        }
    }
    return 0;
}