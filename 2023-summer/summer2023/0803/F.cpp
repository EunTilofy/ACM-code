#include<bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
const int N = 4e5 + 10;

bool cmp(vector<int> a, vector<int> b) {
    if(a[0] > b[0]) return true;
    if(a[0] < b[0]) return false;
    for(int i = 1; i < a.size(); ++i) {
        if(a[i] > b[i]) return true;
        if(a[i] < b[i]) return false;
    }
    return true;
}

vector<int> mul(vector<int> a, int b) {
    for(int i = 1; i <= a[0] / 2; ++i) swap(a[i], a[a[0] - i + 1]);
    vector<int> c(a.size(), 0);
    // for(int x : a) cerr << x; cerr << "aa\n";
    c[0] = a[0];
    for(int i = 1; i <= a[0]; ++i) {
        c[i] += a[i] * b;
        int pos = c[i] / 10;
        c[i] %= 10;
        if(i + 1 < c[0]) c[i + 1] += pos;
        else if(pos) c.push_back(pos), c[0]++;
    }
    for(; c[c[0]] >= 10; ) {
        c.push_back(c[c[0]] / 10);
        c[c[0]] %= 10;
        c[0]++;
    }
    for(int i = 1; i <= c[0] / 2; ++i) swap(c[i], c[c[0] - i + 1]);
    return c;
}
vector<int> cut(vector<int> a, vector<int> b) {
    for(int i = 1; i <= a[0] / 2; ++i) swap(a[i], a[a[0] - i + 1]);
    for(int i = 1; i <= b[0] / 2; ++i) swap(b[i], b[b[0] - i + 1]);
    // for(int x : a) cerr <<x;cerr <<"a\n";
    // for(int x: b) cerr << x; cerr << "b\n";
    for(int i = a[0]; i >= 1; --i) {
        if(i <= b[0]) {
            a[i] -= b[i];
            if(a[i] < 0) a[i + 1]--, a[i] += 10;
        }
    }
    // for(int x : a) cerr << x; cerr <<"a\n";
    vector<int> c; c.push_back(0);
    for(int i = a[0]; i >= 1; --i) {
        if(a[i]) {
            for(int j = i; j >= 1; --j) {
                c.push_back(a[j]);
                c[0]++;
            }
            return c;
        }
    }
    return {1, 0};
}

pair<vector<int>, vector<int> > chu(vector<int> a, vector<int> b) {
    vector<int> c, d;
    c.push_back(0), d.push_back(0);
    for(int i = 1; i <= a[0]; ++i) {
        d[0]++;
        d.push_back(a[i]);
        // cerr << i << "\n";
        if(cmp(d, b)) {
            // cerr << "in\n";
            int pos = -1;
            for(int j = 1; j <= 9; ++j) {
                if(cmp(d, mul(b, j))) pos = j;
                else break;
            }
            // cerr << pos << "\n";
            assert(pos > 0);
            // cerr << pos << "pos\n";
            c[0]++;
            vector<int> z = mul(b, pos);
            // for(int x : z) cerr << x; cerr <<"z\n";
            d = cut(d, z);
            // for(int x : d) cerr << x;cerr << "!\n";
            c.push_back(pos);
        } else if(c[0]) {
            c[0]++;
            c.push_back(0);
        }
    }
    if(!d[0]) d.push_back(0);
    return {c, d};
}

int main() {
    // freopen("continued.in", "r", stdin);
    // freopen("continued.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 2, 0), b(m + 1, 9);
    a[0] = n + 1, a[1] = 1;
    b[0] = m;
    vector<vector<int> > ans;
    for(;;) {
        if(cmp(a, b)) {
            // cerr << "!!\n";
            auto[c, d] = chu(a, b);
            a = b, b = d;
            ans.push_back(c);
            if(d[0] == 1 && d[1] == 0) break;
        } else {
            assert(ans.size()==0);
            ans.push_back({1, 0});
            swap(a, b);
        }
    }
    cout << ans.size() - 1 << "\n";
    for(auto x : ans) {
        for(int i = 1; i <= x[0]; ++i) cout << x[i];
        cout << " ";
    }
    return 0;
}
/*
!!
1
2
in
1
1pos
19z
201a
19b
210a
11!
!!
1
in
9
9pos
19z
19a
19b
10a
10!

1
11 19

*/