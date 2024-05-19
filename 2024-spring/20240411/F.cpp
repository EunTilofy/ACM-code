#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

map<string, int> mp;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        mp[s]++;
    }
    for(auto[x, y] : mp) if(y > n / 2) {
        cout << x << "\n";
        return 0;
    }
    cout << "uh-oh\n";
    return 0;
}