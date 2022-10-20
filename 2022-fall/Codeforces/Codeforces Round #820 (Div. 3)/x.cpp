#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int len, m;
char s[N];

bool check1(int l, int r) {
	if(l > r) return false;
	if(r > l && s[l] == '0' && s[l + 1] == '0') return false;
	return true;
}

bool check2(int l, int r) {
	for(int i = l; i <= r; ++i)
		if(s[i] < 'a' || s[i] > 'z') return false;
	return true;
}

pair<int, int> num(int be) {
	if(s[be] != 'i') return make_pair(be, 3);
	for(int i = be; i < len; ++i) {
		if(s[i] >= '0' && s[i] <= '9') {
			2333;
		} else if(s[i] == 'e') {
			if(check1(be + 1, i - 1)) return make_pair(i + 1, 0);
			else return make_pair(i + 1, 1);
		} else return make_pair(i, 1);
	}
	return make_pair(len, 1);
}

pair<int, int> str(int be) {
	int pos = 0, now;
	for(int i = be; i < len; ++i) {
		if(s[i] >= '0' && s[i] <= '9') {
			pos = pos * 10 + s[i] - '0';
		} else if(s[i] == ':') {
			if(check1(be, i - 1)) {now = i + 1; break;}
			else return make_pair(be, 2);
		} else return make_pair(be, 2);
	}
	if(check2(now, min(len - 1, now + pos - 1))) return make_pair(now + pos, now + pos - len);
	for(int i = now; i < len; ++i) {
		if(s[i] < 'a' || s[i] > 'z') return make_pair(i, now + pos - i);
	}
}

pair<int, int> lis(int be) {
	
}

int main() {
	scanf("%d%s", &m, s);

	return 0;
}