#include<bits/stdc++.h>
using namespace std;
const int N = 405, mod = 167772161;
int a[N], pr[N][N][N], sf[N][N][N], id[N];
vector<int> ans[N];

int add(int x, int y) {
    return (x + y) % mod;
}
void Add(int &x, int y) {
    x = add(x, y);
}
int mul(int x, int y) {
    return 1ll * x * y % mod;
}
void Mul(int &x, int y) {
    x = mul(x, y);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, K;
    cin >> n >> K;
    for(int i = 1; i <= n; ++i) cin >> a[i], id[i] = i;
    sort(id+1, id+n+1, [&](int x, int y)->bool{
        return a[x] < a[y];
    });
    sort(a+1, a+n+1);

    pr[0][0][0] = sf[n+1][0][0] = 1;
    for(int i = 1; i <= n; ++i) {
        pr[i][0][0] = 1;
        for(int j = 1; j <= i; ++j) for(int k = 0; k < N; ++k) {
            Add(pr[i][j][k], pr[i - 1][j][k]);
            if(k >= a[i]) Add(pr[i][j][k], pr[i - 1][j - 1][k - a[i]]);
        }
    }
    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= i; ++j) for(int k = 1; k < N; ++k)
            Add(pr[i][j][k], pr[i][j][k-1]); 
    }
    for(int i = n; i >= 1; --i) {
        sf[i][0][0] = 1;
        for(int j = 1; j <= (n - i + 1); ++j) for(int k = 0; k < N; ++k) {
            Add(sf[i][j][k], sf[i + 1][j][k]);
            if(k >= a[i]) Add(sf[i][j][k], sf[i + 1][j - 1][k - a[i]]);
        }
    }
    for(int i = 1; i <= n; ++i) {
        if(a[i] == a[i-1]) {
            ans[id[i]] = ans[id[i-1]];
            continue;
        }
        ans[id[i]].resize(n);
        int UP = min(n, K/a[i]);
        for(int r = 0; r <= UP; ++r) {
            for(int l = 0; l <= n-1-r; ++l) if(l + r > 0) {
                for(int nr = 0; nr <= K; ++nr) if(sf[i+1][r][nr]) {
                    int _l = max(K-a[i]+1-nr, 0), _r = K-nr;
                    if(_l <= _r) {
                        int NUM = pr[i-1][l][_r];
                        if(_l) NUM = add(NUM, mod - pr[i-1][l][_l-1]);
                        Add(ans[id[i]][l+r], mul(sf[i+1][r][nr], NUM));
                    }
                }
            }
        }
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j < n; ++j) {
            cout << ans[i][j] << " " ;
        }
        cout << "\n";
    }
    return 0;
}