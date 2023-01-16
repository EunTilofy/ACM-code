#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define all(x) x.begin(),x.end()

bool solve(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	map<string,int> vis;
	for(int i=0;i<n-1;++i){
		if(vis.count(s.substr(i,2))){
			if(vis[s.substr(i,2)]!=i-1)return 1;
		}
		else vis[s.substr(i,2)]=i;
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--)cout<<(solve()?"YES":"NO")<<'\n';
}