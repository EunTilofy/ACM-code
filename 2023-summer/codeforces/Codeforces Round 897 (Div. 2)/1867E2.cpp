#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define all(x) x.begin(),x.end()

const int N=1e5+3;
int qry(int x){
	cout<<"? "<<x<<endl;
	fflush(stdout);
	int res;
	cin>>res;
	return res;
}

int n,k,a[N],d[N];
void solve(){
	cin>>n>>k;
	if(n%k==0){
		int ans=0;
		for(int i=1;i<=n;i+=k)ans^=qry(i);
		cout<<"! "<<ans<<endl;
		fflush(stdout);
	}
	else{
		int ans=0,x=n%k;
		for(int i=1;i<=n-k-x;i+=k)ans^=qry(i);
		int l=n-k-x+1,r=n;
		ans^=qry(l);
		qry(l);
//		qry(r-k+1);
//		qry(r-k+1);
		int mid=(l+r)/2-k/2+1;
		ans^=qry(mid);
		ans^=qry(r-k+1);
		cout<<"! "<<ans<<endl;
		fflush(stdout);
	}
}

int main(){
//	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
}