#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define all(x) x.begin(),x.end()

int solve(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	char ans=0;
	for(char x:s)ans=max(ans,x);
	return ans-'a'+1;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--)cout<<solve()<<'\n';
}