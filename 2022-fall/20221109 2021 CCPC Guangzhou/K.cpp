#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")

#include<bits/stdc++.h>
using namespace std;
int n, m, p, q;
#define MN 210005
#define mod 998244353
int Add(int x, int y) {return ((x+y)%mod+mod)%mod;}
int Mul(int x, int y) {return ((1ll*x*y)%mod+mod)%mod;}
int fpow(int x,int y) {int r=1;for(;y;y>>=1,x=Mul(x,x))if(y&1)r=Mul(r,x);return r;}
std::vector<int> d[MN], pos[MN], sum[MN], sum1[MN], sum2[MN];
int sum3[MN], sum4[MN];

int mu[MN], pr[MN], tot;
bool mk[MN];
void init() {
	mu[1] = 1;
	for(int i = 2; i <= m; ++i) {
		if(!mk[i]) {pr[++tot]=i; mu[i]=-1;}
		for(int j = 1; j <= tot && 1ll * pr[j] * i <= m; ++j) {
			mk[pr[j]*i] = 1;
			if(i % pr[j] == 0) {
				mu[i * pr[j]] = 0;
				break;
			}
			else mu[i * pr[j]] = - mu[i];
		}
	}
	for(int i = 1; i <= m; ++i) mu[i] = (mu[i]%mod + mod) % mod;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin>>n>>m>>p>>q;
	int M = m;
	m = max(p, q);
	init();
	for(int i = 1; i <= m; ++i) {
		for(int j = i; j <= m; j += i) {
			d[j].push_back(i);
			pos[i].push_back(d[j].size()-1);
		}
	}
	for(int i = 1; i <= m; ++i) 
		sum[i].resize(d[i].size()),
		sum2[i].resize(d[i].size()),
		sum1[i].resize(d[i].size());
	
	for(int i = 1; i <= m; ++i) {
		for(auto x : d[i]) {
			for(int j = i; j <= m; j += i) {
				sum[j][pos[x][j/x-1]] = Add(sum[j][pos[x][j/x-1]], i);
			}
		}
	}
	for(int i = 1; i <= m; ++i) for(int j = 0; j < d[i].size(); ++j) sum[i][j] = fpow(sum[i][j], n);
	for(int i = 1; i <= m; ++i) {
		for(int j = 0; j < d[i].size(); ++j) {
			for(auto y : d[d[i][j]]) {
				sum1[i][pos[y][i/y-1]] = Add(sum1[i][pos[y][i/y-1]], Mul(mu[d[i][j]/y], sum[i][j]));
			}
		}
	}

	for(int i = 1; i <= m; ++i) {
		for(int j = 0; j < d[i].size(); ++j) {
			for(int jj = i; jj <= m; jj = jj + i) {
				sum2[jj][pos[d[i][j]][jj/d[i][j]-1]] = Add(sum2[jj][pos[d[i][j]][jj/d[i][j]-1]], Mul(mu[jj/i], sum1[i][j]));
			}
		}
	}

	for(int i = 1; i <= M; ++i) {
		int _ = 0;
		int _b = i, _e = (M/i) * i;
		_ = Mul(Add(_b, _e), Mul((_e-_b)/i + 1, (mod + 1)/2));
		_ = fpow(_, n);
		sum3[i] = _;
	}
	for(int i = 1; i <= M; ++i) for(int j = i; j <= M; j += i) sum4[i] = Add(sum4[i], Mul(mu[j/i], sum3[j]));
	
	int _sum1 = 0, _sum2 = 0;
	
	for(int i = 1; i < p; ++i) {
		for(int j = 0; j < d[i].size(); ++j) {
			if(d[i][j] <= q) {
//				dbg1(i); dbg2(d[i][j]);
				_sum1 = Add(_sum1, sum2[i][j]);
			}
		}
	}
	for(int i = q + 1; i <= M; ++i) _sum2 = Add(_sum2, sum4[i]);
	
//	dbg2(_sum2);
//	dbg2(_sum1);
	
	int All = fpow(Mul(M, Mul(M + 1, (mod + 1)/2)), n);
	
	int Ans = Add(All, Add(mod - _sum1, mod - _sum2));
	
	cout<<Ans<<endl;
	
	return 0;
}