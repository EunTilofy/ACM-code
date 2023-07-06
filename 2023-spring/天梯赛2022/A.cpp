#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")

#include<bits/stdc++.h>
using namespace std;
int n;
int cnt;
map<string, int> all;
vector<string> fin;
vector<int> G[10005];
vector<string> GG;
map<string, int> id;
string str[10005];
int deg[10005];

struct node{
    string s;
    vector<string> t;
    int len;
    void ycl() {
        string tt = "";
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '.' || i == s.size() - 1) {
                if(i == s.size() - 1) tt += (char)s[i];
                t.push_back(tt);
                if(all.count(tt));
                else {
                    all[tt] = cnt++;
                    fin.push_back(tt);
                }
                tt = "";
            }
            else tt = tt + (char)s[i];
        }
        len = t.size();
        // for(auto x : t) cout << x << endl;
        // cout << endl;
    }
}a[100005];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i].s;
        a[i].ycl();
    }
    for(int i = 1; i <= n; ++i) {
        int j = i;
        while(j + 1 <= n && a[j+1].len == a[i].len) ++j;
        for(int k = i; k < j; ++k) {
            for(int s = 0; s < a[k].len; ++s) {
                if(a[k].t[s] == a[k+1].t[s]) continue;
                else {
                    int x1 = all[a[k].t[s]];
                    int x2 = all[a[k+1].t[s]];
                    G[x1].push_back(x2);
                    ++deg[x2];
                    break;
                }
            }
        }
        i = j;
    }
    for(auto x : fin) GG.push_back(x);
    sort(GG.begin(), GG.end());
    for(int i = 0; i < GG.size(); ++i) {
        id[GG[i]] = GG.size()-1-i;
        str[GG.size()-1-i] = GG[i];
    }
    priority_queue<int> q; 
    for(int i = 0; i < cnt; ++i) if(!deg[i]) q.push(id[fin[i]]);
    int out = 0;
    while(!q.empty()) {
        if(!out) out = 1;
        else cout << ".";
        string t = str[q.top()];
        cout << t;
        int x = all[t];
        q.pop();
        for(auto y : G[x]) {
            if(!--deg[y]) q.push(id[fin[y]]);
        }
    }
    return 0;
}