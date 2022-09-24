#include<bits/stdc++.h>
#define ll long long
//#define int long long
#define db double
#define ld long double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
#define dbg3(x) cerr<<#x<<"\n"
using namespace std;
#define reg register
#define inf 0x3f3f3f3f
#define infL 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define REP(i,a,b) for(int i=(a),i##_end_=(b);i<i##_end_;++i)
#define DREP(i,a,b) for(int i=(a),i##_end_=(b);i>i##_end_;--i)
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define FOr(i,a,b) for(int i=(a);i>=(b);--i)
#define y1 y11111111111
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define mod 998244353
inline int qpow(int x,ll y,int m=mod){int r=1;for(;y;y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;return r;}
inline int Add(int x, int y){return (x + y) % mod;}
inline int Mul(int x, int y){return 1ll * x * y % mod;}
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}
#define reg register

const int MN=2e5+5,MM=2e5+5;

int in[MN];
int n,m;

struct LCT{
    int c[MN][2],fa[MN],w[MN],X[MN],st[MN],N,a[MN],b[MN];
    bool rev[MN];
    long long mst;
    bool nrt(int x){return c[fa[x]][0]==x||c[fa[x]][1]==x;}
    void Rev(int x){rev[x]^=1;std::swap(c[x][0],c[x][1]);}
    bool get(int x){return c[fa[x]][1]==x;}
    void up(int x)
    {
        X[x]=x;
        if(w[X[c[x][0]]]>w[X[x]]) X[x]=X[c[x][0]];
        if(w[X[c[x][1]]]>w[X[x]]) X[x]=X[c[x][1]];
    }
    inline void down(int x){if(x&&rev[x])Rev(c[x][0]),Rev(c[x][1]),rev[x]=0;}
    void rtt(int x)
    {
        int y=fa[x],z=fa[y],l=get(x),r=l^1;if(nrt(y))c[z][get(y)]=x;fa[x]=z;
        c[y][l]=c[x][r];fa[c[x][r]]=y;c[x][r]=y;fa[y]=x;up(y);
    }
    void Splay(int x)
    {
        int i,top;st[top=1]=x;
        for(i=x;nrt(i);i=fa[i])st[++top]=fa[i];
        for(;top>0;--top)down(st[top]);
        for(;nrt(x);rtt(x))
            if(nrt(fa[x])) rtt(get(x)^get(fa[x])?x:fa[x]);
        up(x);
    }
    void acs(int x){for(int i=0;x;x=fa[i=x])Splay(x),c[x][1]=i,up(x);}
    void mkrt(int x){acs(x);Splay(x);Rev(x);}
    int fdrt(int x){acs(x);Splay(x);for(;c[x][0];down(c[x][0]),x=c[x][0]);Splay(x);return x;}
    void link(int x,int y){mkrt(x);fa[x]=y;}
    void cut(int x,int y){mkrt(x);acs(y);Splay(y);c[y][0]=fa[x]=0,up(y);}
	void ins(int x,int y,int B,int _)
    {
    	w[_]=B;a[_]=x;b[_]=y;
        mkrt(x);
        if(fdrt(y)^x){in[_-n]=1;link(a[_],_);link(b[_],_);mst+=w[_];return;}
        mkrt(x);acs(y);Splay(y);
        if(B>=w[X[y]]) {in[_-n]=0;return;}
        in[_-n]=1;
//		S.erase(mkp(w[_],_-n));
        int t=X[y];cut(t,a[t]);cut(t,b[t]);mst-=w[t];
//        S.insert(mkp(w[t],t-n));
		in[t-n]=0;
        link(a[_],_);link(b[_],_);mst+=w[_];
    }
    bool del(int x,int y,int _)
    {
    	if(in[_-n]) {
			cut(_,a[_]),cut(_,b[_]);mst-=w[_];
//			S.insert(mkp(w[_],_-n));
			in[_-n]=0;
    		return 0;
		}
		else return 1;
	}
}lct;

struct edge{int u,v,b,id;}e[MM];
int ID[MM];
inline bool cmp(const edge&x,const edge&y){return x.b<y.b;}
int main()
{
	freopen("output.txt", "w", stdout);
     freopen("input.txt", "r", stdin);
    lct.N=n=read(),m=read();
    lct.N+=m;
    reg int i;
    for(i=1;i<=m;++i)
        e[i].u=read(),e[i].v=read(),e[i].b=read(),e[i].id=i;
    std::sort(e+1,e+m+1,cmp);
    for(i=1;i<=m;++i) {
    	ID[e[i].id]=i;
        lct.ins(e[i].u,e[i].v,e[i].b,i+n);
    }
    int t=read();
    while(t--) {
		int i=read();
		i=ID[i];
		e[i].b=read();
//		dbg1(i);
//		dbg1(e[i].u);
//		dbg1(e[i].v);
//		dbg2(e[i].b);
		if(lct.del(e[i].u,e[i].v,i+n)) {
			lct.ins(e[i].u,e[i].v,e[i].b,i+n);
		}
		else{
//			dbg2(lct.mst);
			for(i=1;i<=m;++i) {
				if(!in[i]) lct.ins(e[i].u,e[i].v,e[i].b,i+n);
			}
		}
		printf("%lld\n", lct.mst);
	}
    return 0;
}
/*
4 6
1 2 10
2 3 20
2 4 30
1 3 40
3 4 50
4 1 60
3
4 22
5 17
4 14

*/
