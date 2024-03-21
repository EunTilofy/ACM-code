#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2510;
string S = "GQBW";
int n, m;
int nm[4];
int qz[N][4];
int a[N], b[N];
void Max(int &x, int y) {
    x = max(x, y);
}
void Min(int &x, int y) {
    x = min(x, y);
}
int g[N][N], f[N][N * 2];
bool check(int x) {
    for(int i = 0; i <= m; ++i) if(g[i][x] != -1) {
        int n1 = g[i][x], n2 = nm[2] + qz[i][2] - x;
        if(f[i + 1][n2] <= n1) return true;
    }
    return false;
}

void solve() {
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    for(int i = 1; i <= n; ++i) a[i] = S.find(s[i - 1]);
    for(int i = 1; i <= m; ++i) b[i] = S.find(t[i - 1]);
    memset(nm, 0, sizeof nm);
    for(int i = 1; i <= n; ++i) nm[a[i]]++;
    int n1 = nm[1], n2 = nm[2], sum = 0, nw = 1;
    for(; nw <= m; ) {
        vector<int> q;
        if(n1) {
            n1--;
            if(b[nw] == 1) n1++;
            if(b[nw] == 2) n2++;
            nw++;
        } else if(n2) {
            sum++, n2--;
            q.push_back(b[nw]);
            if(nw + 1 <= m) q.push_back(b[nw + 1]);
            nw += 2;
        } else break;
        for(int x : q) {
            if(x == 1) n1++;
            if(x == 2) n2++;
        }
    }
    if(nw <= m) {
        cout << "IMPOSSIBLE\n";
        return ;
    }
    int l = 0, r = sum, ans = sum;
    for(int i = 1; i <= m; ++i) {
        for(int j = 0; j < 4; ++j) qz[i][j] = qz[i - 1][j];
        qz[i][b[i]]++;
    }
    for(int i = 0; i <= m; ++i) for(int j = 0; j <= m; ++j) g[i][j] = -1;
    g[0][0] = nm[1];
    for(int i = 0; i <= m; ++i) {
        for(int j = 0; j < m; ++j) if(g[i][j] != -1) {
            if(g[i][j] && i + 1 <= m) Max(g[i + 1][j], g[i][j] - (b[i + 1] != 1));
            if(nm[2] + qz[i][2] > j && i + 2 <= m) Max(g[i + 2][j + 1], g[i][j] + (b[i + 1] == 1) + (b[i + 2] == 1));
        }
    }
    for(int i = 0; i <= m + 1; ++i) for(int j = 0; j <= nm[1] + qz[m][1] + 2; ++j) f[i][j] = 1e9 * (i != m + 1);
    for(int i = m + 1; i >= 0; --i) for(int j = nm[1] + qz[m][1]; j >= 0; --j) {
        Min(f[i][j], f[i][j + 1]);
        if(f[i][j] != 1e9) {
            if(i >= 1) {
                Min(f[i - 1][j], f[i][j] + (b[i - 1] != 1)); 
                if(j && b[i - 1] == 2) Min(f[i - 1][j - 1], f[i][j] + 1);
            }
            if(i >= 2) {
                Min(f[i - 2][j], f[i][j] - (b[i - 1] == 1));
                if(j && b[i - 1] == 2) Min(f[i - 2][j - 1], f[i][j]);
            }
        }
        cout << i << " " << j << " " << f[i][j] << "\n";
    }
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(check(mid)) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    cout << ans + n << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for(int o = 1; o <= T; ++o) solve();
}