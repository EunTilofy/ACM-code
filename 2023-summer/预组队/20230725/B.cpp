#include<bits/stdc++.h>
using namespace std;
typedef pair<int, string> pis;

string s;
string num[30000]; int dig[30000];

pis operator +(const pis&a, const pis&b) {
    return {max(a.first, b.first), a.second + b.second};
}
string get(int l, int r) {
    return num[l]+","+num[r]+":";
}
int lb(int l, int r, int pos) {
    pos += (r - l + 1) * (dig[pos] + 1);
    return dig[pos];
} 

pis solve(int pos, int l, int r) {
    if(r-l==1) {
        for(int i = pos + 4; true;++i) {
            if(pos+dig[i]*2+2==i) {
                return {i, get(i, i)};
            }
        }
        return {0, ""};
    }
    int ret = 0;
    for(int i = l; i <= r; ++i) {
        if(s[i]=='(') ++ret;
        else --ret;
        if(ret == 0 && i != r) {
            pis tmp = solve(pos, l, i);
            tmp = tmp + solve(tmp.first, i+1, r);
            return tmp;
        }
    }
    for(int digr = lb(l, r, pos); digr <= 5; ++digr) {
        int numl = pos + dig[pos] + 2 + digr;
        if(dig[numl] > dig[pos]) ++numl;
        pis tmp = solve(pos + dig[numl] + 2 + digr, l + 1, r - 1);
        if(dig[tmp.first] == digr) {
            tmp.second = get(numl, tmp.first) + tmp.second;
            return tmp;
        }
    }
    return {0, ""};
}

int main() {
    cin >> s;

    for(int i = 0; i < 30000; ++i){
        if(i<10) {
            num[i]=num[i]+((char)('0'+i));
            dig[i]=1;
        } else {
            num[i]=num[i/10]+(char)('0'+(i%10));
            dig[i]=dig[i/10]+1;
        }
    }
    pis ans = solve(0, 0, s.size() - 1);
    cout << ans.second;
    return 0;
}