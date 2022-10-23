#include<bits/stdc++.h>
#define dbg2(x) std::cerr<<#x<<"="<<(x)<<"\n"
#define dbg4(x) std::cerr<<#x<<" "
using namespace std;
std::set<long long> pre[55][55], suf[55][55];
std::set<__int128> all;
char s[55],t[55];
int ls, lt;
void dfs_pre(int ns, int nt, int len, long long v) {
	if(ns + nt == len) {
//		dbg4(pre); dbg2(v);
		pre[ns][nt].insert(v);
		return;
	}
	if(ns < ls) {
		dfs_pre(ns + 1, nt, len, (v<<1)|(s[ns+1]-'0'));
	}
	if(nt < lt) {
		dfs_pre(ns, nt + 1, len, (v<<1)|(t[nt+1]-'0'));
	}
}
void dfs_suf(int ns, int nt, int len, long long v) {
	if(ls - ns + lt - nt + 2 == len) {
//		dbg4(suf); dbg2(v);
		suf[ns][nt].insert(v);
		return;
	}
	int pos = (ls - ns + lt - nt + 2);
	if(ns) {
		dfs_suf(ns - 1, nt, len, v|((s[ns-1]-'0') << pos));
	}
	if(nt) {
		dfs_suf(ns, nt - 1, len, v|((t[nt-1]-'0') << pos));
	}
}
void print(__int128 x) {
	if(x < 2) printf("%d", (int)(x==1?1:0));
	else {
		print(x/10);
		printf("%d", (int)(x%2==1?1:0));
	}
}
int main() {
	freopen("interleave.in","r",stdin);
	freopen("interleave.out","w",stdout);
//	std::ios::sync_with_stdio(0);
//	std::cin.tie(0);
//	srand(time(NULL));
	scanf("%s", s + 1);
	scanf("%s", t + 1);
	ls = strlen(s + 1), lt = strlen(t + 1);
	int len = ls + lt;
	int half = len / 2;
	dfs_pre(0,0,half, 0);
	dfs_suf(ls + 1,lt + 1,len - half, 0);
	for(int i = 0; i <= half; ++i) {
		int j = half - i;
		if(i <= ls && j <= lt && j >= 0) {
			for(auto _pre : pre[i][j]) {
				for(auto _suf : suf[i + 1][j + 1]) {
					__int128 _all = _pre;
					__int128 __suf = _suf;
					_all = (_all << (len - half)) + __suf;
//					print(_all);puts("");
					all.insert(_all);
				}
			}
		}
	}
	printf("%d\n", all.size() % 1000000007);
//	for(__int128 x : all) {
//		print(x);puts("");
//	}
	return 0;
}