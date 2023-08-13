#include<bits/stdc++.h>
using namespace std;

#define int long long
const int MN = 1e6+5;
long long n, y;
long long sum[MN], num0[MN], num1[MN];
long long f[MN], F[MN];

deque<int> q;
pair<long long, long long> slp(int y, int x) {return {num0[y]-num0[x], F[y]-F[x]};}
bool cmp(pair<long long, long long> x, pair<long long, long long> y) {
    __int128 one = 1;
    __int128 xx = one * x.second * y.first;
    __int128 yy = one * x.first * y.second;
    return xx >= yy;
}
void Add(int id) {
    while(q.size() >= 2 && cmp(slp(q[q.size()-1], q[q.size()-2]), slp(id, q[q.size()-1]))) q.pop_back();
    q.push_back(id);
}
int Get(long long x) {
    while(q.size() >= 2 && cmp({1, x}, slp(q[1], q[0]))) q.pop_front();
    return q[0];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> y;
    string s;
    cin >> s;

    f[0] = -y;
    for(int i = 0; i < n; ++i) {
        num0[i+1] = num0[i] + (s[i]=='+');
        num1[i+1] = num1[i] + (s[i]=='?');
        if(s[i]=='?') sum[i+1] = sum[i] + num0[i]; 
        else sum[i+1]=sum[i];
    }
    for(int i = 1; i <= n; ++i) {
        F[i-1]=f[i-1]+y+1ll*num0[i-1]*num1[i-1]-sum[i-1];
        if(i-1==0||(s[i-2]=='+'&&s[i-1]=='?')) Add(i-1);
        int id=Get(num1[i]);
        f[i]=F[id]+sum[i]-1ll*num1[i]*num0[id];
    }
    cout << f[n] << endl;
}