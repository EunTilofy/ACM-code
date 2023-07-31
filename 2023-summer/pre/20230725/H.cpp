#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long

ll f[2][100005];
ll v[1000005], ans[100005], len;

void solve(bool p, bool q, int I, int J, int l, int r, int jl, int jr) {
    // cerr << I << " " << J << " " << l << " " << r << " " << jl << " " << jr << "\n";
    int mid = (l + r) >>1;
    int jc=min(jr,mid);
    for(int i = jl; i <= mid && i <= jr; ++i) {
        if(i+len<mid) continue;
        if(f[p][J+I*i]+v[mid-i] > f[q][J+I*mid]) {
            jc = i;
            f[q][J+I*mid]=f[p][J+I*i]+v[mid-i];
        }
    }
    if(l<mid) solve(p,q,I,J,l,mid-1,jl,jc);
    if(mid<r) solve(p,q,I,J,mid+1,r,jc,jr);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, K;
    cin >> n >> K;
    vector<vector<ll>> V(301);
    for(int i = 1; i <= n; ++i) {
        int w, v;
        cin >> w >> v;
        V[w].push_back(v);
    }
    for(auto &o : V) {
        sort(o.begin(),o.end());
        reverse(o.begin(),o.end());
    }
    for(int i = 0; i <= K; ++i) {
        f[0][i]=f[1][i]=-1e15;
    }
    f[0][0]=0;
    bool p=0,q=1;
    for(int i = 1; i <= 300; ++i) if(V[i].size()) {
        for(int j=0;j<=V[i].size();++j)v[j+1]=v[j]+V[i][j];
        len = V[i].size();
        for(int j=0;j<=K;++j) f[q][j]=-1e15;
        // f[q][0]=f[p][0]=0;
        for(int j=0;j<i;++j)solve(p,q,i,j,0,(K-j)/i,0,(K-j)/i);
        p^=1,q^=1;
    }
    for(int i = 1; i <= K; ++i) ans[i] = max(f[p][i], ans[i-1]);
    for(int i = 1; i <= K; ++i) cout << ans[i] << " ";
    return 0;
}