#include <bits/stdc++.h>
#define ll long long
#define db double
#define dbg1(x) cerr<<#x <<"="<<(x)<<" "
#define dbg2(x) cerr<<#x <<"="<<(x)<<"\n"
#define dbg3(x) cerr<<#x <<"\n"
using namespace std;
bool fnd = 0;
int ans = 0;
int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch <= '9' && ch >= '0') {x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
	return x * f;
}
int l, r;
void dfs(int k, bool _l, bool _r, int now, int nm1) {
	if((now >> (k + 1)) & 1) {
		if(nm1 == k + 1 && now >= l && now <= r) {fnd = 1; ans = now; return;}
	}
	// dbg1(k); dbg1(_l); dbg1(_r); dbg1(now); dbg2(nm1);
	if(k < 0) return ;
	if(fnd) return;
	if(!_l && !_r) {
		if(nm1 >= k) return;
		else {
			int Now = now + (1 << nm1 + 1);
			fnd = 1;
			ans = Now;
			return;
		}
	}
	int oL = 0, oR = 1;
	if(_l) oL = l>>k&1;
	if(_r) oR = r>>k&1;
	for(int _ = oL; _ <= oR; ++_) {
		dfs(k - 1, _l & (_ == (l>>k&1)), _r & (_ == (r>>k&1)), now + (_ << k), nm1 + _);
	}
	return ;
}
int main() {
	int T = read();
	while(T--) {
		l = read(); r = read();
		fnd = ans = 0;
		dfs(30, 1, 1, 0, 0);
		if(fnd) printf("%d\n", ans);
		else printf("-1\n");
	}
	return 0;
}