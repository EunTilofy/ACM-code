#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define all(x) x.begin(),x.end()

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> a(n*2+2);
    for(int i=0;i<n;++i) {
        a[i*2+1]=s[i]=='1';
    }
    for(int i=2;i<n*2-1;i+=2){
        if(a[i-1]!=a[i+1]) a[i]=a[i+1];
        else a[i]=-1;
    }
    int ans=1;
    int mod=998244353;
    int p=1;
    for(int i=2;i<n*2-1;i+=2){
        if(a[i]==-1){
            p=p*2%mod;
        }
        else p=1;
        ans=(ans+p)%mod;
    }
    cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
}