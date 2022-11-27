#include<bits/stdc++.h>
using namespace std;
#define M 30
int n,i,j,a[M],b[M];
char s[M];
string ans,now;
bool fl;
bool dfs(int x) {
	if(x==n+1) {
		now="";
		for(int j=i; j>0; j--)now+=('0'+b[j]);
//		printf("%d ",i);
//		cout<<now<<endl;
		if(!fl||now<ans)ans=now,fl=1;
		return 1;
	}
//	printf("%d %d\n",x,b[x-1]);
	if(x>i) {
		int res=0;
		for(int j=1,k=x; j<=x; j++,k--)
			if(j<=i&&k<=i)res=(res+(b[j]*b[k])%10)%10;
//		printf("!%d %d %d %d\n",res,a[x],b[1],b[2]);
		if(res==a[x])return dfs(x+1);
		else return 0;
	} else {
		int f=0;
		for(int i=0; i<=9; i++) {
			int res=0;
			b[x]=i;
			for(int j=1,k=x; j<=x; j++,k--)
				res=(res+(b[j]*b[k])%10)%10;
			if(res==a[x])f|=dfs(x+1);
		}
		return f;
	}
}
int main() {
	scanf("%s",s+1),n=strlen(s+1);
	for(i=1; i<=n; i++)a[i]=s[n-i+1]-'0';
	i=n+1>>1;
//	for(i=1; i<=n; i++) {
	if(dfs(1)) {
		cout<<ans;
		return 0;
	}
//	}
	printf("-1\n");
	return 0;
}