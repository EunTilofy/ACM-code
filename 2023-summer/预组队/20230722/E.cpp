#include<bits/stdc++.h>
using namespace std;

long long f[2][10][75];
string s;
int a[75];
long long dfs(int dig, int up, int pre, bool sky, bool dec) {
    if(dig > up) {
        return 1;
    }
    if(!sky) {
        if(f[dec][pre][up-dig+1]) return f[dec][pre][up-dig+1];
        long long sum = 0;
        for(int i = 0; i < 10; ++i) {
            if(dec+(i>pre)<2)
                sum += dfs(dig+1, up, i, 0, dec|(i<pre));
        }
        f[dec][pre][up-dig+1]=sum;
        return sum;
    } else {
        long long sum = 0;
        int _ = a[dig];
        for(int i = 0; i < _; ++i) {
            if(dec+(i>pre)<2)
                sum += dfs(dig+1, up, i, 0, dec|(i<pre));
        }
        if(dec+(_>pre)<2) sum += dfs(dig+1, up, _, 1, dec|(_<pre));
        return sum;
    }
}

long long solve() {
    cin >> s;
    int pos1=s.size(), pos2=0;
    for(int i = 0; i < s.size(); ++i) a[i]=s[i]-'0';
    for(int i = 1; i < s.size(); ++i) {
        if(s[i-1]<s[i]) pos2=max(pos2, i);
        if(s[i-1]>s[i]) pos1=min(pos1, i);
    }
    if(pos1<pos2)return -1;
    return dfs(0, s.size()-1, 0, 1, 0)-1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        cout << solve() << "\n";
    }
    return 0;
}

