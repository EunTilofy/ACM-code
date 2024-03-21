#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define all(x) x.begin(),x.end()
#define fi first
#define se second
#define pb push_back
#define mkp make_pair
#define mod 998244353
#define dbg1(x) cerr << #x << '=' << (x) << ' '
#define dbg2(x) cerr << #x << '=' << (x) << '\n'
#define dbg3(x) cerr << #x << '\n'
inline int qpow(int x,ll y,int m=mod){int r=1;for(;y;y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;return r;}
inline int Add(int x, int y){return (x + y) % mod;}
inline int Mul(int x, int y){return 1ll * x * y % mod;}
#define cerr std::cerr
#define cout std::cout
#define cin std::cin
const int MN = 4e5 + 5;
int a[1005][1005];
int b[6][6];
int n, m;

void YES() {
    cout << "YES\n";
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) 
        cout << a[i][j] << " \n"[j==n];
}
void NO() {
    cout << "NO\n";
}
pair<int,int> nxt(int x, int y) {
    if(y < n) return {x, y + 1};
    else return {x + 1, 1};
}
bool dfs(int x, int y, int lef) {
    if(lef == 0 || (x == n && y == n)) {
        if(lef) b[n][n] += lef;
        int fl = 0, fl2 = 0;
        for(int i = 1; i <= n; ++i) fl ^= b[1][i], fl2 ^= b[i][1];
        // if(b[1][1] == 1 &&  b[2][2] == 1 &&  b[3][3] == 1) {
        //     if(b[1][2] == 2 && b[2][3] == 2 && b[3][1] == 2) {
        //         for(int i = 1; i <= n; ++i)
        //             for(int j = 1; j <= n; ++j) 
        //                 cerr << b[i][j] << " \n"[j == n];
        //     }
        // }
        for(int j = 2; j <= n; ++j) {
            int ffl = 0, ffl2 = 0;
            for(int i = 1; i <= n; ++i) ffl ^= b[j][i], ffl2 ^= b[i][j];
            if(ffl != fl || ffl2 != fl2) {b[n][n] = 0; return 0;}
        }
        for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) a[i][j] = b[i][j];
        b[n][n] = 0;
        return 1;
    }
    auto [xx, yy] = nxt(x, y);
    for(int val = 0; val <= 1; ++val) {
        b[x][y] = val;
        if(x > 1 && y == n) {
            int fl1 = 0, fl2 = 0;
            for(int i = 1; i <= n; ++i)
                fl1 ^= a[1][i], fl2 ^= a[x][i];
            if(fl1 != fl2) {
                b[x][y] = 0;
                continue;
            }
        }
        if(dfs(xx, yy, lef-val)) return 1;
        b[x][y] = 0;
    }
    return 0;
}

void solve() {
    cin >> n >> m;
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);
    if(m % 2 == 1 || m == 2 || m == n * n - 2) {
        NO(); return;
    }
    if(m % 4 == 0) {
        int cnt = m;
        for(int i = 1; i <= n; i += 2) for(int j = 1; j <= n; j += 2) {
            if(cnt) {
                cnt -= 4;
                a[i][j] = a[i+1][j] = a[i][j+1] = a[i+1][j+1] = 1;
            }
            else break;
        }
        YES(); return;
    }
    /*
    1 1 0 0 1 1 1 1
    1 0 1 0 1 1 1 1
    0 1 1 0 1 1 1 1
    0 0 0 0 1 1 1 1
    1 1 1 1 1 1 1 1
    1 1 1 1 1 1 1 1
    1 1 1 1 1 1 1 1
    1 1 1 1 1 1 1 1
 
    */
    if(n * n - 10 >= m && m >= 6) {
        a[1][1] = a[1][2] = a[2][1] = a[2][3] = a[3][2] = a[3][3] = 1;
        int cnt = m - 6;
        for(int i = 1; i < n; i += 2) for(int j = 5; j <= n; j += 2) {
            if(cnt) {
                cnt -= 4;
                a[i][j] = a[i+1][j] = a[i][j+1] = a[i+1][j+1] = 1;
            }
            else break;
        }
        for(int i = 5; i < n; i += 2) for(int j = 1; j < n; j += 2) {
            if(cnt) {
                cnt -= 4;
                a[i][j] = a[i+1][j] = a[i][j+1] = a[i+1][j+1] = 1;
            }
            else break;
        }
        YES(); return;
    }

    /*
    0 0 0 0 0 1
    0 1 1 1 1 1
    0 1 1 1 1 1
    0 1 1 1 1 1
    0 1 1 1 1 1
    1 1 1 1 1 0
    */

    // if(dfs(1, 1, m)) {
    //     YES(); return;
    // }
    // return;
    if(n == 2) {
        NO(); return;
    }
    /*
    a a 0 0
    a a 0 0
    0 0 0 0
    0 0 0 0
    */
    // if(n >= 5 && m % 2 == 0 && m >= 6) {
    //     a[1][1] = a[2][3] = a[3][2] = 1;
    //     a[1][2] = a[2][1] = a[3][3] = 1;
    //     a[1][3] = a[2][2] = a[3][1] = 0;
    //     assert((m-6)%4==0);
    //     a[4][4] = a[5][5] = a[4][5] = a[5][4] = (m-6)/4;
    //     YES(); return;
    // }
    if(m % 2 == 1) {
        NO(); return;
    }
    // if(m % 3 == 0 && m < 3000 && n > 2) {
    //     for(int aa = 1; aa < m/3; ++aa) 
    //         for(int b = aa; aa + b < m/3; ++b)
    //             if((aa^b^(m/3-aa-b))==0) {
    //                 a[1][1] = a[2][3] = a[3][2] = aa;
    //                 a[1][2] = a[2][1] = a[3][3] = b;
    //                 a[1][3] = a[2][2] = a[3][1] = m/3 - aa -b;
    //                 YES(); return;
    //             }
    // }
    // for(int i = 1; i <= n; ++i)
    //     for(int j = 1; j <= n; ++j) b[i][j] = 0;
    if(n == 4 && m == 6) {
        cout << "YES\n0 0 0 0\n0 0 1 1\n0 1 0 1\n0 1 1 0\n";
        return ;
    }
    if(n == 4 && m == 10) {
        cout << "YES\n0 0 0 1\n0 1 1 1\n0 1 1 1\n1 1 1 0\n";
        return ;
    }
    if(n * n - 6 == m) {
        a[1][1] = a[2][2] = a[3][3] = 1;
        for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) if(i > 3 || j > 3) a[i][j] = 1;
        YES(); return;
    }
    // if(dfs(1, 1, m)) {
    //     YES(); return;
    // }

    /*
    a b c
    b c a
    c a b

    a + b + c = n && a ^ b ^ c = 0
    1 ^ 2 ^ 3 = 0, 1 + 2 + 3 = 6 -> 18
    (n - a - b) ^ a ^ b = 0

    a b c d
    b c d a
    c d a b
    d a b c
    */

    NO();
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) 
		solve();
}