#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define all(x) x.begin(),x.end()

int solve(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if(!a)return 1;
	int t=abs(b-c)+d;
	return a+2*min(b,c)+min(a+1,t);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--)cout<<solve()<<'\n';
}