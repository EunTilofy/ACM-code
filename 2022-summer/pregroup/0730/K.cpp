#include<bits/stdc++.h>
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
#define dbg3(x) cerr<<#x<<"\n"
using namespace std;
#define reg register
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define mod 998244353
inline int qpow(int x,ll y,int m=mod){int r=1;for(;y;y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;return r;}
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}

#define REP(i,a,b) for(int i=(a),i##_end_=(b);i<i##_end_;++i)
#define DREP(i,a,b) for(int i=(a),i##_end_=(b);i>i##_end_;--i)
#define M 5333
#define N 53
#define MM 1000003

int T,n,m,nn,mm,nm;
char MP[N][N];
int Head[M],V[MM],Fl[MM],Next[MM],tot;
ll W[M],Dis[M];

void Add_Edge(int u,int v,ll w,int f){
	Next[++tot]=Head[u],V[Head[u]=tot]=v,W[tot]=w,Fl[tot]=f;
}
void PAdd_Edge(int u,int v,ll w,int f){
	//cerr<<u<<','<<v<<','<<w<<','<<f<<endl;
	Add_Edge(u,v,w,f);
	Add_Edge(v,u,-w,0);
}
int s,t;
int Val[N][N],Cost[N][N];

int Xp[]={0,1,0,-1};
int Yp[]={1,0,-1,0};
int Dir[256];

#define ND(x,y) ((x)*m+(y))

int GetNext(int x,int y,int p){
	x+=Xp[p],y+=Yp[p];
	while(x>=0 && y>=0 && x<n && y<m){
		//cerr<<x<<','<<y<<','<<MP[x][y]<<endl;
		if(MP[x][y]=='#')return -1;
		if((MP[x][y]<'A' || MP[x][y]>'Z') && MP[x][y]!='.')return ND(x,y);
		x+=Xp[p],y+=Yp[p];
	}
	return -1;
}

int Q[M];
bool Vis[M];
bool SPFA(){
	memset(Dis,0x3f,sizeof(Dis));
	memset(Vis,0,sizeof(Vis));
	
	Dis[s]=0;
	int l=0,r=0;
	
	Q[r++]=s,Vis[s]=1;
	
	while(l!=r){
		int x=Q[l++];if(l==M)l=0;
		Vis[x]=0;
		for(int i=Head[x];i;i=Next[i])if(Fl[i]){
			int y=V[i];
			if(Dis[y]>Dis[x]+W[i]){
				Dis[y]=Dis[x]+W[i];
				if(!Vis[y]){
					Q[r++]=y,Vis[y]=1;
					if(r==M)r=0;
				}
			}
		}
	}
	
	return Dis[t]!=0x3f3f3f3f3f3f3f3f;
}
int Dinic(int x,int f){
	int fs=0;
//	cerr<<"***"<<x<<','<<f<<endl;
	if(x==t)return f;
	Vis[x]=1;
	for(int i=Head[x];i;i=Next[i])if(Fl[i] && Dis[x]+W[i]==Dis[V[i]] && !Vis[V[i]]){
		int fl=Dinic(V[i],min(f,Fl[i]));
		if(!fl)continue;
		Fl[i]-=fl;
		Fl[i^1]+=fl;
		fs+=fl,f-=fl;
		if(!f)return fs;
	}
	Vis[x]=0;
	return fs;
}
ll Work(){
	ll Ans=0;
	while(SPFA()){
		if(Dis[t]>=0)return Ans;
		//cerr<<Dis[t]<<endl;
		memset(Vis,0,sizeof(Vis));
		Ans+=Dis[t]*Dinic(s,0x3f3f3f3f);
	}
	return -Ans;
}

int main()
{
	Dir['R']=0;
	Dir['D']=1;
	Dir['L']=2;
	Dir['U']=3;
	Dir['>']=0;
	Dir['v']=1;
	Dir['<']=2;
	Dir['^']=3;
	
	T=read();
	while(T--){
		memset(Head,0,sizeof(Head));
		memset(MP,0,sizeof(MP));
		tot=1;
		
		n=read(),m=read(),nn=read(),mm=read();
		nm=n*m;
		
		REP(i,0,n)scanf("%s",MP[i]);
		
		s=2*nm,t=2*nm+1;
		
		//cerr<<"::"<<s<<','<<t<<endl;
		
		REP(i,0,nn){
			int x=read()-1,y=read()-1;
			Val[x][y]=read();
		}
		REP(i,0,mm){
			int x=read()-1,y=read()-1;
			Cost[x][y]=read();
		}
		
		REP(i,0,n)REP(j,0,m){
			if(MP[i][j]=='x')
				PAdd_Edge(ND(i,j),t,-Val[i][j],1);	
				
			else if('A'<=MP[i][j] && MP[i][j]<='Z'){
				PAdd_Edge(s,ND(i,j),0,1);
				int nt=GetNext(i,j,Dir[MP[i][j]]);
				//cerr<<i<<','<<j<<':'<<Dir[MP[i][j]]<<','<<nt<<endl;
				if(nt!=-1)
					PAdd_Edge(ND(i,j),nt,0,1);
			}
			else if(MP[i][j]!='#' && MP[i][j]!='.'){
				PAdd_Edge(ND(i,j),ND(i,j)+nm,0,1);				
				
				int p=Dir[MP[i][j]];
				ll c=0;
			//	cerr<<i<<','<<j<<','<<Cost[i][j]<<endl;
				
				REP(_,0,4){
					int nt=GetNext(i,j,p);
					if(nt!=-1)PAdd_Edge(ND(i,j)+nm,nt,c,1);
					
					c+=Cost[i][j];
					p=(p+1)&3;
				}
			}
		}
		
		printf("%lld\n",Work());
	}
	return 0;
}
