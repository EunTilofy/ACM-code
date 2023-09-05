#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long lll;
// typedef __int128 lll;
const int N = 1e6 + 10, LOG = 21;
int n, pw[N];
ll a[N];
lll sum[N], p[N], P[N];
int st[N][LOG + 1], St[N][LOG + 1];

lll getmx(int l, int r) {
    int k = pw[r - l + 1];
    return max(p[st[l][k]], p[st[r - (1 << k) + 1][k]]);
}
lll Getmx(int l, int r) {
    int k = pw[r - l + 1];
    return max(P[St[l][k]], P[St[r - (1 << k) + 1][k]]);
}

int findr(lll x, int be, int r) {
    // cerr << x << " " << be << " " << r << "findr\n";
    int l = be, ans = -1;    //???
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(getmx(be, mid) > x) ans = mid, r = mid - 1;  //??
        else l = mid + 1;
    }
    // cerr << "ans = " << ans << "\n";
    return ans;
}

int findl(lll x, int ed, int l) {
    // cerr << x << " " << ed << " " << l << "findl\n";
    int r = ed, ans = -1;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(Getmx(mid, ed) > x) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    // cerr << "ans = " << ans << "\n";
    return ans;
}

ll go(int be) {
    lll x = 2 * a[be];
    ll ans = a[be];
    int l = be + 1, r = be - 1;
    if(l > n) l -= n;
    if(r < 1) r += n;
    int res = 0;
    while(1) {
        // cerr << l << " " << r << " " << x << "!\n";
        if(a[l] < a[r]) {
            if(x < a[l]) ans += a[l] - x, x = a[l];
            lll pos = x - sum[l - 1];
            int id = findr(pos, l, l > r ? r + n : r);
            if(id != -1) x += sum[id - 1] - sum[l - 1], l = id > n ? id - n: id;
            else return ans;
            lll tmp = l > r ? x + sum[r + n] : x + sum[r];
            int di = findl(tmp, l > r ? r + n: r, l);
            if(di != -1) x = tmp - sum[di], r = di > n ? di - n : di;
            else return ans;
        } else {
            if(x < a[r]) ans += a[r] - x, x = a[r];
            lll tmp = l > r ? x + sum[r + n] : x + sum[r];
            int di = findl(tmp, l > r ? r + n: r, l);
            if(di != -1) x = tmp - sum[di], r = di > n ? di - n : di;
            else return ans;
            lll pos = x - sum[l - 1];
            int id = findr(pos, l, l > r ? r + n : r);
            if(id != -1) x += sum[id - 1] - sum[l - 1], l = id > n ? id - n: id;
            else return ans;
        }
        res++;
        // assert(res < 40);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 2; i <= 2 * n; ++i) {
        pw[i] = pw[i / 2] + 1;
    }
    ll ans = 1e13;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    int m = 2 * n;
    for(int i = 1; i <= m; ++i) {
        sum[i] = sum[i - 1] + a[i];
        p[i] = -sum[i] + a[i] * 2;
        P[i] = sum[i] + a[i];
    }
    for(int i = 1; i <= m; ++i) st[i][0] = i, St[i][0] = i;
    for(int j = 1; j <= LOG; ++j) for(int i = 1; i + (1 << j) <= m + 1; ++i) {
        st[i][j] = p[st[i][j - 1]] >= p[st[i + (1 << (j - 1))][j - 1]] ? st[i][j - 1] : st[i + (1 << (j - 1))][j - 1];
        St[i][j] = P[St[i][j - 1]] >= P[St[i + (1 << (j - 1))][j - 1]] ? St[i][j - 1] : St[i + (1 << (j - 1))][j - 1];
    }
    for(int i = 1; i <= n; ++i) {
        ll pos = go(i);
        // cerr << i << " " << pos << "!!\n";
        ans = min(ans, pos);
    }
    cout << ans << "\n";
    return 0;
}