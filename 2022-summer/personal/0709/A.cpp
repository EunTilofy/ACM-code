#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool mk[1000000005];
int pr[100000005], cnt;
void init() {
    for(int i = 2; i <= 1000; ++i) {
        if(!mk[i]) {pr[++cnt] = i;}
        for(int j = 1; j <= cnt && 1ll * pr[j] * i <= 1000; ++j) {
            mk[pr[j] * i] = true;
            if(i % pr[j] == 0) break;
        }
    }
} 
std::map<long long, int> mp;
int ans = 0;
int main() {
    ll n;
    scanf("%lld", &n);
    init();
    for(int l = 1; l <= cnt; ++l) {
        long long res = 1;
        for(int r = l; r <= cnt; ++r) {
            res *= pr[r];
            if(res > n) break;
            long long RR = res + 1;
            while(RR % 2 == 0) RR /= 2;
            if(RR == pr[r + 1] && RR != res + 1) {if(!mp[RR]) mp[RR] = 1, ++ans;}
        }
    }
    printf("%d\n", ans);
    return 0;
}