#include<bits/stdc++.h>
using namespace std;
#define P 1000000007
char a[55],b[55];
int l1,l2,i,ans,res;
map<__int128,bool>pos[55][55];
void dfs(int x,int y,__int128 now) {
	if(pos[x][y][now])return;
	pos[x][y][now]=1;
	if(x==l1/2&&y==l2/2) {
		res++;
		return;
	}
	if(x<l1/2)dfs(x+1,y,now*2+a[x+1]-'0');
	if(y<l2/2)dfs(x,y+1,now*2+b[y+1]-'0');
}
void rdfs(int x,int y,__int128 now) {
	if(pos[x][y][now])return;
	pos[x][y][now]=1;
	if(x==l1&&y==l2) {
		res++;
		return;
	}
	if(x<l1)dfs(x+1,y,now*2+a[x+1]-'0');
	if(y<l2)dfs(x,y+1,now*2+b[y+1]-'0');
}
int main() {
	scanf("%s%s",a+1,b+1),l1=strlen(a+1),l2=strlen(b+1);
	res=0,rdfs(0,0,0),ans=res;
	res=0,dfs(l1/2,l2/2,0),ans=1ll*res*ans%P;
	printf("%d\n",ans);
	return 0;
}