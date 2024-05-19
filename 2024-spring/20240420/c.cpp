#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int a[10][10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int o = 1; o <= n; ++o) {
        int flg = 1;
        for(int i = 0; i < 9; ++i) for(int j = 0; j < 9; ++j) cin >> a[i][j];
        for(int i = 0; i < 9; ++i) {
            vector<int> cnt(10);
            for(int j = 0; j < 9; ++j) {
                int x = a[i][j];
                if(x < 1 || x > 9) flg = 0;
                else {
                    if(cnt[x]) flg = 0;
                    cnt[x] = 1;
                }
            }
        }
        for(int i = 0; i < 9; ++i) {
            vector<int> cnt(10);
            for(int j = 0; j < 9; ++j) {
                int x = a[j][i];
                if(x < 1 || x > 9) flg = 0;
                else {
                    if(cnt[x]) flg = 0;
                    cnt[x] = 1;
                }
            }
        }
        for(int i = 0; i < 9; i += 3) for(int j = 0; j < 9; j += 3) {
            vector<int> cnt(10);
            for(int k = 0; k < 3; ++k) for(int t = 0; t < 3; ++t) {
                int x = a[i + k][j + t];
                if(x < 1 || x > 9) flg = 0;
                else {
                    if(cnt[x]) flg = 0;
                    cnt[x] = 1;
                }
            }
        }
        cout << flg << "\n";
    }
    return 0;
}