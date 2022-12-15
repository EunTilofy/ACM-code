#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define all(x) x.begin(),x.end()
#define int long long
#define MN 300005

int a[MN],n;

void solve(){
	cin>>n;
	for(int i=1;i<=n;++i) cin>>a[i];
	long long ans=0;
	// long long num01=0;
	long long num0=0;
	for(int i=1;i<=n;++i){
		if(a[i]==0) ans+=1ll*(n-i+1)*i;
	}
	for(int i=1;i<=n;++i){
		if(a[i]==0){
			int j=i;
			while(j+1<=n&&a[j+1]==0)++j;
			num0+=1ll*(j-i+1)*(j-i)/2+(j-i+1);
			// num01+=1ll*(j-i+1)*(j-i)/2;
			i=j;
		}
	}
	int b=-1;
	vector<int> q;
	vector<pair<int,int>> p;
	vector<pair<int,int>> t1,t2;
	for(int i=1;i<=n;++i){
		if(a[i]!=b&&a[i]!=0) {
			q.push_back(i);b=a[i];
			if(q.size()>=3){
				int sz=q.size();
				int x1=q[sz-1],x2=q[sz-2],x3=q[sz-3];
				if(a[x3]==3&&a[x2]==2&&a[x1]==1) t1.push_back({x3,i});
				if(a[x3]==3&&a[x2]==1&&a[x1]==2) t2.push_back({x3,i});
			}
			if(q.size()>=2){
				int sz=q.size();
				int x1=q[sz-1],x2=q[sz-2];
				if(a[x1]==2&&a[x2]==1) p.push_back({x2,i});
				if(a[x1]==1&&a[x2]==2) p.push_back({x2,i});
			}
		}
		else if(a[i]==b){
			q.back()=i;
		}
	}
	// cerr<<"xxxx"<<endl;
	int ans1=0;
	int last=0,lastr=1;
	for(auto o: p){
		int left=o.first;
		int right=o.second;
		ans1+=1ll*(left-last)*(n-right+1);
		if(a[left]==2){
			if(lower_bound(all(t2),make_pair(right+1,right+1))!=t2.end()){
				pair<int,int> o=*lower_bound(all(t2),make_pair(right+1,right+1));
				ans=ans+1ll*(left-last)*(n-o.second+1);
			}
		}
		else {
			if(lower_bound(all(t1),make_pair(right+1,right+1))!=t1.end()){
				pair<int,int> o=*lower_bound(t1.begin(),t1.end(),make_pair(right+1,right+1));
				ans=ans+1ll*(left-last)*(n-o.second+1);
			}
		}
		last=left;lastr=right;
	}
	cout<<ans+ans1+1ll*(n-1)*n/2+n-num0<<endl;
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T=1;
	while(T--) solve();
}