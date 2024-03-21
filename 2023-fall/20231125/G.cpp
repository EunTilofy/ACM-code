#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll x, y;
    cin >> x >> y;
    ll now = 0;
    for(int i = 63; i >= 0; --i) if((y >> i) & 1) {
        if(((x >> i) & 1) == 0) {
            now = 1ll << i;
            break;
        }
    }
    // cout << now << "\n";
    x ^= now;
    assert((x ^ y) < x);
    cout << 2 << "\n" << now << " " << (x ^ y) << "\n";
}