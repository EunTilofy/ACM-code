#include<bits/stdc++.h>
using namespace std;
int n;
bool ff[205][105][105];
double f[205][105][105];
double dfs(int m, int np, int nl) {
    int all = 0;
    if(n>m && np+nl>0) all += 4 * (np + nl) * (n - m);
    if(np+nl>1) all += 4 * (np + nl) * (np + nl - 1);
    if(nl>0) all += 2 * nl;
    if(n>m+1) all += (n - m) * (n - m - 1);
    if (all == 0) return 0;
    if(ff[m][np][nl]) return f[m][np][nl];
    double ans = (double)n*n/(double)all;
    if(np>0 && n>m) ans += dfs(m+1, np-1, nl+1) * 4 * np * (n - m) / (double)all; // case 1
    if(nl>0 && n>m) ans += dfs(m+1, np, nl) * 4 * nl * (n-m) / (double)all;
    if(np>0 && nl>0) ans += dfs(m, np-1, nl) * 2 * np * 2 * nl * 2 / (double)all; // case 2
    if(np>1) ans += dfs(m, np-2, nl+1) * 4 * np * (np - 1) / (double)all;
    if(nl>1) ans += dfs(m, np, nl-1) * 4 * nl * (nl - 1) / (double)all;
    if(nl>0) ans += dfs(m, np, nl-1) * 2 * nl / (double)all; // cas3 
    if(n-m>1) ans += dfs(m+2, np+1, nl) * (n-m) * (n-m-1) / (double)all; // cas4
    ff[m][np][nl]=1;
    f[m][np][nl] = ans;

    // cout << m << " " << np << " " << nl << " " << f[m][np][nl] << " " << all << endl;
    return ans;
}
int main() {
    cin >> n;
    cout << fixed << setprecision(9) << dfs(0, 0, 0) ;
}