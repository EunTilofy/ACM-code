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
#define mkp make_pair
using namespace std;
#define MN 4005
int n, a[MN][MN];
inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar();
	}
	return x*f;
}

#define se second
#define fi first

int f[MN][MN];
bitset<MN / 2> vis[MN], vis2[MN];
std::pair<int, int> pos[MN * MN / 4];

void upd(int l, int r) {
    // printf("upd %d %d : (f[%d][%d] = %d) \n", l, r, l, r, f[l][r]);
    bitset<MN / 2> tmp;
    if(r + 1 <= n) {
        tmp = (~vis[l]) & vis[r + 1];
        int k = tmp._Find_first();
        while(k != tmp.size()) {
            // printf("===%d %d %d\n", l, k, f[l][r]);
            int kk = k * 2 + (l % 2 == 0);
            f[l][kk] = f[l][r];
            vis[l][kk / 2] = vis2[kk][l / 2] = 1;
            upd(l, kk);
            k = tmp._Find_next(k);
        }
    }
    if(l > 1) {
        tmp = (~vis2[r]) & vis2[l - 1];
        int k = tmp._Find_first();
        while(k != tmp.size()) {
            // printf("===%d %d %d\n", k, r, f[l][r]);
            int kk = k * 2 + (r % 2 == 0);
            f[kk][r] = f[l][r];
            vis[kk][r / 2] = vis2[r][kk / 2] = 1;
            upd(kk, r);
            k = tmp._Find_next(k);
        }
    }
    // printf("upd %d %d : (f[%d][%d] = %d) \n", l, r, l, r, f[l][r]);
    if(l > 1 && r < n && !vis[l - 1][(r + 1) / 2] && a[l - 1][r + 1] < f[l][r]) {
        // printf("***%d %d %d\n", l - 1, r + 1, f[l][r]);
        vis[l - 1][(r + 1) / 2] = 1;
        vis2[r + 1][(l - 1) / 2] = 1;
        f[l - 1][r + 1] = f[l][r];
        upd(l - 1, r + 1);
    }
}

int main() {
    n = read();
	for(int i = 1; i <= n; i++)
		for(int j = i + 1; j <= n; j += 2) {
            a[i][j] = read();
            pos[a[i][j]] = mkp(i, j);
        }
    int MAX = (n / 2) * (n / 2);
    for(int i = 1; i <= MAX; ++i) {
        int l = pos[i].fi, r = pos[i].se;
        if(vis[l][r / 2] == 0 && (vis[l + 1][(r - 1) / 2] == 1 || (r == l + 1))) {
            vis[l][r / 2] = vis2[r][l / 2] = 1;
            f[l][r] = i;
            upd(l, r);
        }
    }
    return 0 * printf("%d\n", f[1][n]);
}