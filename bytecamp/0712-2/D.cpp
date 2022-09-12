#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10, M = 1e6 + 10;
struct node {
	int x, y, v;
} a[N];
vector<int> qc[M], qr[M];
int c[M], r[M], p[M];
multiset<int> s;

void Add() {
	int sz = s.size();
	for(int i = sz; i <= 3; ++i)
		s.insert(0);
}

int pd[3];
multiset<int> :: iterator it;
int get() {
	int pos = 0;
	for(int i = 0; i < 2; ++i) {
		it = s.end(); it--;
		pd[i] = *it;
		s.erase(it);;
	}
	for(int i = 0; i < 2; ++i) {
		pos += pd[i];
		s.insert(pd[i]);
	}
	return pos;
}

void upd(int x, int pls) {
	s.erase(s.find(x));
	s.insert(x + pls);
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].v);
		qc[a[i].y].push_back(i);
		qr[a[i].x].push_back(i);
		c[a[i].y] += a[i].v, r[a[i].x] += a[i].v;
	}
	for(int i = 0; i < M; ++i) p[i] = c[i];
	sort(p, p + M);
	int ans = 0, pos = 0;
	for(int i = M - 1; i >= M - 3; --i) pos += p[i];
	ans = max(ans, pos);
	pos = 0;
	for(int i = 0; i < M; ++i) p[i] = r[i];
	sort(p, p + M);
	for(int i = M - 1; i >= M - 3; --i) pos += p[i];
	ans = max(ans, pos);
	for(int i = 0; i < M; ++i) {
		if(r[i]) s.insert(r[i]);
	}
	Add();
	for(int i = 0; i < M; ++i) {
		int sz = qc[i].size();
		if(!sz) continue;
//		printf("nw===%d\n", i);
		pos = c[i];
		for(int j = 0; j < sz; ++j) {
			int id = qc[i][j];
			upd(r[a[id].x], -a[id].v);
		}
		pos += get();
//		if(pos == 7) printf("WTTSFDSG%d\n", i);
		ans = max(ans, pos);
		for(int j = 0; j < sz; ++j) {
			int id = qc[i][j];
			upd(r[a[id].x] - a[id].v, a[id].v);
		}
	}
	s.clear();
	for(int i = 0; i < M; ++i) 
		if(c[i]) s.insert(c[i]);
	Add();
	for(int i = 0; i < M; ++i) {
		int sz = qr[i].size();
		if(!sz) continue;
//		printf("nww===%d\n", i);
		pos = r[i];
		for(int j = 0; j < sz; ++j) {
			int id = qr[i][j];
			upd(c[a[id].y], -a[id].v);
		}
		pos += get();
//		if(pos == 7) printf("%dWTF!!!\n", i);
		ans = max(ans, pos);
		for(int j = 0; j < sz; ++j) {
			int id = qr[i][j];
			upd(c[a[id].y] - a[id].v, a[id].v);
		}
	}
	printf("%d\n", ans);
	return 0;
}