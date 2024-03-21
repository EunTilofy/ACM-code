#include<bits/stdc++.h>
using namespace std;

long long n, cnt;
long long a[61*61];
bool in[61*61];
int ID[66][66], xx[61*61], yy[61*61];
pair<long long, long long> check() {
    vector<pair<long long, int>> v;
    for(int i = 1; i <= cnt; ++i) v.push_back({a[i], i}), in[i] = 0;
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    // cerr << v[0].first << "\n";
    long long now = 0, ch = 0;
    for(auto [x, id] : v) {
        if(now + x <= n && x > 0) {
            in[id] = 1;
            now += x;
            ++ch;
        }
    }
    return {ch, n-now};
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    
    for(int i = 1; i <= 60; ++i) for(int j = 1; j <= i; ++j) {
        ID[i][j] = ++cnt;
        xx[cnt]=i*2-1, yy[cnt]=j;
    }
    for(int i = 1; i <= 60; ++i) a[ID[i][1]] = 1;
    
    for(int day=0; day<=80; ++day) {
        auto [x, y] = check();
        // cerr << x << " " << y << "\n";
        if(x+y<=10000) {
            cout << (y+1830) << "\n";
            for(int i = 1; i <= 60; ++i) {
                cout << i*2-1 << " " << "1 1\n";
                for(int j = 2; j <= i; ++j)
                cout << i*2-1 << " " << j << " " << "0\n";
            }
            for(int i = 1; i <= y; ++i) {
                cout << "-1 " << i*2-1 << " " << "1\n";
            }
            long long all = 0;
            cout << x+y << " " << day << "\n";
            for(int i = 1; i <= y; ++i) cout << "-1 " << i*2-1 << "\n", ++all;
            for(int i = 1; i <= cnt; ++i) if(in[i]) {
                cout << xx[i] << " " << yy[i] << "\n";
                all += a[i];
            }
            // cerr << all << "\n";
            return 0;
        }
        for(int i = 1; i <= 60; ++i) {
            vector<long long> v(i+1);
            for(int j = 1; j <= i; ++j) {
                long long vv = a[ID[i][j]];
                if(j>1) vv+=a[ID[i][j-1]];
                if(j<i) vv+=a[ID[i][j+1]];
                v[j] = vv;
            }
            for(int j = 1; j <= i; ++j) a[ID[i][j]] = v[j];
        }
    }
    // assert(0);
    return 0;
}