#include<bits/stdc++.h>
using namespace std;
const int MN = 2e5+5;
int n;
long long B, C, a[MN], p[MN];
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> B >> C;
    for(int i = 1; i <= n; ++i) cin >> a[i] >> p[i];
    n += 1;
    a[n]=3ll*B;
    p[n]=B+1;

    long long nowP = 0, cost = 0, now = a[1];
    // price, num
    multiset<pair<int, long long>> S;
    nowP += (long long)C;
    S.insert({p[1], C});

    for(int i = 2; i <= n; ++i) {
        // from i-1 to i
        while(cost < B && now < a[i] && S.size() > 0) {
            pair<int, long long> o = *S.begin();
            int pr = o.first;
            long long _ = o.second;
            long long cc = min(_, min((B-cost)/pr, (a[i]-now)));
            if(cc == 0) break;
            cost += cc * pr;
            now += cc;
            nowP -= cc;
            if(_ == cc) {
                S.erase(S.find(o));
            }
            else {
                S.erase(S.find(o));
                S.insert({pr, _ - cc});
            }
        }
        // cerr << now << " " << cost << endl;
        if(now == a[i]) {
            while(S.size() > 0) {
                pair<int, long long> o = *S.rbegin();
                if(o.first > p[i]) {
                    S.erase(S.find(o));
                    nowP -= o.second;
                } else break;
            }
            if(nowP < C) S.insert({p[i], C-nowP});
            nowP = C;
        }
        else break;
    }

    cout << now << endl;
    return 0;
}