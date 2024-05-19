#include<bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

const int N = 6e6+5;
const int mod = 998244353;
int Add(int x, int y) { return (x+y)%mod; }
int Dec(int x, int y) { return (x-y+mod)%mod; }
int Mul(int x, int y) { return (1ll*x*y)%mod; }

namespace PAC 
{
    int sz, tot, last;
    int cnt[N], ch[N][10], len[N], fail[N];
    char s[N];

    int node(int l)
    {
        sz++;
        memset(ch[sz], 0, sizeof(ch[sz]));
        len[sz] = l;
        fail[sz] = cnt[sz] = 0;
        return sz;
    }

    void clear()
    {
        sz = -1;
        last = 0;
        s[tot = 0] = '$';
        node(0);
        node(-1);
        fail[0] = 1;
    }

    int getfail(int x) 
    {
        while(s[tot - len[x] - 1] != s[tot])
        {
            x = fail[x];
        }
        return x;
    }

    void insert(char c, int L)
    {
        s[++tot] = c;
        int now = getfail(last);
        if(!ch[now][c - '0'])
        {
            int x = node(len[now] + 2);
            fail[x] = ch[getfail(fail[now])][c - '0'];
            ch[now][c - '0'] = x;
        }
        last = ch[now][c - '0'];
        cnt[last] += L;
    }

    ll solve(int n)
    {
        ll ans = 0;
        for (int i = sz; i >= 0; --i) 
        {
            cnt[fail[i]] = Add(cnt[fail[i]], cnt[i]);
        }
        for (int i = 2; i <= sz; ++i)
        {
            if(len[i] > n) continue;
            // cerr << len[i] << " " << cnt[i] << " " << cnt[i] << "\n";
            ans = Add(ans, Mul(len[i], Mul(cnt[i], cnt[i])));
        }
        return ans;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    std::string s;
    cin >> s;
    PAC::clear();
    for(int i = 1; i < n*2; ++i) 
    {
        // cerr << s[i<=n?i-1:i-n-1] << "\n";
        PAC::insert(s[i<=n?i-1:i-n-1], (i>=n?1:0));
    }
    cout << PAC::solve(n);
    return 0;
}

/*
0
1
0
1
0
0
1
0
1
1 3 3
1 2 2
3 2 2
3 1 1
5 1 1
2 1 1
4 1 1
6 1 1
8 1 1

*/