#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
struct node {
    vector<pair<int, int>> in, ou;
}c[N];
map<pair<int, int>, int> ed;
ll sum = 0;


struct LCT {
    int f[N], c[N][2], siz[N], st[N];
    ll s[N], sg[N];
    bool lz[N];
    void init(int n) {
        ++n;
        for(int i = 0; i < n; ++i) {
            f[i] = c[i][0] = c[i][1] = lz[i] = 0;
            s[i] = sg[i] = 0;
            siz[i] = 0;
        }
    }
    ll cal(int x) {
        return 1ll * x * (x - 1) / 2;
    }
    bool nroot(int x) const {
        return c[f[x]][0] == x || c[f[x]][1] == x;
    }
    void pushup(int x) {
        int lc = c[x][0], rc = c[x][1];
        siz[x] = siz[lc] + siz[rc] + 1;
        s[x] = s[lc] + s[rc] + 1 + sg[x];
    }
    void swp(int x) {
        swap(c[x][0], c[x][1]);
        lz[x] ^= 1;
    }
    void pushdown(int x) {
        int lc = c[x][0], rc = c[x][1];
        if(lz[x]) {
            if(lc) swp(lc);
            if(rc) swp(rc);
            lz[x] = 0;
        }
    }
    void zigzag(int x) {
        int y = f[x], z = f[y], typ = (c[y][0] == x);
        if(nroot(y)) c[z][c[z][1] == y] = x;
        f[x] = z, f[y] = x;
        if(c[x][typ]) f[c[x][typ]] = y;
        c[y][typ ^ 1] = c[x][typ];
        c[x][typ] = y;
        pushup(y);
    }
    void splay(int x) {
        int y, tp = 0;
        st[tp = 1] = y = x;
        while(nroot(y)) st[++tp] = y = f[y];
        while(tp) pushdown(st[tp--]);
        for(; nroot(x); zigzag(x)) if(!nroot(f[x])) continue;
        else zigzag((c[f[x]][0]==x) ^ (c[f[f[x]]][0]==f[x]) ? x : f[x]);
        pushup(x);
    }
    void access(int x) {
        for(int y = 0; x; x = f[y = x]) {
            splay(x);
            sg[x] -= s[y], s[x] -= s[y];
            sg[x] += s[c[x][1]]; s[x] += s[c[x][1]];
            c[x][1] = y; pushup(x);
        }
    }
    int findroot(int x) {
        access(x); splay(x); pushdown(x);
        while(c[x][0]) pushdown(x=c[x][0]);
        splay(x);
        return x;
    }
    void split(int x, int y) {
        makeroot(x);
        access(y);
        splay(y);
    }
    void makeroot(int x) {
        access(x); splay(x);
        swp(x);
        pushup(x);
    }
    ll get(int x) {
        split(x, x);
        cerr << "? " << x << " " << s[x] << "\n";
        return cal(s[x]);
    }
    void link(int x, int y) {
        cerr << "link" << x << " " << y << "\n";
        
        makeroot(x); 
        if(x != findroot(y)) {
            sum -= get(x) + get(y);
            makeroot(x); f[x] = y;
            sg[y] += s[x], s[y] += s[x]; 
            sum += get(x);
        }
       
        cerr << "sum = " << sum << "\n";
    }
    void cut(int x, int y) {
        cerr << "cut" << x << " " << y << "\n";
        makeroot(x); 
        ll pos = -get(x);
        if(x == findroot(y)) {
            
            pushdown(x);
            // split(x, y);
            if(c[x][1] == y && !c[y][0] && !c[y][1]) {
                c[x][1] = f[y] = 0;
                cerr << "!!!\n";
                pushup(x);
            } 
            if(c[x][0] == y && !c[y][0] && !c[y ][1]) {
                c[x][0] = f[y] = 0;
                cerr << "!!!\n";
                pushup(x);
            } 
        }
        // split(x, y);
        // if(c[y][0] == x && !c[x][1]) c[y][0] = f[x] = 0, pushup(y);
        makeroot(x);
        if(x != findroot(y)) sum += pos + get(x) + get(y);
        cerr << "sum = " << sum << "\n";
    }
} tr;

map<int, int> mp;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k, res = 0;
    cin >> n >> m >> k;
    tr.init(n);
    vector<pair<int, int>> q;
    
    
    for(int i = 1, x, y, z; i <= m; ++i) {
        cin >> x >> y >> z;
        if(x > y) swap(x, y);
        int pos = 0;
        // cerr << i << "=======\n";
        for(int i = 29; i >= 0; --i) {
            int ki = (k >> i) & 1, zi = (z >> i) & 1;
            if(ki) {
                int l = pos | ((zi) << i), r = l + ((1 << i) - 1) + 1;
                // cerr << l << " " << r << "\n";
                if(!mp.count(l)) mp[l] = ++res;
                if(!mp.count(r)) mp[r] = ++res;
                (c[mp[l]].in).push_back({x, y});
                (c[mp[r]].ou).push_back({x, y});
            }
            pos |= (ki != zi) << i;
        }
    }
    int Q;
    cin >> Q;
    for(int o = 0, x; o < Q; ++o) {
        cin >> x;
        q.push_back({x, o});
    }
    sort(all(q));
    vector<ll> ans(Q);

    auto it = mp.begin();
    for(auto [val, id] : q) {
        cerr << val << "val----\n";
        for(; it != mp.end() && (*it).first <= val; ++it) {
            int i = (*it).second;
            for(auto[x, y] : c[i].in) {
                ed[{x, y}]++;
                if(ed[{x, y}] == 1) tr.link(x, y);
            }
            for(auto[x, y] : c[i].ou) {
                ed[{x, y}]--;
                if(!ed[{x, y}]) tr.cut(x, y);
            }
        }
        // tr.init(n);
        // for(auto[x, y] : ed) if(y) {tr.link(x.first, x.second); cout << x.first << " " << x.second << "\n";}
        ans[id] = sum;
    }
    for(ll x: ans) cout << x << "\n";
    return 0;
}