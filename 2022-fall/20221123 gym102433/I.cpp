#include<bits/stdc++.h>
using namespace std;
int n,pd[505],deg[505];
string a[505],b;
map<string,int>pos;
int mk[505];
bool mark[505];
vector<int>e[505];
bool sp(int x) {
	for(int i=0; i<e[x].size(); i++) {
		int y=e[x][i];
		if(mark[y])continue;
		mark[y]=1;
		if(mk[y]==-1||sp(mk[y])) {
			mk[y]=x;
			return 1;
		}
	}
	return 0;
}
int match() {
	int ans=0;
	memset(mk,-1,sizeof(mk));
	for(int i=1; i<=n; i++) {
		if(!pd[i]) {
			memset(mark,0,sizeof(mark));
			if(sp(i))ans++;//,printf("%d ",i);
		}
//		if(!deg[i])ans++,printf("%d ",i);
	}
//	for(int i=1; i<=n; i++)printf("%d %d %d\n",i,pd[i],mk[i]);
	return n-ans;
}

int main() {
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		pos[a[i]]=i;
	}
	int l=a[1].size();
	for(int i = 1; i <= n; ++i) {
		for(int j = 0; j < l; ++j)
			for(int k = 0; k < j; ++k) {
				pd[i] ^= (a[i][j] < a[i][k]);
			}
	}
	for(int i=1; i<=n; i++)
		if(!pd[i]) {
			for(int j=0; j<l; j++)
				for(int k=j+1; k<l; k++) {
					b=a[i];
					swap(b[j],b[k]);
					if(pos.count(b)) {
						e[i].push_back(pos[b]),deg[i]++,deg[pos[b]]++;
//						printf("!!%d %d %d\n",i,pos[b],pd[pos[b]]);
					}
				}
		}
	printf("%d\n",match());
	return 0;
}