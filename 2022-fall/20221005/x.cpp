#include<bits/stdc++.h>
#define ll long long
//#define int long long
//#define ll __int128
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

map<string, int> mp;

void upd(string s) {
	mp.clear();
	for(int i = 0; i < s.size(); ++i) {
		for(int j = i; j < s.size(); ++j) {
			string t = "";
			for(int k = i; k <= j; ++k) 
				t += s[k];
			mp[t] = 1;
		}
	}
}

void dfs(int dep, string s) {
	if(dep > 6) {
		upd(s);
		if(mp.size() == 16) {
			cout << s << endl;
			exit(0);
		}
		return ;
	}
	string t = s;
	for(int i = 0; i < 26; ++i) {
		s += ('a' + i);
		dfs(dep + 1, s);
		s = t;
	}
}

int main() {
//	 freopen("distinct.out", "w", stdout);
//     freopen("distinct.in", "r", stdin);
	dfs(2, "a");	
	return 0;
}