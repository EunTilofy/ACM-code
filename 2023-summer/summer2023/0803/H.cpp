#include<bits/stdc++.h>
using namespace std;

int F;
int f[100005];
int cal(int x, int i, int j) {
    int r = 0;
    if(i&1) r^=f[x];
    if(j&1) r^=f[x+1];
    return r;
}

void init() {
    for(int i = F; i <= 100000; ++i) {
        vector<int> _;
        
        for(int l=2,r; l<=i; ++l) {
            r=i/(i/l);
            
            int j=i/l, k=i%l;
            _.push_back(cal(j, l-k, k));
            if(r>l) _.push_back(cal(j, l+1-k+j, k-j));
            l=r;
        }

        sort(_.begin(), _.end());
        int tmp=0;
        for(auto x:_) {
            if(x>tmp) break;
            if(x==tmp) tmp++;
        }
        f[i]=tmp;
    }
}

void solve() {
    int n;
    cin >> n;
    int ans=0;
    for(int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        ans ^= f[x];
    }
    if(ans) cout << "1 ";
    else cout << "0 ";
}

int main() {
    freopen("nimg.in", "r", stdin);
    freopen("nimg.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n >> F;
    init();
    for(int i = 1; i <= n; ++i) {
        solve();
    }
}