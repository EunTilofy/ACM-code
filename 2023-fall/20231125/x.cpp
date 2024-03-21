#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for(int i = 1; i <= n; ++i) {
        cout << "k = " << i << "\n";
        vector<pair<int, int>> q;
        for(int j = 1; j <= i; ++j) {
            q.push_back({__gcd(j, i), __gcd(i - j + 1, i)});
            cout << __gcd(j, i) << " " << __gcd(i - j + 1, i) << "\n";
        }
        cout << "----\n";
        sort(q.begin(), q.end());
        for(auto [x, y] : q) {
            cout << x << " " << y << "\n";
        }
    }
}