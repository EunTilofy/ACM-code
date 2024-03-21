#include<bits/stdc++.h>
using namespace std;

const int MN = 5e5+5, MM = (5e5+5) * 20;
struct node {int l, r, s;}t[MM];
int tot = 0;
vector<long long> _;
void Add(int& rt, int rt2, int l, int r, int v) {
    rt = ++tot;
    t[rt].s = t[rt2].s;
    if(l == r) {
        t[rt].s += 1;
        return ;
    }
    int mid = (l + r) >>1;
    if(v <= mid) Add(t[rt].l, t[rt2].l, l, mid, v), t[rt].r = t[rt2].r;
    else Add(t[rt].r, t[rt2].r, mid+1, r, v), t[rt].l = t[rt2].l;
    t[rt].s = t[t[rt].l].s + t[t[rt].r].s;
}
int Que(int rt, int l, int r, long long v) {
    if(!rt) return 0;
    if(l == r) { return t[rt].s; }
    int mid = (l + r) >> 1;
    if(v < _[mid]) return Que(t[rt].l, l, mid, v);
    else return t[t[rt].l].s + Que(t[rt].r, mid+1, r, v);
}

long long a[MN], b[MN];
long long n, k, all;

__int128 qzh[MN];
int rt[MN];
void init() {
    qzh[n+1] = 0;
    for(int i = n; i; --i) {
        qzh[i] = qzh[i+1] + a[i]/k;
        b[i] = ((a[i]%k)+k)%k;
        _.push_back(b[i]);
    }
    sort(_.begin(), _.end());
    _.erase(unique(_.begin(), _.end()), _.end());
    all = _.size();
    for(int i = n; i; --i) {
        b[i] = lower_bound(_.begin(), _.end(), b[i]) - _.begin() + 1;
        Add(rt[i], rt[i+1], 1, all, b[i]);
    }
}

int Que2(int l, long long num) {
    // long long ret = 0;
    // for(int i = l; i <= n; ++i) {
    //     ret += (((a[i]%k)+k)%k) <= num;
    // }
    // return ret;
    // num = upper_bound(_.begin(), _.end(), num) - _.begin(); // <= num
    if(num < _[0]) return 0;
    return Que(rt[l], 1, all, num);
}

__int128 cal(long long c, int x) {
    int l = upper_bound(a+1, a+n+1, c) - a;
    __int128 ret = n - l + 1 - x + 1;
    if(ret <= 0) return 0;

    __int128 cc = (c>=0?c/k:(c-k+1)/k);

    ret += qzh[l] - cc * (n-l+1);
    long long __ = c%k; if(__ < 0) __ += k;
    ret -= Que2(l, __);
    return ret;
}

__int128 tim[MN];

int main() {
    // freopen("in.txt", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie(0);
    int m; cin >> n >> m >> k;

    __int128 T = 0;
    long long INF = 1e18;

    for(int i = 1; i <= n; ++i) cin >> a[i];
    sort(a+1, a+n+1);

    init();

    for(int i = 1; i <= n; ++i) tim[i] = cal(a[i] - 1, n-i+1);
    int J = n;

    while(m--) {
        string s;
        cin >> s;
        if(s[0] == 'A') {
            int x; cin >> x;
            if(n-x+1 <= J) {
                cout << a[n-x+1] << "\n";
                continue;
            }
            long long L = -INF, R = a[n-x+1]-1, ans = R+1;
            if(tim[1] > T) L = a[1];
            else if((a[1] + INF) / k >= ((T - tim[1]) / n + 1)) L = a[1] - k * ((T - tim[1]) / n + 1);
            // cerr << L << " " << R << "\n";
            while(L <= R) {
                long long mid = (L + R) >> 1;
                if(cal(mid, x) <= T) ans = mid, R = mid - 1;
                else L = mid + 1;
            }
            cout << ans << "\n";
        } else {
            long long t; cin >> t;
            T += t;
            while(T >= tim[J] && J >= 1) --J;
        }
    }
    return 0;    
}

/*
3 5 5
7 3 9
A 3
C 1
A 2
C 2
A 3
*/