#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int l, r;
    cin >> l >> r;
    vector<int> f, b;
    for(int i = l; i <= r; ++i) {
        string s;
        cin >> s;
        if(s[0] >= '0' && s[0] <= '9') {

        } else if(s.size() > 4) {
            f.push_back(i);
            b.push_back(i);
        } else if(s[0] == 'F') f.push_back(i);
        else b.push_back(i);
    }
    int inf = 1e6, A = -1, B = -1;
    if(f.size() == 0) A = inf, --inf;
    else if(f.size() == 1) {
        for(int i = 1; i <= f[0]; ++i) if(f[0] % i == 0) {
            int L = (l + i - 1) / i * i, R = r / i * i;
            if(L == R && f[0] == L) {
                A = i;
                break;
            }
        }
    } else {
        A = f[1] - f[0];
    }
    if(b.size() == 0) B = inf, --inf;
    else if(b.size() == 1) {
        for(int i = 1; i <= b[0]; ++i) if(b[0] % i == 0) {
            int L = (l + i - 1) / i * i, R = r / i * i;
            if(L == R && b[0] == L) {
                B = i;
                break;
            }
        }
    } else {
        B = b[1] - b[0];
    }
    cout << A << " " << B << "\n";
    return 0;
}