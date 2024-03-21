#include<bits/stdc++.h>
using namespace std;

string s;

struct state{
    int len, link;
    vector<int> next;
    vector<int> sum;
    int end;

    state() : next(26), sum(26), len(0), link(0), end(0) {}
};

const int MAXLEN = 300005;

state st[MAXLEN*2];
int sz, last;

void init() {
    st[0].len = 0;
    st[0].link = -1;
    sz++;
    last = 0;
    st[0].sum = vector<int>(26, 0);
}

void build(int c) {
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    st[cur].sum = st[last].sum; st[cur].sum[c]++;
    st[cur].end = st[cur].len;
    int p = last;
    while(p!=-1&&!st[p].next[c]) {
        st[p].next[c] = cur;
        p = st[p].link;
    }
    if(p==-1) {
        st[cur].link = 0;
    } else {
        int q = st[p].next[c];
        if(st[p].len + 1 == st[q].len) {
            st[cur].link = q;
        } else {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            st[clone].next = st[q].next;
            st[clone].link = st[q].link;
            st[clone].end = st[q].end;
            st[clone].sum = st[p].sum; st[clone].sum[c]++;
            while(p!=-1 && st[p].next[c] == q) {
                st[p].next[c] = clone;
                p = st[p].link;
            }
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    init(); 

    cin>>s;
    for(auto x : s) build(x-'a');

    long long ans = 0;
    for(int o = 1; o < sz; ++o) {
        int fa = st[o].link;
        int c = s[st[o].end-st[fa].len-1] - 'a';
        for(int i = 0; i < 26; ++i) {
            ans += 1ll*(st[o].next[i]>0)*(st[o].sum[i]-st[fa].sum[i]-(c==i));
        }
        if(st[fa].next[c]) ++ans;
    }   
    cout << ans << "\n";
    return 0;
}