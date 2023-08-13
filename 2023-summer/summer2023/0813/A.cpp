#include<bits/stdc++.h>
using namespace std;

// map<long long, vector<int>> G;
// map<pair<long long, long long>, int> H[3005];
long long sqr(int x) {
    return 1ll * x * x;
}
long long num[3005];
__int128 H[3005][3005];
__int128 _ = 8000000000000000001ll;
void solve(int n) {
    vector<pair<int,int>> a(n + 1);
    // H.clear(); H.resize(n + 1);
    // G.clear();
    for(int i = 1; i <= n; ++i) {
        int x, y;
        cin >> x >> y;
        a[i] = {x, y};
        num[i] = sqr(x) + sqr(y);
        // G[X].push_back(i);
    }
    for(int i = 1; i <= n; ++i) H[i][0]=0;
    for(int i = 1; i <= n; ++i) for(int j = i + 1; j <= n; ++j) {
        if(i != j) {
            long long X = sqr(a[i].first - a[j].first) + sqr(a[i].second - a[j].second);
            long long I = sqr(a[i].first) + sqr(a[i].second);
            long long J = sqr(a[j].first) + sqr(a[j].second);
            __int128 num1 = J; num1 = num1 * _ + X;
            __int128 num2 = I; num2 = num2 * _ + X;
            H[i][++H[i][0]] = num1;
            H[j][++H[j][0]] = num2;
        }
    }
    for(int i = 1; i <= n; ++i) sort(H[i]+1, H[i]+H[i][0]+1);
    int Q;
    cin >> Q;
    while(Q--) {
        long long a, b, c;
        cin >> a >> b >> c;
        long long ans = 0;
        __int128 num1 = b * _ + c;
        for(int x = 1; x <= n; ++x) if(num[x] == a) {
            int l, r;
            l = lower_bound(H[x]+1, H[x]+H[x][0]+1, num1) - H[x];
            r = upper_bound(H[x]+1, H[x]+H[x][0]+1, num1) - H[x];
            ans += r - l;
        } 
        if(a == b) ans /= 2;
        cout << ans << "\n";
    }
}

int main() {
    freopen("astronomy.in", "r", stdin);
    freopen("astronomy.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(1) {
        int N;
        cin >> N;
        if(N) solve(N);
        else break;
    }
    return 0;
}