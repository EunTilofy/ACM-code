#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e4 + 10;
int pr[N], mk[N];

bool check(int x) {
    cout << "? " << x << endl;
    // fflush(stdout);
    string s;
    cin >> s;
    return s == "Yes";
}

void output(int x) {
    cout << "! " << x << endl;
    // fflush(stdout);
    exit(0);
}

int main() {
    int mx = 10000;
    for(int i = 2; i <= mx; ++i) {
        if(!mk[i]) pr[++pr[0]] = i;
        for(int j = 1; j <= pr[0] && i * pr[j] < N; ++j) {
            mk[i * pr[j]] = 1;
            if(i % pr[j] == 0) break;
        }
    }
    // cout << pr[0] << "\n";
    int ans = 1;
    for(int i = 1; i <= pr[0]; ++i) {
        if(pr[i] * ans > mx) break;
        int pos = pr[i];
        if(check(pos)) {
            for(; pos * pr[i] * ans <= mx && check(pos * pr[i]); pos *= pr[i]);
            ans *= pos;
        }
    }
    output(ans);
    return 0;
}