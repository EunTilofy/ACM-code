#include<bits/stdc++.h>
using namespace std;

const int MN = 2e5 + 5;

vector<int> G[MN];

bool vis[MN];

bool solve() {
    int n;
    cin >> n;
    vector<int> b(n);
    for(int& x : b) cin >> x;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        if(i > 0) {
            if(b[i] == b[i - 1]) a[i] = a[i - 1];
            else if(b[i] == b[i - 1] + 1) a[i] = a[i - 1] + 1;
            else return false;
        } else {
            if(b[i] != 1) return false;
            a[i] = 1;
        }
    }
    cout << "YES\n";
    for(int x : a) cout << x << " ";
    cout << "\n";
    return  true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        if(!solve()) cout << "NO\n";
    }
}