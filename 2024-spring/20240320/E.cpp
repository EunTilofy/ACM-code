#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
const int N = 1e5 + 10;
struct node {
    int cnt;
    vector<ll> val;
} a[N];
int ys[N];

using std::cin, std::cout, std::cerr;

const int MOD = 1e9 + 7;
// const int MN = 1 << 19 | 5;
// int Add(const int &x, const int &y) {
//     return (x + y) % MOD;
// }
int Mul(const int &x, const int &y, const int &p) {
    return 1ll * x * y % p;
}
int fpow(int x, int m, int p) {
    int ans = 1;
    for(; m; m >>= 1) {
        if(m & 1) ans = Mul(ans, x, p);
        x = Mul(x, x, p);
    }
    return ans;
}
namespace NTT {
    const int MN = 1 << 20 | 5;
    int input[MN]; // a
    int output[MN]; // b
    const int mod[3] = {469762049, 998244353, 1004535809}, g = 3;
    int pos[MN], len, di;
    int F[MN], G[MN];
    struct Polynomial {
        int P, invg, r[N];
        void NTT(int *a, int n, int type) {
            int i, j, p, k, w, wn, X, Y;
            for(int i = 0; i < n; ++i) if(i < pos[i]) swap(a[i], a[pos[i]]);
            for(int i = 1; i < n; i <<= 1) {
                wn = fpow(type > 0 ? g : invg, (P - 1) / (i << 1), P);
                for(p = i << 1, j = 0; j < n; j += p) 
                for(w = 1, k = 0; k < i; ++k, w = Mul(w, wn, P)) {
                    X = a[j + k]; Y = Mul(w, a[j + k + i], P);
                    a[j + k] = (X + Y) % P;
                    a[j + k + i] = (X - Y + P) % P;
                }
            }
            int invn = fpow(n, P - 2, P);
            if(type == -1) for(i = 0; i < n; ++i) a[i] = Mul(a[i], invn, P);
        }
        void combine(int *A, int *B, int n) {
            memcpy(F, A, sizeof(int[n]));
            memcpy(G, B, sizeof(int[n]));
            NTT(F, n, 1); NTT(G, n, 1);
            for(int i = 0; i < n; ++i) r[i] = Mul(F[i], G[i], P);
            NTT(r, n, -1);
        }
    } poly[3];
    void init(int n) {
        for(len = 1, di = 0; len < n; ) len <<= 1, di++;
        for(int i = 0; i < len; ++i) pos[i] = (pos[i >> 1] >> 1) | ((i & 1)<<(di - 1));
        for(int i = 0; i < 3; ++i) {
            poly[i].P = mod[i];
            poly[i].invg = fpow(g, mod[i] - 2, mod[i]);
        }
    }

    int a[MN], b[MN];
    inline ll mul(ll a, ll b, ll p) {
        static const long double eps = 1e-8;
        a = (a%p+p)%p; b = (b%p+p)%p;
        return ((a*b-(ll)((long double)a/p*b+eps)*p)%p+p)%p;
    }
    void multi(vector<int> &aa, vector<int> &bb, vector<int> &cc, int n, int m, int ret) {
        // ++n, ++m;
        for(int i = 0; i < n; ++i) a[i] = aa[i];
        for(int i = 0; i < m; ++i) b[i] = bb[i];
        init(2*n+2);
        for(int i = 0; i < 3; ++i) poly[i].combine(a, b, len);
        // for(int i = 0; i < n*2-1; ++i) cerr << poly[0].r[i] << "\n";
        // for(int i = 0; i < n*2-1; ++i) cerr << poly[1].r[i] << "\n";
        // for(int i = 0; i < n*2-1; ++i) cerr << poly[2].r[i] << "\n";
        ll t0, t1;
        int p0 = mod[0], p1 = mod[1], p2 = mod[2];
        int *u = poly[0].r, *v = poly[1].r, *w = poly[2].r;
        ll p0p1 = 1ll * p0 * p1;
        ll _p0p1 = mul(fpow(p0, p2-2, p2), fpow(p1, p2 - 2, p2), p2);
        ll _0 = mul(p1, fpow(p1, p0 - 2, p0), p0p1);
        ll _1 = mul(p0, fpow(p0, p1 - 2, p1), p0p1);
        for(int i = 0; i < ret; ++i) {
            t0 = (mul(u[i], _0, p0p1)+mul(v[i], _1, p0p1))%p0p1;
            t1 = mul((w[i] - t0%p2 + p2)%p2, _p0p1, p2);
            // cerr << t0 << " " << t1 << "\n";
            cc[i] = (long long)(t1 * p0p1 + t0);
        }
        // for(auto x : cc) cout << x << "\n";

        for(int i = 0; i < n; ++i) a[i] = 0;
        for(int i = 0; i < m; ++i) b[i] = 0;
    }
    void solve(int n) { // give n
        vector<int> a(n), b(n);
        for(int i =0; i < n; ++i) a[i] = input[i];

        // for(int i = 0; i < n; ++i) cerr << input[i] << " "; cerr << "\n";

        for(int j = 0; j < n; ++j) b[n-j-1] = input[j];
        vector<int> c(2*n-1);
        multi(a, b, c, n, n, 2*n - 1);
        output[0] = c[n-1];
        for(int i = 1; i < n; ++i) {
            output[i] = c[n-i-1] + c[2*n-i-1];
        }
        // for(int i = 0; i < n; ++i) cerr << output[i] << " "; cerr << "\n";
    }
}



using NTT::input, NTT::output, NTT::solve;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q, res = 0;
    cin >> n >> q;
    vector<int> p(n + 1), vs(n + 1);
    for(int i = 1; i <= n; ++i) cin >> p[i];
    for(int i = 1; i <= n; ++i) if(!vs[i]) {
        vector<int> pa;
        int nw = i;
        for(; !vs[nw]; nw = p[nw]) {
            pa.push_back(nw);
            vs[nw] = 1;
        }
        int len = pa.size();
        if(!ys[len]) ys[len] = ++res, a[res].cnt = len, (a[res].val).resize(len);
        int id = ys[len];
        for(int _ = 0; _ < pa.size(); ++_) input[_] = pa[_];
        solve(pa.size());
        // for(int _ = 0; _ < pa.size(); ++_) cerr << output[_] << "\n";
        for(int _ = 0; _ < pa.size(); ++_) a[id].val[_] += output[_];
        // in = pa
        // (a[id].val) += output
    } 
    for(int o = 1, x; o <= q; ++o) {
        cin >> x;
        ll ans = 0;
        for(int i = 1; i <= res; ++i) ans += a[i].val[x % a[i].cnt];
        std::cout << ans << "\n";
    }
    return 0;
}