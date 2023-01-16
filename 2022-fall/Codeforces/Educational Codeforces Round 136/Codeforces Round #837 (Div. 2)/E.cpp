#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define all(x) x.begin(),x.end()

const int N=403;
int n,m;
string a[N];
int u[N][N][2],l[N][N][2];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i],a[i]=' '+a[i];
	for(int j=1;j<=m;++j){
		for(int i=1;i<=n;++i){
			if(a[i][j]=='#')
				u[i][j][0]=u[i][j][1]=0;
			else if(a[i][j]=='m'){
				u[i][j][0]=0;
				u[i][j][1]=u[i-1][j][0]+1;
			}
			else{
				u[i][j][0]=u[i-1][j][0]+1;
				u[i][j][1]=u[i-1][j][1]+1;
			}
		}
	}
/*	for(int i=1;i<=n;++i,cout<<'\n')
		for(int j=1;j<=m;++j)
			cout<<u[i][j][0]<<' ';
	for(int i=1;i<=n;++i,cout<<'\n')
		for(int j=1;j<=m;++j)
			cout<<u[i][j][1]<<' ';*/
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(a[i][j]=='#')
				l[i][j][0]=l[i][j][1]=0;
			else if(a[i][j]=='m'){
				l[i][j][0]=0;
				l[i][j][1]=l[i][j-1][0]+1;
			}
			else{
				l[i][j][0]=l[i][j-1][0]+1;
				l[i][j][1]=l[i][j-1][1]+1;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=m;++i){
		for(int j=i+2;j<=m;++j){
			int cnt=0;
			for(int k=3,o=2;k<=n;++k){
				int t=min(u[k][i][0],u[k][j][0]);
				while(o<=k-t+1){
					if(l[o][j-1][1]>=j-i-1)--cnt;
					++o;
				}
				if(l[k-1][j-1][1]>=j-i-1)++cnt;
				//cout<<i<<' '<<j<<' '<<k<<' '<<k-t+1<<' '<<cnt<<'\n';
				if(cnt>=1)ans=max(ans,2*t+j-i-1);
			}
		}
	}
	for(int i=1;i<=m;++i){
		for(int j=i+2;j<=m;++j){
			int cnt=0;
			for(int k=3,o=2;k<=n;++k){
				int t=max(min(u[k][i][0],u[k][j][1]),min(u[k][i][1],u[k][j][0]));
				while(o<=k-t+1){
					if(l[o][j-1][0]>=j-i-1)--cnt;
					++o;
				}
				if(l[k-1][j-1][0]>=j-i-1)++cnt;
				//cout<<i<<' '<<j<<' '<<k<<' '<<k-t+1<<' '<<cnt<<'\n';
				if(cnt>=1)ans=max(ans,2*t+j-i-1);
			}
		}
	}
	cout<<ans<<'\n';
}