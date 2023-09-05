#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
// 40+11=51
// 12+41=53
// PBGPPGGB

// 268
// BPB
// 426

    vector<pair<pair<int,int>,int>> ans;

    string s, t, tmp;
    cin >> s >> t;
    for(int a = 0; a < 100; ++a) for(int b = 0; b < 100; ++b) for(int c = 0; c < 100; ++c) {
        if(a + b != c) continue;
        tmp = "";
        tmp += char('0'+a/10);
        tmp += char('0'+a%10);
        tmp += '+';
        tmp += char('0'+b/10);
        tmp += char('0'+b%10);
        tmp += '=';
        tmp += char('0'+c/10);
        tmp += char('0'+c%10);

        map<char, int> mp, smp, tm;

        bool fid = 1;
        for(auto x : s) tm[x] = 0;
        for(auto x : tmp) tm[x] = 0;

        for(int i = 0; i < 8; ++i) {
            if(t[i] == 'G' && s[i] != tmp[i]) {
                fid = 0;
                break;
            }
            if(s[i] == tmp[i] && t[i] != 'G') {
                fid = 0;
                break;
            }
            if(t[i] != 'G') {
                ++mp[tmp[i]];
                ++smp[s[i]];
            }
            if(t[i] == 'P') ++tm[s[i]];
        }
        if(fid == 0) continue;
        for(auto [x, y] : tm) {
            if(y != min(mp[x], smp[x])) {
                fid = 0;
                break;
            }
        }
        if(fid == 0) continue;
        // cout << s << endl << tmp << endl;

        ans.push_back({{a, b}, c});

    }

    cout << ans.size() << endl;
    for(auto x : ans) {
        if(x.first.first < 10) cout << "0";
        cout << x.first.first << "+";
        if(x.first.second < 10) cout << "0";
        cout << x.first.second << "=";
        if(x.second < 10) cout << "0";
        cout << x.second << endl;
    }
	return 0;
}