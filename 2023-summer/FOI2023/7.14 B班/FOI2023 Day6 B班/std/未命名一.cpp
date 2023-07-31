#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e7+3,M=220;
int n,m,q,s[N],c[N],p[N];
ll op[N],now,ans;
bool np[N],vis[N];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=1,c;(c=i*i*i)<=n;++i)
		for(int j=1;c*j<=n;++j)s[c*j]=j;
	for(int i=2;i*i<=n;++i)if(!np[i])
		for(int j=i*i;j<=n;j+=i)if(!np[j])
			p[j]=i,np[j]=1;
	for(int i=2;i<=n;++i)if(s[i]==i&&!op[i]){
		if(!np[i])op[i]=1ll*i*i;
		else if((i/p[i])%p[i])op[i]=op[i/p[i]]*p[i]*p[i];
		else op[i]=op[i/p[i]]/p[i];
		if(op[i]<=n)op[op[i]]=i;
	}
	now=1,ans=1;
	for(int i=2;i<=n;++i){
		if(s[i]!=1){
			int o=s[i];
			if(op[o]>n)++now;
			else{
				++c[o];
				if(c[o]>c[op[o]]){
					if(!vis[o])vis[o]=1,vis[op[o]]=0;
					++now;
				}
			}
		}
		ans^=(1ll*i*now);
	}
	cout<<ans<<'\n';
}