#include<bits/stdc++.h>
using namespace std;

const int MN = 2e5+5;
int n,q;
int a[MN];

int pr[1000000], mi[10000005];
bool mk[10000005];
void init() {
    int mx = 10000000;
    for(int i = 2; i <= mx; ++i) {
        if(!mk[i]) {
            pr[++pr[0]] = i;
            mi[i] = i;
        }
        for(int j = 1; j <= pr[0] && i * pr[j] <= mx; ++j) {
            mk[i * pr[j]] = 1;
            mi[i * pr[j]] = pr[j];
            if(i % pr[j] == 0) break;
        }
    }
}

int b[MN], num1[MN], num2[MN];
pair<int,int> st[19][MN];
pair<int,int> Merge(pair<int,int> x, pair<int,int> y) {
    if(x.first == y.first) return {x.first, x.second + y.second};
    else {
        if(x.second == y.second) return {0, 0};
        if(x.second > y.second) return {x.first, x.second-y.second};
        return {y.first, y.second-x.second};
    }
}
vector<int> S[MN];

pair<int,int> Get(int l, int r) {
    int len = r - l + 1;
    pair<int,int> res = {0, 0};
    for(int k = 18; ~k; --k) if((len >> k) & 1){
        res = Merge(res, st[k][l]);
        l += (1<<k);
    }
    return res;
}
int CCal(int r, int num) {
    if(r <= 0 || num == 0) return 0;
    if(S[num].back() <= r) return S[num].size();
    if(S[num][0] > r) return 0;
    return upper_bound(S[num].begin(), S[num].end(), r) - S[num].begin();
}
int Cal(int l, int r, int num) {
    return CCal(r, num) - CCal(l - 1, num);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
    cin >> n >> q;
    int cnt = 0;
    map<int, int> MP;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        int x = a[i];
        if(x == 1) {
            num1[i] = 1;
        } else {
            // cerr << x << " " << mi[x] << endl;
            int y = mi[x];
            while(x % y == 0) x /= y;
            if(x == 1) b[i] = y;
        }
        if(b[i]) {
            st[0][i] = {b[i], 1};
            num2[i] = 1;
            // ++cc[b[i]];
            if(!MP[b[i]]) {
                MP[b[i]]=++cnt;
                S[cnt].clear();
            }
            S[MP[b[i]]].push_back(i);
        }
        else st[0][i] = {0, 0};
    }
    for(int i = 1; i <= n; ++i) num1[i] += num1[i - 1], num2[i] += num2[i - 1];

    for(int k = 1; k <= 18; ++k)
    for(int i = 1; i <= n; ++i) if(i + (1<<k) - 1 <= n){
        st[k][i] = Merge(st[k-1][i], st[k-1][i + (1<<(k-1))]);
    }

    while(q--) {
        int l, r;
        cin >> l >> r;
        pair<int,int> o = Get(l, r);
        int num = Cal(l, r, MP[o.first]);
        int len = r - l + 1;
        int _1 = num1[r] - num1[l-1];
        int _2 = num2[r] - num2[l-1];
        int ans;
        if(_2 == num && _2 + _1 == len) ans = -1;
        else {
            ans = max(num, (_2 + 1) / 2) + _1;
        }
        cout << ans << "\n";
    }
    return 0;
}