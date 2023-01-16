#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define all(x) x.begin(),x.end()

const int MN = 2e5+5;
int a[MN];
int mi[MN],mk[MN],pr[MN], tot;

void init() {
	mi[1]=1;
	for(int i=2;i<MN;++i){
		if(!mk[i]){pr[++tot]=i;mi[i]=i;}
		for(int j=1;j<=tot&&1ll*pr[j]*i<MN;++j){
			mk[pr[j]*i]=1;
			mi[pr[j]*i]=pr[j];
			if(i%pr[j]==0)break;
		}
	}
}

void solve(){
	int n, m;
	cin>>n>>m;
	if(n % m != 0) {cout<<"-1"<<endl;return;}
	for(int i = 1; i <= n; ++i) a[i] = i;
	if(m != 1) {
		if(m == n) swap(a[1], a[n]);
		else {
			swap(a[1], a[n]);
			swap(a[m], a[1]);
			// cout<<"ddd"<<endl;
			// for(int i = 1; i <= n; ++i) cout<<a[i]<<" ";
			// cout<<endl<<"ddd"<<endl;
			int fr = m, to = n;
			while(fr != to) {
				int now=fr;
				fr=mi[to/now]*now;
				// cout<<fr<<" "<<now<<endl;
				if(fr!=to) swap(a[fr],a[now]);
				else {a[now]=n;break;}
			}
		}
	}
	for(int i = 1; i <= n; ++i) cout<<a[i]<<" ";
	cout<<endl;
}

int main(){
	init();
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
}