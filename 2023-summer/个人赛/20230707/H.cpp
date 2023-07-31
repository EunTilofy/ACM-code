#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        bool a[26];
        for(int i = 0; i < 26; ++i) a[i] = 0;
        int n;
        cin >> n;
        for(int j = 1; j <= 2 * n + 1; ++j) {
            string s;
            cin >> s;
            for(auto c : s) {
                a[c-'a']^=1;
            }
        } 
        for(int i = 0; i < 26; ++i) if(a[i] == 1) cout << (char)('a' + i) << endl;
    }
}