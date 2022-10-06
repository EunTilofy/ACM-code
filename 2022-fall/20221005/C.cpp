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
string s = "";

int check(int x) {
	int ans = 0;
	for(int i = 0; i <= s.size(); ++i) {
		string t = "";
		for(int j = i; j < s.size(); ++j) {
			t += s[j];
		}
		t += ('a' + x);
		if(!mp.count(t)) ans++;
	}
//	printf("%d %d %d\n", x, ans, (int)mp.size());
	return ans + mp.size();
}

void upd() {
	for(int i = 0; i < s.size(); ++i) {
		string t = "";
		for(int j = i; j < s.size(); ++j) {
			t += s[j];
		}
		mp[t] = 1;
	}
}

int main() {
//	 freopen("distinct.out", "w", stdout);
//     freopen("distinct.in", "r", stdin);
//	int n = read();
	for(int n = 1; n <= 300; ++n) {
		cout << n << endl;
		mp.clear();
	int len = 0;
	for(; len * (len + 1) / 2 < n; ++len) {
	}
	int now = 1;
	mp["a"] = 1, s = "a";
	for(int i = 2; i <= len; ++i) {
		int pos = 0, cur = (len + i + 1) * (len - i) / 2;
//		printf("i = %d %d\n", i, cur);
		for(int j = 0; j < 26; ++j) {
			if(check(j) + cur >= n) {pos = j; break;}
		}
		s += ('a' + pos);
		upd();
	}
	if(mp.size() != n) cout << s << endl;
	}
	return 0;
}