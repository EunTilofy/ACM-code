#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
const int MN = 1e5 + 5;
int a[MN], b[MN], c[MN];
priority_queue<pii> q;

void solve(){
	int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i];
        q.push({max(a[i], b[i]), i});
    }
    long long ans = 0;
    memset(c, 0, sizeof c);
    while(!q.empty()){
        pii _x = q.top(); q.pop();
        pii _y = q.top(); q.pop();
        int idx = _x.se, idy = _y.se, vx = _x.fi, vy = _y.fi;
        ans += abs(vx - vy); ++c[idx]; ++c[idy];
        assert(c[idx] <= 2);
        assert(c[idy] <= 2);
        if(c[idx] == 1) q.push({min(a[idx], b[idx]), idx});
        if(c[idy] == 1) q.push({min(a[idy], b[idy]), idy});
    }
    cout << ans << endl;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	solve();
}