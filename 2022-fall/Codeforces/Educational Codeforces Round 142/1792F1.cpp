#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define all(x) x.begin(),x.end()

const int N=5003,mod=998244353;
int n;
ll fac[N],inf[N];
void init(int n){
	fac[0]=1;
	for(int i=1;i<=n;++i)fac[i]=fac[i-1]*i%mod;
	inf[1]=1;
	for(int i=2;i<=n;++i)inf[i]=inf[mod%i]*(mod-mod/i)%mod;
	inf[0]=1;
	for(int i=1;i<=n;++i)inf[i]=inf[i-1]*inf[i]%mod;
}
inline ll C(int n,int m){
	return fac[n]*inf[m]%mod*inf[n-m]%mod;
}
ll f[N];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	init(n);
	f[1]=1,f[2]=1;
	for(int i=3;i<=n;++i){
		for(int j=1;j<i;++j)
			f[i]=(f[i]+f[j]*f[i-j]*(i-j==1?1:2)%mod*C(i-1,j-1))%mod;
	}
	cout<<(f[n]*2-2+mod)%mod<<'\n';
}