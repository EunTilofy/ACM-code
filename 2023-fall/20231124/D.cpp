#include<bits/stdc++.h>
using namespace std;

struct node {
    int flg, x, y, t;
};
const int M = 1 << 13;
int mk[M];

int n;
void solve() {
    int m, tot;
    cin >> m >> tot;
    int sum = 0;
    vector<int> q;
    vector<node> a(n);
    for(int i = 0, x, y; i < n; ++i) {
        string s; cin >> s;
        if(s == ".") {
            a[i].flg = 0;
        } else if(s == "-") {
            cin >> x;
            a[i].flg = -1, a[i].x = x;
        } else if(s == "+") {
            cin >> s;
            int id = 0;
            for(int j = 0; j < s.size(); ++j) if(s[j] == '/') id = j;
            a[i].x = stoi(s.substr(0, id)), a[i].t = stoi(s.substr(id + 1, s.size() - id - 1));
            // cout << a[i].x << " " << a[i].t << "\n";
            m--;
            a[i].flg = 1;
            sum += (a[i].x - 1) * 20 + a[i].t;
        } else {
            // cout << s << "!!\n";
            // return ;
            assert(s == "?");
            a[i].flg = 2;
            cin >> a[i].x >> a[i].y;
            q.push_back(i);
        }
    }
    // cout << sum << "\n";
    int num = q.size();
    for(int i = 0; i < (1 << num); ++i) if(mk[i] == m) {
        vector<int> vs(n);
        int ans = sum, all = 0, fs = 0, pls = 0;
        for(int j = 0; j < num; ++j) {
            int id = q[j];
            if((i >> j) & 1) {
                vs[id] = 1;
                all += a[id].x - 1;
                ans += 240 + (a[id].y - a[id].x) * 20;
            } 
        }
        if(ans > tot) continue;
        fs = min(all, (tot - ans) / 20);
        pls = tot - ans - fs * 20;
        if(pls > m * 59) continue;
        cout << "Yes\n";
        for(int o = 0; o < n; ++o) {
            if(a[o].flg == 0) {
                cout << ".\n";
            } else if(a[o].flg == 1) {
                cout << "+ " << a[o].x << "/" << a[o].t << "\n";
            } else if(a[o].flg == -1) {
                cout << "- " << a[o].x << "\n";
            } else {
                if(!vs[o]) cout << "- " << a[o].y << "\n";
                else {
                    int x = a[o].y - a[o].x + 1, t = 240;
                    if(fs) {
                        int X = min(a[o].x - 1, fs);
                        x += X, fs -= X;
                    }
                    if(pls) {
                        int T = min(59, pls);
                        t += T, pls -= T;
                    }
                    cout << "+ " << x << "/" << t << "\n";
                }
            }
        }
        return ;
    }
    cout << "No\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 1; i < M; ++i) mk[i] = mk[i / 2] + (i & 1);
    int T; cin >> T >> n;
    for(int o = 1; o <= T; ++o) solve();   
}
/*
1 13
7 951
+ 1/6
? 3 4
+ 4/183
- 2
+ 3/217
.
.
.
+ 2/29
+ 1/91
.
+ 1/22
.
*/