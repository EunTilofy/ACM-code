#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        int x,y,k;
        cin >> x >> y >> k;
        if(x>y) cout << "Case #" <<i <<": " << k << endl;
        else {
            int cost = 1ll*11*y-9ll*x;
            int ans = k;
            while(ans>0) {
                if(1ll*cost*ans<=1ll*(k-ans)*11*x) break;
                ans--;
            }
            cout << "Case #" <<i <<": " << ans << endl;
        }
    }
    return 0;
}