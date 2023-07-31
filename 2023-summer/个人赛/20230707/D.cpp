#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    long long sum = 0;
    for(int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        sum += x;
        if(sum < 0) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}