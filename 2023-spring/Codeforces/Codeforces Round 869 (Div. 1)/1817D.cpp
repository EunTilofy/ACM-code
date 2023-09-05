//这回只花了114514min就打完了。
//真好。记得多手造几组。ACM拍什么拍。 
#include "bits/stdc++.h"
using namespace std;
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
template<typename typC,typename typD> bool cmin(typC &x,const typD &y) { if (y<x) { x=y; return 1; } return 0; }
template<typename typC,typename typD> bool cmax(typC &x,const typD &y) { if (x<y) { x=y; return 1; } return 0; }
template<typename typC> vector<typC> range(typC l,typC r,typC step=1) { assert(step>0); int n=(r-l+step-1)/step,i; vector<typC> res(n); for (i=0; i<n; i++) res[i]=l+step*i; return res; }
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...) ;
#define dbgn(...) ;
#endif
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
// template<typename T1,typename T2> void inc(T1 &x,const T2 &y) { if ((x+=y)>=p) x-=p; }
// template<typename T1,typename T2> void dec(T1 &x,const T2 &y) { if ((x+=p-y)>=p) x-=p; }
const int N=1e6+5;
string operator*(const string &s,int m)
{
	string r;
	while (m--) r+=s;
	return r;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cout<<fixed<<setprecision(15);
	int n,m;
	cin>>n>>m;
	auto solve=[&](int n,int m) -> string
	{
		if (m==n/2) return "DL"s;
		if (m<=n/2) return "DRUL"s*m;
		string s;
		s=n-2==m?"R"s:"DLUR"s*(n-1-m);
		s+="LDLU"s*(n+5);
		s+="RDL";
		return s;
	};
	cout<<solve(n,m)<<endl;
}
