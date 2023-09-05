#include<bits/stdc++.h>
using namespace std;
#define MN 200005
#define mod 998244353
string s;
int n, nt;
class AC{
public:
    int tr[MN][26], cnt, e[MN], ffail[MN], fail[MN], dep[MN];
    void insert(string t, int v) {
        int p = 0;
        for(int i = 0; i < t.size(); ++i) {
            int k = t[i] - 'a';
            if(!tr[p][k]) {
                tr[p][k] = ++cnt;
                dep[cnt]=dep[p]+1;
            }
            p = tr[p][k];
        }
        e[p] = (e[p] + v) % mod;
    } 
    void build() {
        queue<int>q;
        for(int i=0;i<26;++i)if(tr[0][i])q.push(tr[0][i]);
        while(!q.empty()) {
            int k=q.front();q.pop();
            for(int i=0;i<26;++i) 
                if(tr[k][i]) {
                    fail[tr[k][i]]=tr[fail[k]][i], q.push(tr[k][i]);
                    if(e[fail[tr[k][i]]]>0) ffail[tr[k][i]] = fail[tr[k][i]];
                    else ffail[tr[k][i]] = ffail[fail[tr[k][i]]];
                }
            else tr[k][i] = tr[fail[k]][i];
        }
        
    }
    void query(string s) {
        int p = 0;
        int n = s.size();
        vector<int> ans(n);
        for(int i = 0; i < n; ++i) {
            p = tr[p][s[i]-'a'];
            if(i) ans[i]=ans[i-1];
            else ans[i]=1;
            for(int j = p; j; j = ffail[j]) if(e[j]>0){
                if(i-dep[j]>=0) ans[i]=(ans[i]+1ll*ans[i-dep[j]]*e[j]%mod)%mod;
                else ans[i]=(ans[i]+1ll*e[j])%mod;
            }
            cout << ans[i] << " ";
        }
    }
}ac;

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    cin >> s >> nt;
    for(int i = 1; i <= nt; ++i) {
        string t; cin >> t;
        int val; cin >> val;
        ac.insert(t, val);
    }
    ac.build();
    ac.query(s);
}