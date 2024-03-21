#include<bits/stdc++.h>
using namespace std;
struct node {
    int id, pi, t, cs, flg;
};
struct xx {
    int nm[26];
    vector<pair<int, int>> ac[26];
};
int get(int x) {
    return min(35, (x + 9) / 10);
}
int cmp(int NP, int PL, int np, int pl) {
    if(NP < np) return 0;
    if(NP > np) return 1;
    if(PL < pl) return 1;
    if(PL > pl) return 0;
    return 2;
}

void solve() {
    int n; string s;
    cin >> n;
    vector<node> a(n);
    vector<string> q;
    map<string, int> mp;
    for(int i = 0; i < n; ++i) {
        cin >> s;
        if(!mp.count(s)) {
            mp[s] = q.size();
            q.push_back(s);
        }
        a[i].id = mp[s];
        cin >> s;
        a[i].pi = s[0] - 'A';
        cin >> a[i].t;
        cin >> s;
        a[i].flg = (s[0] == 'a');
    }
    int num = q.size(), tot = 0;
    vector<int> mk(num), np(num), pl(num);
    vector<xx> tm(num);
    for(auto &x : tm) {
        memset(x.nm, 0, sizeof x.nm);
    }
    for(auto &[id, pi, t, cs, flg]: a) {
        auto &TM = tm[id];
        cs = ++TM.nm[pi];
        if(flg) {
            if(!(TM.ac[pi]).size()) np[id]++, pl[id] += (cs - 1) * 20 + t;
            TM.ac[pi].push_back({cs, t});
        }
    }
    for(int x : np) if(x) tot++;
    vector<int> rk(num);
    for(int i = 0; i < num; ++i) rk[i] = i;
    sort(rk.begin(), rk.end(), [&](int x, int y) {
        return np[x] == np[y] ? pl[x] < pl[y] : np[x] > np[y];
    });
    int np1, pl1, np2 = -1, pl2 = -1;
    int sum = 0, ssum = 0, xy = get(tot);
    for(int i = 0; i < num; ++i) {
        int j = i;
        for(; j + 1 < num && pl[rk[i]] == pl[rk[j + 1]] && np[rk[i]] == np[rk[j + 1]]; ++j) ;
        if(sum < xy) {
            np1 = np[rk[i]], pl1 = pl[rk[i]];
            for(int k = i; k <= j; ++k) mk[rk[k]] = 1;
        }
        else if(np2 == -1) ssum = sum, np2 = np[rk[i]], pl2 = pl[rk[i]];
        sum += j - i + 1;
        i = j;
    }
    // cout << get(tot) << "\n";
    // for(int i = 0; i < num; ++i) cout << q[rk[i]] << " " << np[rk[i]] << " " << pl[rk[i]] << "\n";
    int flg1 = 0;
    for(auto &[id, pi, t, cs, flg] : a) {
        int TOT = tot, NP = np[id], PL = pl[id];
        xx pos = tm[id];
        if(flg) {
            if(pos.ac[pi].size() > 1) {
                if(pos.ac[pi][0].first == cs) {
                    PL -= (cs - 1) * 20 + t;
                    auto [CS, T] = pos.ac[pi][1];
                    PL += (CS - 1) * 20 + T;
                }
            } else {
                NP--, PL -= (cs - 1) * 20 + t;
                if(!NP) TOT--;
            }
            if(cmp(np[id], pl[id], np1, pl1)) {
                if(ssum - (cmp(NP, PL, np2, pl2) != 1) < get(TOT)) flg1 = 1;
            } 
        } else {
            if(!tot) {
                mk[id] = 1;
                continue;
            }
            if(pos.ac[pi].size()) {
                auto [CS, T] = pos.ac[pi][0];
                if(CS > cs) {
                    PL -= (CS - 1) * 20 + T;
                    PL += (cs - 1) * 20 + t;
                }
            } else {
                if(!NP) TOT++;
                NP++, PL += (cs - 1) * 20 + t;
            }
            int XY = get(TOT);
            if(cmp(NP, PL, np[rk[XY - 1]], pl[rk[XY - 1]])) mk[id] = 1;
            if(get(TOT) > get(tot)) {
                int res = ssum;
                if(!cmp(np[id], pl[id], np1, pl1) && cmp(NP, PL, np2, pl2 - 1)) res++;
                if(res < get(TOT)) flg1 = 1;
            }
        }
        // cout << q[id] << " " << NP << " " << PL << "\n";
    }
    if(flg1) {
        for(int i = 0; i < num; ++i) if(np2 == np[i] && pl2 == pl[i]) mk[i] = 1;
    }
    vector<string> ans;
    for(int i = 0; i < num; ++i) if(mk[i]) ans.push_back(q[i]);
    cout << ans.size() << "\n";;
    for(auto x : ans) cout << x << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
}
/*
3
5
TSxingxing10 G 0 rejected
TSxingxing10 B 83 accepted
swun J 98 accepted
TS1 J 118 accepted
TS1 B 263 accepted
7
LetItRot A 56 rejected
LetItRot A 100 rejected
LetItRot A 120 rejected
LetItRot A 170 accepted
AllTheWayNorth A 191 accepted
LetThemRot A 200 rejected
AlltheWaySouth A 240 rejected
6
A A 1 accepted
A A 2 accepted
A A 3 rejected
A A 3 rejected
A A 3 rejected
B B 23 accepted
*/