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
const int MN = 3e5 + 5;
string s, ans = "";
int len = s.length(), flg2 = 0, flg3 = 0;

void fail() {
	puts("!@#$%");
	exit(0);
}

void go(int pos) {
	int tmp = pos / 4, yu = pos % 4;
	if(yu) {tmp--, ans += "<b></b>";}
	for(int k = 1; k <= tmp; ++k) ans += "<i></i>";
}

void solve(int pos) {
	if(!pos) return ;
	if(pos == 1) fail();
	if(flg2 && flg3) {
		if(pos & 1) {
			pos -= 3, flg3 = 0, ans += "</b>";
			solve(pos); return ;
		} else {
			pos -= 2, flg2 = 0, ans += "</i>";
			solve(pos); return ;
		}
	} else if(flg2) {
		if(pos == 2) {
			flg2 = 0, ans += "</i>";
		} else if(pos % 6 == 0) {
			for(int i = 1; i <= pos / 6; ++i) {
				ans += "<b></b>";
			}
		} else if(pos & 1) {
			pos -= 3, flg3 = 1;
			if(pos == 2) flg2 = 0, ans += "</i>";
			else 			
			ans += "<b>";
		}
	} else if(flg3) {
		if(pos & 1) {
			pos -= 3, flg = 0, ans += "</b>";
			solve(pos); return ;
		} else if(pos % 4 == 0) {
			go(pos); return ;
		} else 
	} else {
		if(pos == 2) flg2 = 1, ans += "<i>";
		else if(pos & 1) {
			pos -= 3, flg3 = 1;
			if(pos == 2) flg2 = 1, ans += "<i>";
			else go(pos);
			ans += "<b>";
		} else {
			go(pos);
		}
	}
}

int main() {
    // freopen("points.out", "w", stdout);
    // freopen("points.in", "r", stdin);
    // std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    getline(cin, s);
    for(int i = 0; i < len; ++i) {
		if(s[i] != '\'') {
			ans += s[i];
		} else {
			int j = i;
			for(; j + 1 < len && ss[j + 1] == '\''; ++len);
			int pos = j - i + 1;
			solve(pos);
			i = j;
		}
	}
	cout << ans << endl;
    return 0;
}