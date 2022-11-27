#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define all(x) x.begin(),x.end()

bool solve(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int& x:a)cin>>x;
	int i=min_element(all(a))-a.begin();
	for(int j=i-1;j>=0;--j)if(j<n-1&&a[j]<a[j+1])return 0;
	for(int j=i+1;j<n;++j)if(j>0&&a[j]<a[j-1])return 0;
	return 1;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--)cout<<(solve()?"YES":"NO")<<'\n';
}