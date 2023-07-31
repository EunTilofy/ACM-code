#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7, MN = 50005;

int Mul(int x, int y) {
	return (1ll * x * y) % mod;
}

int Add(int x, int y) {
	return (x + y) % mod;
}

int fpow(int x, long long y) {
	int r = 1;
	for(; y; y>>=1, x = Mul(x, x)) if(y & 1) r = Mul(r, x);
	return r;
}

map<char, int> v;
string s;
int findnex(int l, int r) {
	int j, k = 0;
	for(j = l; j <= r;++j) {
		// cerr << "in findnex : " << "i = " << j << " " << s[j] << endl;
		if(s[j] == '{') ++k;
		else if(s[j] == '}') --k;
		if(k == -1) return j;
	}
	return r;
}

int solve(int l, int r) {
	// cerr << "l = " << l << ", r = " << r << endl;
	// for(int i = l; i <= r; ++i) cerr << s[i];cerr << endl;
	int opt = 0;
	// 0 : + 1 : - 2 : cdot
	vector<int> val;
	for(int i = l; i <= r; ++i) {
		// cerr << "s[" << i << "] = " << s[i] << endl; 
		int x = 0;
		if(s[i] == '\\') {
			++i;
			if(s[i] == 's') { // sum
			// \sum_{k=[Tex1]}^{[Tex2]}\left({[Tex3]}\right)
				i += 5;
				char dig = s[i];
				i += 2;
				int _l = i, _r = findnex(i, r) - 1;
				v[dig] = solve(_l, _r);
				i = _r + 4;
				int L = i, R = findnex(L, r) - 1;
				i = R + 9;
				int LL = i;
				int RR = findnex(LL, r) - 1;
				i = RR + 8;
				int tmp = 0;
				while(v[dig] <= solve(L, R)) {
					tmp = Add(tmp, solve(LL, RR));
					++v[dig];
				}
				x = tmp;
			} else if(s[i] == 'p') { // prod
			// \prod_{k=[Tex1]}^{[Tex2]}\left({[Tex3]}\right)
				i += 6;
				char dig = s[i];
				i += 2;
				int _l = i, _r = findnex(i, r) - 1;
				v[dig] = solve(_l, _r);
				i = _r + 4;
				int L = i, R = findnex(L, r) - 1;
				i = R + 9;
				int LL = i;
				int RR = findnex(LL, r) - 1;
				i = RR + 8;
				int tmp = 1;
				while(v[dig] <= solve(L, R)) {
					tmp = Mul(tmp, solve(LL, RR));
					++v[dig];
				}
				x = tmp;
			} else if(s[i] == 'm' && s[i + 1] == 'i') { // min
			// \min\left({[Tex1]},{[Tex2]}\right)
				int x1, x2;
				i += 10;
				int j = findnex(i, r) - 1;
				x1 = solve(i, j);
				i = j + 4;
				j = findnex(i, r) - 1;
				x2 = solve(i, j);
				i = j + 8;
				x = min(x1, x2);
			} else if(s[i] == 'm' && s[i + 1] == 'a') { // max
			// \max\left({[Tex1]},{[Tex2]}\right)
				int x1, x2;
				i += 10;
				int j = findnex(i, r) - 1;
				x1 = solve(i, j);
				i = j + 4;
				j = findnex(i, r) - 1;
				x2 = solve(i, j);
				i = j + 8;
				x = max(x1, x2);
			} else if(s[i] == 'f') { // frac
			// \frac{[Tex1]}{[Tex2]}
				int x1, x2;
				i += 5;
				int j = findnex(i, r) - 1;
				x1 = solve(i, j);
				i = j + 3;
				j = findnex(i, r) - 1;
				x2 = solve(i, j);
				i = j + 1;
				x = Mul(x1, fpow(x2, mod - 2));
			} else if(s[i] == 'c') { // codt
			// \cdot 
				opt = 2;
				i += 4;
				// cerr << "get a cdot " << "s[i] = " << s[i] << "i = " << i << endl;
				continue;
			} else if(s[i] == 'l') { // left
			// \left({[Tex]}\right)
				i += 6;
				int j = findnex(i, r) - 1;
				x = solve(i, j);
				i = j + 8;
			}
		}
		else if (s[i] == '+') {
			opt = 0;
			continue;
		} else if(s[i] == '-') {
			opt = 1;
			continue;
		} else if(s[i] <= '9' && s[i] >= '0') {
			x = s[i] - '0';
			while(i + 1 <= r && s[i + 1] <= '9' && s[i + 1] >= '0') {
				++i;
				x = Add(s[i] - '0', Mul(x, 10));
			}
		} else if(s[i] <= 'z' && s[i] >= 'a') {
			x = v[s[i]];
		}
		// cerr << "x = " << x << endl;
		if(opt == 2) x = Mul(val.back(), x), val.pop_back(), val.push_back(x);
		else if(opt == 1) val.push_back(mod-x);
		else val.push_back(x);
	}
	int ans = 0;
	for(auto x : val) {
		ans = Add(ans, x);
		
		// cerr << "final : " << x << endl;
	}
	return ans;
}

int main() {
	getline(cin, s);

	cout << solve(0, s.size() - 1) << endl;

	return 0;
}