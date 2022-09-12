#include <bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;

void read(int &x) {
    x = 0; char ch = getchar(); int f = 1;
    for(; ch < '0' || ch > '9'; ch = getchar()) if(ch == '-') f = -1;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
    x *= f;
}
const int mod = 1e9 + 7;
int add(int x, int y) {
    return ((1ll * x + y) % mod + mod) % mod;
}
void Add(int &x, int y) {
    x = add(x, y);
}
int mul(int x, int y) {
    return ((1ll * x * y % mod) + mod) % mod;
}
void Mul(int &x, int y) {
    x = mul(x, y);   
}

const int N = 1e5 + 10;
vector<int> g[N];

int mu[N], f[N], pr[N], mk[N];
void initu() {
    mu[1] = 1;
    for(int i = 2; i < N; ++i) {
        if(!mk[i]) pr[++pr[0]] = i, mu[i] = -1;
        for(int j = 1; j <= pr[0] && i * pr[j] < N; ++j) {
            mk[i * pr[j]] = 1;
            if(i % pr[j] == 0) break;
            else mu[i * pr[j]] = -mu[i];
        }
    }
}
void init() {
    for(int i = 1; i < N; ++i) {
        for(int j = i; j < N; j += i) {
            g[j].push_back(i);
            // if(j == 2) printf("%lld %lld %lld\n", i, j / i - 1, mu[j / i]);
            Add(f[j], mul(j / i - 1, mu[i]));
        }
    }
}

ll gcd(ll x, ll y) {
    return y ? gcd(y, x % y) : x;
}
ll lcm(ll x, ll y) {
    return x * y / gcd(x, y);
}

signed main() {
    initu(), init();
    // for(int i = 1; i <= 100; ++i) {
    //     printf("f[%lld] = %lld\n", i, f[i]);
    // }
    int n; read(n);
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        int cur = n - i;
        for(auto x : g[cur]) {
            Add(ans, mul(lcm(i, x), f[cur / x]));
        }
    }
    printf("%lld\n", ans);
    return 0;
}  