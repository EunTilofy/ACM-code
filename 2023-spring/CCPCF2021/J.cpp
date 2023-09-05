#include<bits/stdc++.h>
using namespace std;
const int N = 2e4 + 10, M = 2.1e7;
struct node {
    string s;
    int val;
} a[N];
int n;
int da[11], res[M];
int ch[M][11], ans = 0, cnt = 0;

void dfs(int id, int l, int r, int now) {
    if(now > r) {
        vector<int> pa;
        for(int i = 0; i < n; ++i) {
            int pos = 0;
            for(int j = l; j <= r; ++j) {
                pos += ((a[i].s[j] - 'A') == da[j]);
            }
            pa.push_back(pos);
        }
        if(!id) {
            int fa = 0;
            for(int pos : pa) {
                if(!ch[fa][pos]) {
                    ch[fa][pos] = ++cnt, res[cnt] = 0;
                    memset(ch[cnt], 0, sizeof ch[cnt]);
                }
                fa = ch[fa][pos];
            }
            res[fa]++;
        } else {
            int fa = 0;
            for(int i = 0; i < n; ++i) {
                int pos = a[i].val - pa[i];
                if(pos < 0 || !ch[fa][pos]) return ;
                fa = ch[fa][pos];
            }
            ans += res[fa];
        }
        return ;
    }
    for(int i = 0; i < 4; ++i) {
        da[now] = i;
        dfs(id, l, r, now + 1);
    }
}

void solve() {
    ans = 0, cnt = 0, memset(ch[0], 0, sizeof ch[0]);
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a[i].s >> a[i].val;
        a[i].val /= 10;
    }
    dfs(0, 0, 4, 0), dfs(1, 5, 9, 5);
    cout << ans << "\n";
}

int main() {
	int cnt = 0;
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
    cin >> T;
    for(int o = 1; o <= T; ++o) {
        solve();
    }
	return 0;
}