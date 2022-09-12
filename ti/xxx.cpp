#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<stack>
#define N 3010
using namespace std;

int T,n,m;
char s[N],ch[N][N];
int p[N][N],L[N][N];
int Lmax[N];
void Prion()
{
	for(int i=1;i<=m;i++)
	{
		printf("%c",43);
		for(int j=1;j<=Lmax[i];j++) printf("%c",45);
	}
	printf("%c",43);
}
void pri(int x,int k)
{
	int l = strlen(ch[x]+1);
	for(int i=k;i<=l;i++)
	{
		if(ch[x][i] == 44) return ;
		printf("%c",ch[x][i]);
	}
}
int GetChar(int x,int y)
{
	if(y == 1) return 1;
	int k = 1, l = strlen(ch[x]+1);
	for(int i=1;i<=l;i++)
	{
		if(ch[x][i] == 44) 
		{
			k++;
			if(k == y) return i+1;		
		}
	}
}
int GetLenh(int x,int y)
{
	int k = 0, l = strlen(ch[x]+1);
	for(int i=p[x][y];i<=l;i++)
	{
		if(ch[x][i] == 44) return k;
		k++;
	}
	return k;
}
int main()
{
	scanf("%d%d %s",&n,&m,s+1);
	for(int i=1;i<=n;i++) scanf(" %s",ch[i]+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			p[i][j] = GetChar(i,j);
			L[i][j] = GetLenh(i,j);
			Lmax[j] = max(Lmax[j],L[i][j]);
		}
	}
	int l = 0,k = 0;
	for(int i=1;i<=n;i++)
	{
		Prion(); printf("\n");
		l = 0;
		for(int j=1;j<=m;j++)
		{
			printf("%c",124);
			l = Lmax[j]-L[i][j];
			if(s[j] == 'L') 
			{
				pri(i,p[i][j]);
				for(k=1;k<=l;k++) printf(" ");
			}
			else if(s[j] == 'R')
			{
				for(k=1;k<=l;k++) printf(" ");
				pri(i,p[i][j]);
			}
			else if(s[j] == 'C')
			{
				for(k=1;k<=l/2;k++) printf(" ");
				pri(i,p[i][j]);
				for(k=1;k<=(l+1)/2;k++) printf(" ");
			}
		}
		printf("%c\n",124);
	}
	Prion();
	return 0;
 }



