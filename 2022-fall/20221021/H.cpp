#include<bits/stdc++.h>
using namespace std;
int T,e,s[30][4],k[4],a[10005][4],si,i,j,h,sz,cnt[5],id;
bool mark[30];
char c[5][5];
void rdfs(int x) {
	if(x==4) {
		sz++;
		for(int i=0; i<4; i++)s[sz][i]=k[i];//printf("%d\n",sz);
		return;
	}
	for(int i=1; i<=4; i++)if(!mark[i])k[x]=i,mark[i]=1,rdfs(x+1),mark[i]=0;
}
void dfs(int x) {
	if(x==4) {
		for(int i=0; i<4; i++) {
			memset(cnt,0,sizeof(cnt));
			for(int j=0; j<4; j++)cnt[s[k[j]][i]]++;
			for(int j=1; j<=4; j++)if(!cnt[j])return;
		}
		for(int i=0; i<4; i+=2)
			for(int j=0; j<4; j+=2) {
				memset(cnt,0,sizeof(cnt));
				cnt[s[k[i]][j]]++;
				cnt[s[k[i]][j+1]]++;
				cnt[s[k[i+1]][j]]++;
				cnt[s[k[i+1]][j+1]]++;
				for(int j=1; j<=4; j++)if(!cnt[j])return;
			}
		si++;
		for(int i=0; i<4; i++)a[si][i]=k[i];
		return;
	}
	for(int i=1; i<=sz; i++)if(!mark[i])k[x]=i,mark[i]=1,dfs(x+1),mark[i]=0;
}
int main() {
	rdfs(0),dfs(0);//printf("%d %d\n",sz,si);
	scanf("%d",&T);
	for(e=1; e<=T; e++) {
		id=0;
		for(i=0; i<4; i++)scanf("%s",c[i]);
		for(i=1; i<=si&&!id; i++) {
			for(j=0; j<4; j++) {
				for(h=0; h<4; h++)
					if(c[j][h]!='*'&&c[j][h]!=s[a[i][j]][h]+'0')break;
				if(h<4)break;
			}
			if(j==4)id=i;
		}
		printf("Case #%d: \n",e);
		for(j=0; j<4; j++,puts(""))
			for(h=0; h<4; h++)printf("%d",s[a[id][j]][h]);
	}
	return 0;
}