#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
template<class T> bool cmin(T &x,const T &y) { if (y<x) { x=y; return 1; }return 0; }
template<class T> bool cmax(T &x,const T &y) { if (x<y) { x=y; return 1; }return 0; }
const int N=2e5+5;
int a[N],len[N];
int f[N][3][3],opp[N][3][3],op[N],pre[N][3][3];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n,i,j,k,x,y,z;
	cin>>n;
	for (i=1; i<=n; i++) cin>>a[i];
	sort(a+1,a+n+1);
	for (i=1; i<=n; i++) len[i]=to_string(a[i]).size();
	memset(f,0x3f,sizeof f);
	memset(op,-1,sizeof op);
	f[0][0][0]=0;
	for (i=1; i<=n; i++)
	{
		auto update=[&](int x,int y,int z,int d,int O)
			{
				if (cmin(f[i][x][y],f[i-1][y][z]+d))
				{
					pre[i][x][y]=z;
					opp[i][x][y]=O;
				}
			};
		update(0,0,0,len[i]+1,0);
		update(0,0,1,len[i]+1,0);
		update(0,0,2,len[i]+1,0);

		update(0,1,0,len[i]+1,0);
		update(0,1,1,len[i]+1,0);
		update(0,1,2,len[i]+1,0);

		update(0,2,0,len[i]+1,0);
		update(0,2,1,len[i]+1,0);
		update(0,2,2,len[i]+1,0);

		update(1,0,0,len[i]*2+2,11);
		update(1,0,1,len[i]*2+2,11);
		update(1,0,2,len[i]*2+2,11);

		update(1,1,0,len[i]*2+2,11);
		update(1,1,1,len[i]*2+2,11);
		update(1,1,2,len[i]*2+2,11);

		update(1,2,0,len[i]*2+2,11);
		update(1,2,1,len[i]*2+2,11);
		update(1,2,2,len[i]*2+2,11);

		if (i>1&&a[i]==a[i-1]+1)
		{
			update(1,1,0,len[i]-len[i-1],1);
			update(1,1,1,len[i]-len[i-1],1);
			update(1,1,2,len[i]-len[i-1],1);
		}

		update(2,0,0,len[i]*2+2,22);
		update(2,0,1,len[i]*2+2,22);
		update(2,0,2,len[i]*2+2,22);

		update(2,1,0,len[i]*2+2,22);
		update(2,1,1,len[i]*2+2,22);
		update(2,1,2,len[i]*2+2,22);

		update(2,2,0,len[i]*2+2,22);
		update(2,2,1,len[i]*2+2,22);
		update(2,2,2,len[i]*2+2,22);

		if (i>1&&a[i]==a[i-1]+2)
		{
			update(2,2,0,len[i]-len[i-1],2);
			update(2,2,1,len[i]-len[i-1],2);
			update(2,2,2,len[i]-len[i-1],2);
		}


		if (i>2&&a[i]==a[i-2]+2)
		{
			update(2,0,2,len[i]-len[i-2],2);
			update(2,1,2,len[i]-len[i-2],2);
			update(2,2,2,len[i]-len[i-2],2);
		}


	}
	x=-1,y=-1,z=1e9;
	for (i=0; i<3; i++) for (j=0; j<3; j++) if (cmin(z,f[n][i][j])) x=i,y=j;
	int anslen=z;
	for (i=n; i; i--)
	{
		z=pre[i][x][y];
		op[i]=opp[i][x][y];
		x=y; y=z;
	}
	string ans;
	vector<vector<int>> stk(3);
	auto clear=[&](vector<int> &a)
		{
			if (!a.size()) return;
			if (a==stk[2]) ans+=to_string(a[0])+"-"+to_string(a.back())+',';
			else ans+=to_string(a[0])+"%#"[a[0]%2]+to_string(a.back())+',';
			a.clear();
		};
	for (i=1; i<=n; i++)
	{
		if (op[i]!=1) clear(stk[2]);
		if (op[i]!=2) clear(stk[a[i]%2]);
		if (op[i]==0)
		{
			ans+=to_string(a[i])+',';
		}
		else if (op[i]%10==1) stk[2].push_back(a[i]);
		else if (op[i]%10==2) stk[a[i]%2].push_back(a[i]);
		else throw;
	}
	for (auto &v:stk) clear(v);
	ans.pop_back();
	cout<<ans<<endl;
	assert(ans.size()==anslen-1);
}
