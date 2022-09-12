#include<bits/stdc++.h>
using namespace std;
#define M 1000001
int n,i,j,x,son[M][26],fa[M],Q[M],l,r,rt,tot,si,id[M],ans[M],mx;
char s[M],k[M];
bool mark[M];
void tree(int x,int &p) {
	if(!p)p=++tot;
	if(x==l) {
		id[i]=p;
		return;
	}
	tree(x+1,son[p][s[x]-'a']);
}
void ac() {
	l=r=0,fa[1]=1;
	for(i=0; i<26; i++)
		if(son[1][i])fa[son[1][i]]=1,Q[++r]=son[1][i];
		else son[1][i]=1;
	while(l<r) {
		x=Q[++l];
		for(i=0; i<26; i++)
			if(son[x][i])fa[son[x][i]]=son[fa[x]][i],Q[++r]=son[x][i];
			else son[x][i]=son[fa[x]][i];
	}
}
void query() {
	for(i=0; i<si; i++) {
		if(mark[i])x=1;
		x=son[x][k[i]-'a'],ans[x]++;
	}
	for(i=r; i>0; i--) {
		ans[fa[Q[i]]] = max(ans[fa[Q[i]]], ans[Q[i]] + 1);
	}
	for(i=1; i<=n; i++){
		mx=max(mx,ans[id[i]]);
//		printf("%d\n", ans[id[i]]);
	}
	printf("%d\n",mx);
}
int main() {
	scanf("%d",&n);
	for(i=1; i<=n; i++) {
		scanf("%s",s),l=strlen(s),tree(0,rt),mark[si]=1;
		for(j=0; j<l; j++)k[si++]=s[j];
	}
	ac(),query();
	return 0;
}
/*
5
abcdgs
bcd
cdgs
gs
cd
*/