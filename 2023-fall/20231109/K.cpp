#include<bits/stdc++.h>
using namespace std;

const int MN = 1e6+5;

int n;
vector<pair<int,bool>> a;
map<pair<int,int>, pair<int,int>> mp;
bool chk(pair<int,int> a, pair<int,int> b) {
    return (1ll*a.first*b.second-1ll*a.second*b.first)>0;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    a.resize(n);
    for(int i = 1; i <= n; ++i) {
        char c; int v;
        cin >> c >> v;
        a[i-1].first = v;
        a[i-1].second = (c=='-');
    }

    double ans = 0;

    sort(a.begin(), a.end(), [&](auto x, auto y)->bool {
        return x.first < y.first || (x.first == y.first && x.second < y.second); 
    });

    // for(auto [x, u] : a) cerr << x << " " << u << "--\n";

    int TP = 0, FP = 0, P = 0, N = 0;
    for(int i = 0; i < a.size(); ++i) TP += !a[i].second, FP += a[i].second, P += !a[i].second, N += a[i].second;

    // cerr << FN << " " << FP << "\n";

    for(int i = 0; i <= a.size(); ++i) {
        // int FNTN = i; 
        // int TPFP = n - i;
        // int TN = FNTN - FN;
        // int TP = TPFP - FP; 
        
        // cerr << FP << " " << TP << " " << FN << " " << TN << " " << a[i].first << "\n";

        pair<int,int> FPR, TPR;
        int g1 = gcd(FP, N), g2 = gcd(TP, P);
        FPR = {FP/g1, (N)/g1};
        TPR = {TP/g2, (P)/g2};
        if(!mp.count(FPR)) mp[FPR] = TPR;
        else {
            if(chk(TPR, mp[FPR])) mp[FPR] = TPR;
        }
        if(i == a.size()) break;
        int j = i;
        while(a[j+1].first == a[i].first) ++j;
        for(int k = i; k <= j; ++k) TP -= !a[k].second, FP -= a[k].second;
        i = j;
    }
    vector<pair<pair<int,int>, pair<int,int>>> _;
    for(auto [x, y] : mp) {
        _.push_back({x, y});
    }
    sort(_.begin(), _.end(), [&](auto x, auto y)->bool{
        return chk(y.first, x.first);
    });
    
    double _v = 0;
    for(auto [x, y] : _) {
        double xx = ((double)x.first / x.second);
        ans += (1 - xx) * (((double)y.first / y.second) - _v);
        _v = ((double)y.first / y.second);
        // cerr << ((double)x.first / x.second) << " " << ((double)y.first / y.second) << "\n";
    }

    cout << fixed << setprecision(10) << ans << "\n";
    return 0;
}


/*

3
+ 2
- 3
- 1

0.5

6
+ 7
- 2
- 5
+ 4
- 2
+ 6

0.888888888888889

8
+ 34
+ 33
+ 26
- 34
- 38
+ 39
- 7
- 27

0.5625

3 3 0 0 2
1 3 2 0 4
1 2 2 1 5
0 2 3 1 6
0 1 3 2 7
0 0 3 3 1007034128



8
+ 34
+ 33
+ 26
- 34
- 38
+ 39
- 7
- 27
4 4 0 0 7
3 4 1 0 26
3 3 1 1 27
2 3 2 1 33
2 2 2 2 34
1 1 3 3 38
0 1 4 3 39
0 0 4 4 0
1 1
0.75 0.75
0.666667 0.6
0.5 0.5
0.25 0.25
0 0.2
0.4333333333
*/