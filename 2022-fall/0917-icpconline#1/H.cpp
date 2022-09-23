#include <bits/stdc++.h>
#define ll long long
#define db double
#define dbg1(x) cerr<<#x <<"="<<" "
#define dbg2(x) cerr<<#x <<"="<< " "
using namespace std;
#define mod 20220911
string s;
int a[1000005], tot;
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
    long long ans = 0;
    tot = 1;
    string s;
	while(1) {
        cin >> s;
        // cout << s << endl;
        if(s == "fin") break;
        if(s == "repeat") {
           	++tot;
            a[tot] = 0;
        }
        if(s == "for") {
        	int n;
        	cin >> n;
        	a[tot] = 1ll * a[tot] * n % mod;
        	a[tot - 1] = (a[tot - 1] + a[tot]) % mod;
            --tot;
        }
        if(s == "times");
        if(s == "library") a[tot] ++;
        if(s == "arithmetic");
    }
    printf("%d\n", a[1]);
	return 0;
}
//repeat library repeat repeat library for 3 times arithmetic library for 3 times for 100 times fin
//repeat library repeat arithmetic library for 3 times repeat library for 2 times arithmetic for 4 times arithmetic fin
