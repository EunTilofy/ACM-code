#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define all(x) x.begin(),x.end()
 
void solve(){
	int n;
	cin>>n;
	// if(n<=10) cout<<n;
	int ans=0;
	for(int i=1;i<=9;++i){
		int j=i;
		while(j<=n){++ans;j=j*10;}
	}
	cout<<ans<<endl;
}
 
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
}