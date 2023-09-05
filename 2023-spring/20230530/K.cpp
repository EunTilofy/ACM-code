#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int flg = 0;
string ans = "Impossible";
int n, k;
string s;

bool check(string t) {
    for (int i = 1; i < n - 1; ++i) if (t[i] == '?') t[i] = '0';
    int pos = 0;
    for (int i = 1; i < n; ++i) pos += (t[i] != t[i - 1]);
    // cerr << pos << " " << t << "\n";
    if ((pos - k) & 1) return false;
    if (pos < k) {
        int tmp = (k - pos) / 2;
        for (int i = n - 2; i >= 1; --i) if (s[i] == '?') {
            if (t[i + 1] == '0' && t[i - 1] == '0') {
                tmp--;
                t[i] = '1';
            }
            if (!tmp) break;
        }
        // cerr << tmp << " " << t << "!\n";
        if (tmp) return false;
    }
    else if (pos > k) {
        int tmp = (pos - k) / 2;
        for (int i = n - 2; i >= 1; --i) if (t[i + 1] == '1' && t[i] == '0') {
            int j = i;
            for (; j - 1 >= 1 && t[j - 1] == '0'; --j);
            int ff = 1;
            if (t[j - 1] != '1') ff = 0;
            for (int k = j; k <= i; ++k)if (s[k] != '?') ff = 0;
            if (ff) {
                tmp--;
                for (int k = j; k <= i; ++k) t[k] = '1';
            }
            if (!tmp) break;
            i = j;
        }
        if (tmp) return false;
    }
    if (!flg) ans = t;
    else ans = ans < t ? ans : t;
    flg = 1;
    return true;
}

void solve() {
    cin >> n >> k >> s;
    flg = 0;
    ans = "Impossible";
    if (s[0] != '1' && s[n - 1] != '1') {
        string S = s; S[0] = '0', S[n - 1] = '0';
        check(S);
    }
    if (s[0] != '1' && s[n - 1] != '0') {
        string S = s; S[0] = '0', S[n - 1] = '1';
        check(S);
    }
    if (s[0] != '0' && s[n - 1] != '1') {
        string S = s; S[0] = '1', S[n - 1] = '0';
        check(S);
    }
    if (s[0] != '0' && s[n - 1] != '0') {
        string S = s; S[0] = '1', S[n - 1] = '1';
        check(S);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}