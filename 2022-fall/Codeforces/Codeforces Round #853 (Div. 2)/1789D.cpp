#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define all(x) x.begin(),x.end()
string s, t;
string XOR(string a, string b, int n) {
    string r="";
    for(int i = 0; i < n; ++i) {
        if(a[i] == b[i]) r+='0';
        else r+='1';
    }
    return r;
}
string tr(string a, int st, int n) {
    string r="";
    for(int i = 0; i < n; ++i) {
        if(i+st<n&&i+st>-1) r+=a[i+st];
        else r+='0';
    }
    return r;
}
void solve(){
	int n;
    cin >> n >> s >> t;
    int ss = -1, tt = -1;
    for(int i = 0; i < n; ++i) if(s[i]=='1'){ss=i;break;}
    for(int i = 0; i < n; ++i) if(t[i]=='1'){tt=i;break;}
    if((ss==-1&&tt==-1) || s==t) {
        cout << "0" << endl;
        return;
    }
    if(ss==-1||tt==-1) {
        cout << "-1" << endl;
        return ;
    }
    vector<int> opt;
    if(ss < tt) {
        int sss = -1;
        for(int i = n-1; ~i; --i) {if(s[i]=='1'){sss=i;break;}}
        if(sss<tt) {
            s = XOR(s, tr(s, ss-tt, n), n);
            opt.push_back(ss-tt);
            sss = -1;
            for(int i = n-1; ~i; --i) {if(s[i]=='1'){sss=i;break;}}
        }
        for(int i = tt-1;~i;--i) {
            if(s[i]=='1') {
                s = XOR(s, tr(s, sss-i, n), n);
                opt.push_back(sss-i);
            }
        }
        ss = -1;
        for(int i = 0; i < n; ++i) if(s[i]=='1'){ss=i;break;}
    }
    if(ss > tt) {
        s = XOR(s, tr(s, ss-tt, n), n);
        opt.push_back(ss-tt);
        ss=tt;
    }
    if(s != t) {
        for(int i = ss + 1; i < n; ++i) {
            if(s[i]!=t[i]) s = XOR(s, tr(s, ss-i, n), n),opt.push_back(ss-i);
        }
    }
    if(opt.size()>n) {
        cout << "-1" << endl;
        return ;
    }
    cout << opt.size() << endl;
    for(auto x : opt) cout << x << " ";
    cout << endl;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) 
		solve();
}