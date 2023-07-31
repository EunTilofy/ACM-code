#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e7+10,mod=998244353;
inline int inc(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int dec(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return (ll)x*y%mod;}
inline int qpow(int x,int y){
	int r=1;
	for(;y;y>>=1){
		if(y&1)r=mul(r,x);
		x=mul(x,x);
	}return r;
}
inline int inv(int x){return qpow(x,mod-2);}

int fac[N],inf[N];
void init(int n){
	fac[0]=1;
	for(int i=1;i<=n;++i)fac[i]=mul(fac[i-1],i);
	inf[n]=inv(fac[n]);
	for(int i=n-1;~i;--i)inf[i]=mul(inf[i+1],i+1);
}

inline int C(int n,int m){
	if(n<m||m<0)return 0;
	return mul(fac[n],mul(inf[m],inf[n-m]));
}

int n,m,a,b,c,x,y,ans=0;
int main(){
	cin>>n>>m>>a>>b>>c>>x>>y;
	init(n);
	for(int i=0;i<=a;++i)
		ans=inc(ans,mul(C(a,i),mul(C(c,x-i),C(b+c-x+i,y))));
	cout<<mul(ans,C(n-x-y,m-x-y));
}