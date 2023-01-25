#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define all(x) x.begin(),x.end()
#define fi first
#define se second
#define pb push_back

unordered_map<ll, int> ans;
unordered_set<int> pr;

void solve(){
	int n, m1, m2;
    cin >> n >> m1 >> m2;
    std::vector<int> d1, d2;
    ans.clear(); pr.clear();
    for(int i = 1; i * i <= m1; ++i) if(m1 % i == 0) {
        d1.pb(i);
        if(m1/i != i) d1.pb(m1/i);
    }
    int mm1 = m1, mm2 = m2;
    for(int i = 2; i * i <= m1; ++i) {
        if(mm1 % i == 0) {
            pr.insert(i);
            while(mm1%i==0) mm1/=i;
        }
    }
    if(mm1>1) pr.insert(mm1);
    for(int i = 1; i * i <= m2; ++i) if(m2 % i == 0) {
        d2.pb(i);
        if(m2/i != i) d2.pb(m2/i);
    }
    for(int i = 2; i * i <= m2; ++i) {
        if(mm2 % i == 0) {
            pr.insert(i);
            while(mm2%i==0) mm2/=i;
        }
    }
    if(mm2>1) pr.insert(mm2);
    sort(all(d1)); sort(all(d2));

    // std::vector<std::vector<int>> dd[2];
    // for(auto x : d1) {
    //     vector<int> _;
    //     for(auto y : d1) if(x % y == 0) _.pb(y);
    //     dd[0].pb(_);
    // }
    // for(auto x : d2) {
    //     vector<int> _;
    //     for(auto y : d2) if(x % y == 0) _.pb(y);
    //     dd[1].pb(_);
    // }

    // for(auto _pr : pr) cerr << _pr << endl;

    std::unordered_set<long long> S;
    int ans1 = 0, ans2 = 0;
    for(int ii = 0; ii < d1.size(); ++ii) for(int jj = 0; jj < d2.size(); ++jj) {
        int x = d1[ii], y = d2[jj];
        long long num = 1ll * x * y;
        if(!S.count(num)) {
            int xx = -1;
            if(num <= n) xx = 1;
            else {
                // cout << num << endl;
                for(auto _pr : pr) if(num % _pr == 0) {
                    int _num = ans[num/_pr];
                    if(_num != 0 && 1ll*_num*_pr<=n) {
                        if(xx == -1) xx = _num*_pr;
                        else xx = min(xx, _num*_pr);
                    }
                }
            }
            // int xx = -1, iii = ii, jjj = jj;
            // bool sw = 0;
            // if(dd[0][ii].size() > dd[1][jj].size()) {
            //     sw = 1;
            //     swap(iii, jjj);
            // }
            // int xxx = lower_bound(all(dd[sw][iii]), num/n/dd[sw^1][jjj].back()) - dd[sw][iii].begin();
            // for(;xxx<dd[sw][iii].size();++xxx) {
            //     int tx = dd[sw][iii][xxx];
            //     if(tx > xx && xx != -1) break;
            //     if(tx > n) break;
            //     int yyy = lower_bound(all(dd[sw^1][jjj]), num/n/tx) - dd[sw^1][jjj].begin();
            //     for(;yyy<dd[sw^1][jjj].size(); ++yyy) {
            //         int ty = dd[sw^1][jjj][yyy];
            //         if(1ll * tx * ty > n) break;
            //         if(tx * ty > xx && xx != -1) break;
            //         if(num / tx / ty <= n) {
            //             if(xx == -1) {xx = tx * ty;}
            //             else {xx = min(xx, tx * ty);}
            //             break;
            //         }
            //     }
            // }
            if(xx != -1) {
                ans[num] = xx;
                ++ans1, ans2 ^= xx;
            }
            else ans[num]=1e9+1;
        }
        S.insert(num);
    }
    cout << ans1 << " " << ans2 << endl;
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) 
		solve();
}