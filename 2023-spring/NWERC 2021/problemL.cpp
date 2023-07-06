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
double eps = 5e-8;
const int MN = 1e6+5;
double p[MN], q[MN], pre[MN], suf[MN];
double fjj[MN], sf[MN];
double fp(double x, int m) {
    double r = 1.0;
    for(;m;m>>=1,x*=x)if(m&1)r*=x;
    return r;
}
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i) p[i] = (double)i/n;
    for(int i = 1; i <= n; ++i) p[i] = fp(p[i], k);
    double ans = m*p[m-1];
    for(int i=m;i<=n;++i) ans+=(double)(i+1)/2*(p[i]-p[i-1]);
    // p[m] = 1;
    // for(int i = n; i; --i) sf[i] = sf[i+1]+1.0/i;
    // for(int i = 1; i <= n; ++i) fjj[i]=(i-1.0)/(double)n+sf[n]*sf[i];
    // for(int j = 1; j <= n; ++j) pre[j] = pre[j-1] + p[j];
    // for(int j = n; j; --j) suf[j] = suf[j+1] + sf[n]*sf[j]*p[j];
    // if(k > 150) {
    //     cout << (n+1.0)/2 << endl;
    //     return 0;
    // }
    // for(int i = 1; i <= min(k, 150); ++i) {
    //     for(int j = 1; j <= n; ++j) q[j] = p[j]*fjj[j]+suf[j+1];
    //     // for(int j = 1; j <= n; ++j) cout << q[j] << " "; cout << endl;
    //     for(int j = 2; j <= n; ++j) q[j] = q[j]+sf[n]*sf[j]*pre[j-1];

    //     for(int j = 1; j <= n; ++j) p[j]=q[j];
    //     for(int j = 1; j <= n; ++j) pre[j]=pre[j-1]+p[j];
    //     for(int j = n; j; --j) suf[j]=suf[j+1]+sf[n]*sf[j]*p[j];
    // }
    // double ans = 0;
    // for(int i = 1; i <= n; ++i) {
    //     // cout << p[i] << " ";
    //     ans += p[i] * i;
    // }
    cout << fixed << setprecision(20) << ans << endl;
    return 0;
}