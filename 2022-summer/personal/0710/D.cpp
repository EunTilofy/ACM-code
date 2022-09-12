#include<bits/stdc++.h>
using namespace std;
int n;
const int MN = 1e5+5;
int a[MN], b[MN], id[MN];
std::set<int> S;
std::set<int>::iterator it;
bool cmp(int x, int y) {return b[x] > b[y] || (b[x] == b[y] && a[x] > a[y]);}
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        id[i] = i;
    }
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &b[i]);
    }
    std::sort(id + 1, id + n + 1, cmp);
    for(int i = 0; i <= 100001; ++i) S.insert(i); 
    long long ans = 0;
    for(int i = 1; i <= n; ++i) {
        int c = b[id[i]];
        int t = a[id[i]];
        it = S.upper_bound(t);
        if(it != S.begin()) {
            --it;
            ans += c;
            S.erase(*it);
        }
    }
    return 0 * printf("%lld\n", ans);
}