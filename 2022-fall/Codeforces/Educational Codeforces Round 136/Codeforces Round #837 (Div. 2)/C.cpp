#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define all(x) x.begin(),x.end()

const int N=32003;
bool np[N];
int pri[N],cnt=0;
void init(int n){
	for(int i=2;i<=n;++i){
		if(!np[i])pri[++cnt]=i;
		for(int j=1;j<=cnt&&i*pri[j]<=n;++j){
			np[i*pri[j]]=1;
			if(!(i%pri[j]))break;
		}
	}
}

set<int> s;
bool o[3500];
bool solve(){
	int n,x;
	cin>>n;
	vector<int> a(n);
	memset(o,0,sizeof(o));
	for(int& x:a)cin>>x;
	s.clear();
	for(int x:a){
		for(int i=1;i<=cnt;++i)if(!(x%pri[i])){
			if(o[i])return 1;
			o[i]=1;
			x/=pri[i];
			while(!(x%pri[i]))x/=pri[i];
		}
		if(x>1){
			if(s.find(x)!=s.end())return 1;
			s.insert(x);
		}
	}
	return 0;
}

int main(){
	init(32000);
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--)cout<<(solve()?"YES":"NO")<<'\n';
}