#include<bits/stdc++.h>
using namespace std;

const int MN = 2e5+5;

int c[MN][26],step[MN],val[MN],fa[MN],siz[MN],v[MN],rk[MN];
int last,cnt,n;
int par[MN][19], tmp[MN];
inline void init()
{
	last=cnt=1;memset(c,0,sizeof c);
	int i;
	for(i=1;i<n<<1;++i) val[i]=step[i]=fa[i]=0;
}

void Insert(int x)
{
	int p=last,np=++cnt;step[np]=step[p]+1;val[np]=1;
    tmp[step[np]]=np;
    for(;p&&!c[p][x];p=fa[p]) c[p][x]=np;
    if(!p) fa[np]=1;
    else 
    {
        int q=c[p][x];
	    if(step[q]==step[p]+1) fa[np]=q;
        else 
        {
        	int nq=++cnt;step[nq]=step[p]+1;
        	memcpy(c[nq],c[q],sizeof c[q]);
            fa[nq]=fa[q];fa[np]=fa[q]=nq;
        	for(;c[p][x]==q;p=fa[p]) c[p][x]=nq;
        }    
    }
    last=np;
}
inline void work()
{
	int i;
	for(i=1;i<=cnt;++i) ++v[step[i]];
    for(i=1;i<=n;++i) v[i]+=v[i-1];
    for(i=1;i<=cnt;++i) rk[v[step[i]]--]=i;
	for(i=cnt;i;--i) val[fa[rk[i]]]+=val[rk[i]],siz[rk[i]]=val[rk[i]];
	val[1]=siz[1]=0;
}
char s[MN],ans[MN];int len;
inline void dfs(int x,int k)
{
	if(k<=val[x]) return;k-=val[x];
    int i;
	for(i=0;i<26;++i)
        if(k>siz[c[x][i]]) k-=siz[c[x][i]];
        else {ans[len++]=i+'a',dfs(c[x][i],k);break;}
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    string s;
    cin >>s;
    init();
    for(int i = 0; i < s.size(); ++i) Insert(s[i]-'A'+1);

    for(int i = 1; i <= cnt; ++i) par[i][0]=fa[i];
    for(int j = 1; j < 19; ++j)
        for(int i = 1; i <= cnt; ++i) {
            par[i][j] = par[par[i][j-1]][j-1];
        }

    int q;
    cin >> q;
    for(int i = 1; i <= q; ++i) {
        int l, r;
        cin >> l >> r;
        int x = tmp[r];
        for(int j = 18; ~j; --j) {
            if(step[par[x][j]] >= r-l+1) x = par[x][j];
        }
        
    }

    return 0;
}