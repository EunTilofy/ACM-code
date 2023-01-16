#include<bits/stdc++.h>
using namespace std;
int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    int G = a[0];
    for(auto x : a) G = gcd(G, x);
    int ans = (a[0]-1)/2;
    ans = max(ans, G);
    
    int fl = 1;
    for(auto x : a) {
        fl &= (x == a[0]) || ((x - 1)/2 >= a[0]) || (x%a[0] == 0);
    }
    int fl1 = a[0]>=2;
    if(fl1) {
        for(auto x : a) {
            fl1 &= (x % (a[0]/2) == 0) || ((x - 1)/2 >= a[0]/2);
        }
    }
    if(fl) ans = max(ans, a[0]);
    if(fl1) ans = max(ans, a[0]/2);
    cout << ans;
    return 0;
}