#include<bits/stdc++.h>
using namespace std;

#define MN 1005
int a[1005][1005];
int b[1005];
void prt(int n, int m, bool fl) {
    if(fl==0) {
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                cout << a[i][j];
            }
            cout << "\n";
        }
    }
    else {
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                cout << a[j][i];
            }
            cout << "\n";
        }
    }
}
void mst(int n, int m) {
    for(int i = 1; i <= n; ++i) 
        for(int j = 1; j <= m; ++j)
            a[i][j] = 0;
}
void solve() {
    int n, m;
    cin >> n >> m;
    bool fl = 0;
    mst(n, m);
    if(n > m) swap(n, m), fl = 1;
    if(n == m) {
        if(n & 1) {
            cout << "NO" << endl;
            return;
        }
        cout << "YES" << endl;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= i; ++j) {
                a[i][j] = 1;
            }
        }
        for(int i = n/2+1; i <= n; ++i) a[i][1] = 0;
        prt(n, m, fl);
        return ;
    }
    if(n < 10 && (1<<n) < m) {
        cout << "NO" << endl;
        return;
    }
    if((n * m) & 1) {
        cout << "NO" << endl;
        return ;
    }
    cout << "YES" << endl;
    mst(n, m);
    for(int i = 0; i <= n; ++i) {
        for(int j = n; j >= n-i+1; --j) a[j][i+1] = 1;
    }
    if(n & 1 || m & 1) {
        for(int i = 1; i <= n; ++i) b[i] = 0;
        int cnt = n + 1;
        int xxxxx = 0;
        while(cnt < m) {
            if(xxxxx < (n-1)/2) {
                ++cnt;++xxxxx;
                for(int i = 1; i <= xxxxx; ++i) a[i][cnt] = 1;
                ++cnt;
                for(int i = 1; i <= n-xxxxx; ++i) a[i][cnt] = 1;
            } else{
            while(1) {
                for(int j = 1; j <= n; ++j) {
                    if(b[j] == 0) {++b[j]; break;}
                    else {
                        b[j] = 0;
                    }
                }
                int cnt0 = 0, cnt1 = 0, cnt3 = 0;
                for(int i = 1; i <= n; ++i) cnt0 += b[i] == 0;
                for(int i = 1; i <= n; ++i) {
                    if(b[i]) break;
                    ++cnt1;
                }
                for(int i = n; i ; --i) {
                    if(b[i]) break;
                    ++cnt3;
                }
                // cout << cnt0 << cnt1 << cnt3;
                if(cnt0 != cnt1 && cnt0 != cnt3) break;
            }
            ++cnt;
            for(int i = 1; i <= n; ++i) a[i][cnt] = b[i];
            ++cnt;
            for(int i = 1; i <= n; ++i) a[i][cnt] = !b[i];
            }    
        }
    }
    else {
        for(int i = 1; i <= n; ++i) b[i] = 0;
        for(int i = 1; i <= n/2; ++i) a[i][n+2] = 1;
        int cnt = n + 2;
        int xxxxx = 0;
        while(cnt < m) {
            int xxx = 0;
            if(xxxxx < (n-1)/2) {
                ++cnt;++xxxxx;
                for(int i = 1; i <= xxxxx; ++i) a[i][cnt] = 1;
                ++cnt;
                for(int i = 1; i <= n-xxxxx; ++i) a[i][cnt] = 1;
            }
            else {
            while(1) {
                for(int j = 1; j <= n; ++j) {
                    if(b[j] == 0) {++b[j]; break;}
                    else {
                        b[j] = 0;
                    }
                }
                int cnt0 = 0, cnt1 = 0, cnt3 = 0;
                for(int i = 1; i <= n; ++i) cnt0 += b[i] == 0;
                for(int i = 1; i <= n; ++i) {
                    if(b[i]) break;
                    ++cnt1;
                }
                for(int i = n; i ; --i) {
                    if(b[i]) break;
                    ++cnt3;
                }
                // cout << cnt0 << cnt1 << cnt3;
                if(cnt0 != cnt1 && cnt0 != cnt3) break;
            }
            ++cnt;
            for(int i = 1; i <= n; ++i) a[i][cnt] = b[i];
            ++cnt;
            for(int i = 1; i <= n; ++i) a[i][cnt] = !b[i];
            }    
        }
    }
    prt(n, m, fl);
}
int main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}