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
#define REP(i,a,b) for(int i=(a),i##_end_=(b);i<i##_end_;++i)
#define DREP(i,a,b) for(int i=(a),i##_end_=(b);i>i##_end_;--i)
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

map<string, char> mp;
char s[100010];

void init() {
	string t1 = "";
	for(int i = 0; i < 26; ++i) {
		t1 = "";
		t1 += 'a' + i;
		mp[t1] = 'a' + i;
	}
mp["iu"]= 'q', mp["en"] = 'f';
mp["ei"]= 'w', mp["eng"] = 'g';
mp["ang"] = 'h';
mp["uan"] = 'r', mp["an"] = 'j';
mp["ue"] = 't', mp["uai"] = 'k', mp["ing"] = 'k';
mp["un"] = 'y', mp["uang"] = 'l', mp["iang"] = 'l';
mp["sh"] = 'u', mp["ou"] = 'z';
mp["ch"] = 'i', mp["ia"] = mp["ua"] = 'x';
mp["uo"] = 'o', mp["ao"] = 'c';
mp["ie"] = 'p', mp["zh"] = mp["ui"] = 'v';
mp["in"] = 'b';
mp["ong"] = mp["iong"] = 's', mp["iao"] = 'n';
mp["ai"] = 'd', mp["ian"] = 'm';
}

bool check(int l, int m, int r) {
	string t1 = "", t2 = "";
	for(int i = l; i <= m; ++i) t1 += s[i];
	for(int i = m + 1; i <= r; ++i) t2 += s[i];
	if(mp.count(t1) && mp.count(t2)) {
		printf("%c%c ", mp[t1], mp[t2]);
		return true;
	}
	return false;
}

int main() {
	init();
	while(scanf("%[^\n]", s) != EOF) {
		getchar();
		int len = strlen(s);
		for(int i = 0; i < len; ++i) {
			int j = i;
			for(; j < len && s[j] != ' '; ++j);
			j--;
			if(j == i) printf("%c%c ", s[i], s[i]);
			else if(j - i == 1) printf("%c%c ", s[i], s[j]);
			else {
				string t1 = "";
				for(int k = i; k <= j; ++k) t1 += s[k];
				if(mp.count(t1)) printf("%c%c ", s[i], mp[t1]);
				else {
					for(int k = i; k < j; ++k) {
						if(check(i, k, j)) {
							break;
						}
					}
				}
			}
			i = j + 1;
		}
		puts("");
	}
	return 0;
}
