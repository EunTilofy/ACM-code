#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    auto solve = [&](int n, vector<int> a) -> int{
        // cout << "!!!\n";
        int Min = a[0], Ma = a[0];
        for(int i = 1; i < n; ++i) Ma = max(Ma, a[i]), Min = min(Min, a[i]);
        int l = Min, r = Ma -1 , ans= Ma;
        while(l <= r) {
            int mid = (l + r) >> 1;
            int L = -1000000000;
            int R = 1000000000;
            int LL = 0, RR = n - 1;
            while(LL < n && a[LL] <= mid) ++LL;
            while(RR >= 0 && a[RR] <= mid) --RR;
            for(int i = LL; i <= RR; ++i) {
                L = max(L, a[i] - mid);
                R = min(R, a[i] - Min);
            }
            if(L <= R) ans = mid, r = mid - 1;
            else l = mid + 1;
        }
        return ans - Min;
    };
    while(T--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 1; i <= n; ++i) {
            cin >> a[i-1];
        }
        int ans = solve(n,a);
        for(int i = 1; i <= n; ++i) a[i - 1] = - a[i - 1];
        ans = min(ans, solve(n,a));
        cout << ans << "\n";
    }
}