#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define all(x) x.begin(),x.end()

void solve(){
	int n;
	cin>>n;
	vector<pii> a(n);
	for(int i=0;i<n;++i)cin>>a[i].first,a[i].second=i;
	sort(all(a));
	vector<int> b(n);
	for(int i=0;i<n;++i)b[a[i].second]=n-i;
	for(int i=0;i<n;++i)cout<<b[i]<<' ';
	cout<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
}