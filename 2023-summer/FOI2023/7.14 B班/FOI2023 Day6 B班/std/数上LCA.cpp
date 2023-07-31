#include<bits/stdc++.h>
using namespace std;

const int N=1e7+3;
bool np[N];
int p[N],pri[N/10],cnt;
void init(int n){
	for(int i=2;i<=n;++i){
		if(!np[i])pri[++cnt]=i,p[i]=i;
		for(int j=1;j<=cnt&&i*pri[j]<=n;++j){
			p[i*pri[j]]=pri[j];
			np[i*pri[j]]=1;
			if(!(i%pri[j]))break;
		}
	}
}
void solve(){
	int x,y;
	cin>>x>>y;
	while(x!=y){
		if(x<y)swap(x,y);
		x/=p[x];
	}
	cout<<x<<'\n';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	init(1e7);
	int T;
	cin>>T;
	while(T--)solve();
}