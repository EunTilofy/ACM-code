#include<bits/stdc++.h>
using namespace std;

int n;
string s[15005];
#define psi pair<string, int>
pair<string, int> sol2(int num, int now) {
    int k=31;
    if(num == 0) return {"", now};
    while(!((num>>k)&1)) {
        --k;
    }
    string r="";
    while(k>=0) {
        if(!((num>>k)&1)) {
            psi _ = sol2(2, now);
            now = _.second;
            r="("+r+"*"+_.first+")";
        }
        else {
            psi _;
            if(r!="") _=sol2(2, now);
            else _={"",now};
            now = _.second;
            if(s[now]=="x") s[now]="s(s(s("+s[now]+")))";
            if(r!="") r="(("+r+"*"+_.first+")"+s[now]+")";
            else r="("+s[now]+")";
            ++now;
        }
        --k;
    }
    return {r, now};
}
pair<string, int> sol(int num, int now) {
    psi _ = sol2(num, now);
    now = _.second;
    string s2="";
    while(s[now]!="x") {
        if(s2.size()) s2=s2+'*'+s[now];
        now++;
    }
    s2=s2+'*'+s[now]; now++;
    return {"("+_.first+"-("+s2+"))", now};
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> s[i];
        if(s[i]!="x"&&s[i]!="1") s[i]="s(s(s("+s[i]+")))";
    }
    int m;
    cin >> m;
    vector<string> ans;
    int now = 0;
    string pre="s(s(s(s(s(s(s(s(s(s(s(s(s(s(s(s(s(s(",suf="))))))))))))))))))";
   
    for(int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        string S = "";
        for(int j = 1; j <= 9; ++j) if(j != x) {
            pair<string, int> _ = sol(j, now);
            now = _.second;
            S = S + "*" + _.first + "";
        }
        pair<string, int> _ = sol2(y, now);
        now = _.second;
        S=pre+S+suf+"*"+_.first+"";
        ans.push_back(S);
    }
    for(int i = 0; i < ans.size(); ++i) {
        if(i) cout << "+";
        cout << ans[i];
    }
    cout << ")";
    for(int j = now; j <= n; ++j) {
        if(s[j]=="x") s[j]="s(s(s("+s[j]+")))";
        cout << "*" << s[j]; 
    }
    cout << "\n";
    return 0;
}