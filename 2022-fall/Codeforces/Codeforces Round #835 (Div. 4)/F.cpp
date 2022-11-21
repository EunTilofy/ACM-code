#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define all(x) x.begin(),x.end()

void solve(){
	int n,d;
	ll c;
	cin>>n>>c>>d;
	vector<ll> a(n);
	for(ll& x:a)cin>>x;
	sort(all(a)),reverse(all(a));
	int l=1,r=d+2,mid,ans=0;
	while(l<=r){
		mid=(l+r)>>1;
		ll s=0;
		for(int i=0;i<min(n,mid);++i)s+=a[i]*((d+mid-i-1)/mid);
		if(s>=c)ans=mid,l=mid+1;
		else r=mid-1;
	}
	if(ans==0)cout<<"Impossible\n";
	else if(ans==d+2)cout<<"Infinity\n";
	else cout<<ans-1<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
}