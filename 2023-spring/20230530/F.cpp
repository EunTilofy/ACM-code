#include<bits/stdc++.h>
using namespace std;
#define cin std::cin
#define cout std::cout
#define cerr std::cerr

typedef pair<int, int> pii;
typedef pair<pii, int> Type;
#define fi first
#define se second
#define ll long long
#define int long long

const int mod = 998244353;
int n;
vector<pair<pii, int>> a;

const int MN = 2e5 + 5;

struct node{
    int l, r;
    int _mul;
    int sum;
}t[2][MN<<2];

int pw2[MN];

void pushdown(int id, int k, int l, int r) {
    if(!t[id][k]._mul) return;
    t[id][k<<1]._mul += t[id][k]._mul;
    t[id][k<<1|1]._mul += t[id][k]._mul;
    t[id][k<<1].sum = (ll)t[id][k<<1].sum * pw2[t[id][k]._mul] % mod;
    t[id][k<<1|1].sum = (ll)t[id][k<<1|1].sum * pw2[t[id][k]._mul] % mod;
    t[id][k]._mul = 0;
}

void CMul(int id, int k, int l, int r, int a, int b) {
    if(l == a && r == b) {
        t[id][k]._mul++;
        t[id][k].sum = (ll)t[id][k].sum * 2 % mod;
        return;
    }
    pushdown(id, k, l, r);
    int mid = (l + r) >> 1;
    if(b <= mid) CMul(id, k<<1, l, mid, a, b);
    else if(a > mid) CMul(id, k<<1|1, mid+1, r, a, b);
    else {
        CMul(id, k<<1, l, mid, a, mid);
        CMul(id, k<<1|1, mid+1, r, mid+1, b);
    }
    t[id][k].sum = (t[id][k<<1].sum + t[id][k<<1|1].sum) % mod;
}
int CSum(int id, int k, int l, int r, int a, int b) {
    // cerr << id << " " << k << " " << l << " " << r << " " << a << " " << b << endl;
    if(l == a && r == b) {
        return t[id][k].sum;
    }
    pushdown(id, k, l, r);
    int mid = (l + r) >> 1;
    if(b <= mid) return CSum(id, k<<1, l, mid, a, b);
    else if(a > mid) return CSum(id, k<<1|1, mid+1, r, a, b);
    else return (CSum(id,k<<1,l,mid,a,mid)+CSum(id,k<<1|1,mid+1,r,mid+1,b)) % mod;
}
void CMod(int id, int k, int l, int r, int a, int val) {
    if(l == r) {
        t[id][k].sum = val;
        return;
    }
    pushdown(id, k, l, r);
    int mid = (l + r) >> 1;
    if(a <= mid) CMod(id, k<<1, l, mid, a, val);
    else CMod(id, k<<1|1, mid+1, r, a, val);
    t[id][k].sum = (t[id][k<<1].sum + t[id][k<<1|1].sum) % mod;
}
void CBuild(int id, int k, int l, int r) {
    if(l == r) {
        t[id][k].sum = t[id][k]._mul = 0;
        if(l == 1) {
            t[id][k].sum = 1;
        }
        return ;
    }
    int mid = (l + r) >> 1;
    CBuild(id, k<<1, l, mid);
    CBuild(id, k<<1|1, mid+1, r);
    t[id][k].sum = (t[id][k<<1].sum + t[id][k<<1|1].sum) % mod;
}
void _Build(int id, int k, int l, int r) {
    t[id][k].sum = t[id][k]._mul = 0;
    if(l == r) {
        return ;
    }
    int mid = (l + r) >> 1;
    _Build(id, k<<1, l, mid);
    _Build(id, k<<1|1, mid+1, r);
}

void solve() {
    cin >> n;
    a.resize(n);
    set<int> s;
    map<int,int> mp;
    s.insert(-2);
    for(auto &[x, y] : a) {
        cin >> x.first >> x.second >> y;
        s.insert(x.first);
        s.insert(x.second);
    }
    
    int cnt = 0;
    for(auto x : s) mp[x] = ++cnt;

    for(auto &[x, y] : a) {
        x.first = mp[x.first];
        x.second = mp[x.second];
    }

    vector<pair<vector<pii>, vector<pii>>> data(cnt+1);
    for(auto &x: a) {
        if(x.se == 1) data[x.fi.se].second.push_back(x.fi);
        else data[x.fi.se].first.push_back(x.fi);
    } 

    CBuild(0, 1, 1, cnt);
    CBuild(1, 1, 1, cnt);

    int last0 = 1, last1 = 1, now = 0;

    int ans = 0;

    for(auto &[D0, D1] : data) {
        if(now == 0 || now == 1) {++now; continue;}
        
        //
        // cerr << now << endl;
        // cerr << "d0" << endl;
        // for(auto &[l, r] : D0) cerr << l << " " << r << endl;
        // cerr << "d1" << endl;
        // for(auto &[l, r] : D1) cerr << l << " " << r << endl;
        //
        
        // cal
        for(auto &[l, r] : D0) {
            // cerr << "mod!" << endl;
            // cerr << "Mul! 1 " << " " << l-1 << endl;
            CMul(1, 1, 1, cnt, 1, l-1);
        }
        for(auto &[l, r] : D1) {
            // cerr << "mod!" << endl;
            // cerr << "Mul! 0 " << " " << l-1 << endl;
            CMul(0, 1, 1, cnt, 1, l-1);
        }
        // mod
        int cal0 = CSum(1, 1, 1, cnt, 1, now);
        int cal1 = CSum(0, 1, 1, cnt, 1, now);

        // cerr << now << " : " << cal0 << " " << last0 << " " << cal1 << " " << last1 << endl;
        int cc0 = (cal0 - last0 + mod) % mod, cc1 = (cal1 - last1 + mod) % mod;
        CMod(0, 1, 1, cnt, now, cc0);
        CMod(1, 1, 1, cnt, now, cc1);

        ans = ((ans + cc0) % mod + cc1) % mod;

        // cerr << "cal0 " << cal0 << " cal1 " << cal1 << endl;
        last0 = CSum(1, 1, 1, cnt, 1, now);
        last1 = CSum(0, 1, 1, cnt, 1, now);
        ++now;
    }

    cout << (1+ans) % mod << endl;

    _Build(0, 1, 1, cnt);
    _Build(1, 1, 1, cnt);

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    pw2[0] = 1;
    for(int i = 1; i < MN; ++i) pw2[i] = pw2[i-1] * 2ll % mod;

    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}