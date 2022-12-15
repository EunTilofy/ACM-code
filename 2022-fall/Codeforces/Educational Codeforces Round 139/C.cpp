#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define all(x) x.begin(),x.end()
#define MN 200005
string s[2];
bool a[2][MN];
void solve(){
	int n;cin>>n;
	cin>>s[0]>>s[1];
	a[0][0]=s[0][0]=='B';
	a[1][0]=s[1][0]=='B';
	for(int i=1;i<n;++i){
		if(s[0][i]=='B'&&s[1][i]=='B'){
			a[0][i]=a[1][i-1];
			a[1][i]=a[0][i-1];
		}
		else if(s[0][i]=='B'){
			a[1][i]=0;
			a[0][i]=a[0][i-1];
		}
		else {
			a[1][i]=a[1][i-1];
			a[0][i]=0;
		}
	}
	cout<<((a[1][n-1]|a[0][n-1])?"YES":"NO")<<endl;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
}