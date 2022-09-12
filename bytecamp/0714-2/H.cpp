#include<bits/stdc++.h>
using namespace std;
#define M 55
int n,m,i,j,cnt,res,f,si,b[M][M],l,r;
char a[M][M];
bool markn[M],markm[M],mkn[M],mkm[M];
struct node {
	int x,y;
} ans[M*M];
void solve(int x,int y) {
	memset(markn,0,sizeof(markn)),memset(markm,0,sizeof(markm));
	memset(mkn,0,sizeof(mkn)),memset(mkm,0,sizeof(mkm)),si=0;
	int i,j;
	markn[x]=markm[y]=1,l=r=0;
	for(i=1; i<=n; i++)if(!(b[i][y]&1))markn[i]=1,l++;
	for(i=1; i<=m; i++)if(!(b[x][i]&1))markm[i]=1,r++;
	if(l!=r)return;
//	printf("%d %d\n",x,y);
	for(i=1; i<=n; i++) {
		for(j=1; j<=m; j++) {
			r=markn[i]+markm[j];
//			if(x==2&&y==2)
//			printf("%d %d %d %d\n",i,j,markn[i],markm[j]);
			if(r==1&&a[i][j]=='W')return;
			if(r==0&&a[i][j]=='B')return;
			if(r==2&&a[i][j]=='B') {
				if(mkn[i]||mkm[j])return;
				mkn[i]=mkm[j]=1,ans[++si]=(node) {
					i,j
				};
			}
		}
	}
	if(si!=l+1)return;
	printf("Yes\n"),f=1;
	printf("%d\n",si);
	for(i=1; i<=si; i++)printf("%d %d\n",ans[i].x,ans[i].y);
}
int main() {
	scanf("%d%d",&n,&m);
	for(i=1; i<=n; i++) {
		scanf("%s",a[i]+1);
		for(j=1; j<=m; j++)if(a[i][j]=='B')res++,b[i][j]=1;
	}
	if(!res){
		printf("Yes\n");
		printf("0\n");
		return 0;
	}
	for(i=1; i<=n&&!f; i++)
		for(j=1; j<=m&&!f; j++)if(a[i][j]=='B')solve(i,j);
	if(!f)printf("No\n");
	return 0;
}
/**/
