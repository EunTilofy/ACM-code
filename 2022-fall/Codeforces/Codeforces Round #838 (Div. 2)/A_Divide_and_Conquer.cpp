#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define all(x) x.begin(),x.end()

void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    int sm=0;
    int nm=100;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        sm^=(a[i]&1);
        int j=1;
        while((a[i]&1)==((a[i]/2)&1)) a[i]/=2,++j;
        nm=min(nm,j);
    }
    if(sm) cout<<nm<<endl;
    else cout<<0<<endl;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
}