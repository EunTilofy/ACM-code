#include<bits/stdc++.h>
using namespace std;

char next(char x, int y) {
    int now = x - 'a';
    now = (now + y) % 26;
    return now + 'a';
}
int fpow(int x, int y, int m) {
    int r=1;
    while(y>0) {
        if(y & 1) r = r * x % m;
        y>>=1;
        x = x*x%m;
    }
    return r;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int pr = 0;
    while(n < m*2) {
        string t1, t2;
        for(int i = 1; i <= n/2; ++i) t1+=s[i-1], t2+=next(s[i-1+n/2], 1);
        s = t1 + s + t2;
        n=n*2;
        ++pr;
        // cout << s << " " << t1 << " " << t2 << endl;
    }
    // cout << s.size() << " " << n << " " << n - m << endl;
    string t = s.substr(n - m, m);
    // cout << t << endl;
    int step = (fpow(10, 100, 26) + 26 - pr) % 26;
    // cerr << step;
    for(auto &x : t) x = next(x, step);
    cout << t ;
}