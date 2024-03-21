#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int b[150][150];

int get(ll x) {
    int ans = 0;
    for(; x; x >>= 1) ans ^= (x & 1);
    return ans;
}
ll dfs(ll x, int now, int lmt, int num, int y) {
    // cout << x << " " << now << " " << lmt << " " << num << " " << y << "\n";
    if(now < 0) return num == y;
    if(!lmt) return 1ll << now; 
    ll ans = 0;
    if((x >> now) & 1 || !lmt) {
        // cout << "???\n";
        ans += dfs(x, now - 1, lmt, num ^ 1, y);
    }
    // if(((x >> now) & 1) == 0) cout << "!!\n";
    ans += dfs(x, now - 1, lmt && (((x >> now) & 1) == 0), num, y);
    return ans;
}

void solve() {
    int n;
    ll L;
    cin >> n >> L;
    vector<int> a(n), c(n);
    for(int &x : a) cin >> x;
    ll ans = 0;
    for(int i = 0; i < min(L + 1, 128ll); ++i) {
        for(int j = 0; j < n; ++j) 
            c[j] = a[j] ^ b[i][j];
        vector<int> q;
        int now = c[0], flg = 1;
        q.push_back(now);
        for(int j = 0; j < n; ++j) {
            if(j + i == 128) now = c[j], q.push_back(now);
            if(c[j] != now) {flg = 0; break;}
        }
        if(!flg) continue;
        // cout << i << " " << q[0] << "\n";
        ll Ans = 0;
        // continue;
        if(q.size() == 1) {
            Ans += dfs(L >> 7, 63, 1, 0, q[0]);
            // cout << ans << "\n";
            if(get(L >> 7) == q[0] && (L & 127) < i) {
                // cout << "---\n";
                Ans--;
            }
            // return ;
        } else {
            ll now = i;
            if(q[0] ^ q[1]) now |= 1ll << 7;
            for(int o = q[0] ^ q[1]; now <= L; now |= 1ll << (o + 7), now |= 1ll << (o + 8), o += 2) {
                ll pos = o + 8;
                ll sum = 0;
                sum += dfs(L >> pos, 63, 1, 0, q[1]);
                // cout << o << " " << pos << " " << now << "??\n";
                if(get(L >> pos) == q[1] && (L & ((1ll << pos) - 1)) < now) {
                    // cout << o << " " << pos << " " << now << "!!!!\n";
                    sum--;
                }
                // if(i == 127) cout << o << " " << sum << " " << ss[o] << "??\n";
                Ans += sum;
            }
        }
        ans += Ans;
    }
    // for(int i = 0; i < 128; ++i) if(DA[i] != da[i]) cout << i << " " << da[i] << " " << DA[i] << "!!!\n";
    cout << ans << "\n";
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0; i < 128; ++i) for(int j = 0; j <= 100; ++j) {
        b[i][j] = get(i + j);
    }
    int T; cin >> T;
    for(int o = 1; o <= T; ++o) solve();
}