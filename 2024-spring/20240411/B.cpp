#include<bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

const int N = 505, mod = 998244353;
#define M 500
int f[N][N], p[N][N];
int Add(int x, int y) { return (x+y)%mod; }
int Dec(int x, int y) { return (x-y+mod)%mod; }
int Mul(int x, int y) { return (1ll*x*y)%mod; }

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n;
    vector<int> a(n),b;
    for(auto &x: a)
    {
        cin >> x;
        if(x != 0) b.push_back(x);
    }
    a=b; n=a.size();
    if(n==0)
    {
        cout << "0\n";
        return 0;
    }

    {
        int i,j,k;
        p[0][0] = 1;
        for(i=1; i<=M; ++i)
        {
            p[i][0] = p[i][i] = 1;
            for(j=1; j<i; ++j)
            {
                p[i][j] = Add(p[i-1][j-1], p[i-1][j]);
            }
        }
        for(i=1; i<=M; ++i) for(j=1; j<=i; ++j) p[i][j] = Add(p[i][j-1], p[i][j]);
    }

    function<int(int,int,int)> g = [&](int i, int j, int k) -> int
    {   
        if(i < 1 || j < 1 || k < 1) return 0;
        if(k >= i+j) return 0;
        if(i+j > M) return 0;
        int l=max(0, i-k), r=min(i+j-k-1, i-1);
        if(l > r || r < 0) return 0;
        int res = p[i+j-1-k][r];
        if(l) res = Dec(res, p[i+j-1-k][l-1]);
        return res;
    };

    int i,j,k;
    f[0][a[0]] = 1;
    for(i=1; i<n; ++i)
    {
        if(a[i]==0) 
        {
            for(j=0; j<=M; ++j) f[i][j] = f[i-1][j];
        }
        else
        {
            for(j=0; j<=M-a[i]; ++j) f[i][j+a[i]] = Add(f[i][j+a[i]], f[i-1][j]);
            for(j=0; j<=M; ++j) for(k=1; k<=M; ++k) if(f[i-1][j])
            {
                f[i][k] = Add(f[i][k], Mul(f[i-1][j], g(j, a[i], k)));
            }
        }
    }

    // for(int i = 0; i < n; ++i, cerr << "\n") for(int j = 0; j <= 10; ++j) cerr << f[i][j] << " ";

    int ans = 0;
    for(int i = 1; i <= M; ++i) ans = Add(ans, f[n-1][i]);
    cout << ans << "\n";
    return 0;
}