#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
void cmax(int &x, int y) {x  = std::max(x, y);}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    const int Mod = 998244353;
    int n, i, j, k;
    cin >> n;
    vector<vector<int>> a(5, vector<int>(n));
    for(j=0; j<5; ++j) for(i=0; i<n; ++i) cin >> a[j][i];
    for(j=0; j<5; ++j) sort(all(a[j]));
    int ans = 0;
    auto Add = [](int x, int y) -> int{return (x+y)%Mod;};
    auto Mul = [](int x, int y) -> int{return (1ll*x*y)%Mod;};
    for(j=0; j<5; ++j) 
    {
        vector<int> num(5, -1);
        for(i=0; i<n; ++i) {
            for(k=0; k<5; ++k) if(k!=j)
            {
                if(k<j) while(a[k][num[k]+1]<=a[j][i] && num[k]<n-1) ++num[k]; 
                else while(a[k][num[k]+1]<a[j][i] && num[k]<n-1) ++num[k];
            }
            num[j]=i-1;
            int __ = 0;
            for(int s=0; s<(1<<5); ++s) {
                int flg = 0;
                for(k=0; k<5; ++k) if(k!=j && (s>>k&1)) ++flg;
                if(flg == 2) {
                    int _ = 1;
                    for(k=0; k<5; ++k) if(k!=j && (s>>k&1))
                         _ = Mul(_, n-num[k]-1);
                    else if(k != j) _ = Mul(_, num[k]+1);
                    // if(_ != 0) cerr << s << " " << _ << "\n";
                    __ = Add(__, _);
                }
            }
            ans = Add(ans, Mul(__, a[j][i]));
        }
    }
    cout << Mul(ans, (Mod+1)/2) << "\n";
    return 0;
}