#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
void cmax(int &x, int y) {x  = std::max(x, y);}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, i, j, x;
    cin >> n >> x;
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    vector<vector<int>> f(n+1, vector<int>(10005));
    fill(all(f[0]), -105);
    function<set<int>(int x)> get = [](int x) -> set<int>
    {
        string s = to_string(x);
        set<int> S;
        vector<int> a(s.size());
        for(int i = 0; i < s.size(); ++i) a[i] = i;
        do
        {
            string t = "";
            for(int i = 0; i < s.size(); ++i) t = t + s[a[i]];
            S.insert(stoi(t));
        }while(next_permutation(all(a)));
        return S;
    };  
    for(auto v : get(x)) f[0][v] = 0;  
    for(i=0; i<n; ++i)
    {
        f[i+1] = f[i];
        for(j=a[i]; j<=10000; ++j) if(f[i][j]>=0) {
            for(auto v : get(j-a[i])) cmax(f[i+1][v], f[i][j]+1);
        }
    }
    int ans=0;
    for(auto x : f[n]) ans = max(x, ans);
    cout << ans << "\n";
    return 0;
}