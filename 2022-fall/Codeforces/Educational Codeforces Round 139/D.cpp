#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define all(x) x.begin(),x.end()

const int N=1e7+3;
bool np[N];
int pri[N/10],cnt=0,p[N];
void sieve(int n){
	for(int i=2;i<=n;++i){
		if(!np[i])pri[++cnt]=i,p[i]=i;
		for(int j=1;j<=cnt&&i*pri[j]<=n;++j){
			np[i*pri[j]]=i;
			p[i*pri[j]]=pri[j];
			if(!(i%pri[j]))break;
		}
	}
}

inline int calc(int x,int p){
	return p-x%p;
}

int solve(){
	int x,y;
	cin>>x>>y;
	if(__gcd(x,y)>1)return 0;
	int d=abs(x-y);
	if(d==1)return -1;
	int ans=1e9;
	while(d>1){
		ans=min(ans,min(calc(x,p[d]),calc(y,p[d])));
		d/=p[d];
	}
	return ans;
}

int main(){
	sieve(1e7);
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--)cout<<solve()<<'\n';
}