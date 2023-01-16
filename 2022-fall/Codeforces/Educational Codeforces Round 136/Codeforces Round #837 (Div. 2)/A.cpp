#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define all(x) x.begin(),x.end()

ll solve(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int &x:a)cin>>x;
	int mx=*max_element(all(a)),mn=*min_element(all(a));
	if(mx==mn)return 1ll*n*(n-1);
	int c1=0,c2=0;
	for(int x:a)if(x==mx)++c1;else if(x==mn)++c2;
	return 2ll*c1*c2;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--)cout<<solve()<<'\n';
}