#include<bits/stdc++.h>
using namespace std;

const int MN = 45;
int n;
long long W;
string s[MN];
int u[MN], v[MN];
#define INF 100000000000LL

vector<vector<int>> lst;
struct Data {
	Data(int leftW) : cost(leftW), gain(-INF), data_id(0) {}
	Data() {}
	long long gain;
	long long cost;
	int data_id;
	bool operator < (const Data &y) const {
		return cost < y.cost || (cost == y.cost && gain > y.gain);
	}
}; int cnt = 0;
Data ans;
vector<Data> tmp, lef;

long long now_gain = 0ll, now_cost = 0ll;
void dfs(int l, int r, vector<int>& now, bool type) {
	if(l > r) {
		if(type == 0) {
			Data o; o.data_id = cnt ++;
			o.gain = now_gain;
			o.cost = now_cost;
			lst.push_back(now);
			tmp.push_back(o);
		} else {
			int leftW = W - now_cost;
			auto it = upper_bound(lef.begin(), lef.end(), Data(leftW));
			if(it != lef.begin()) {
				--it;
				if(it->gain + now_gain > ans.gain) {
					ans.gain = it->gain + now_gain;
					ans.cost = it->cost + now_cost;
					ans.data_id = cnt ++;
					lst.push_back(now);
					for(auto id : lst[it->data_id]) {
						lst.back().push_back(id);
					}
				}
			} else if(now_cost <= W && now_gain > ans.gain) {
				ans.gain = now_gain;
				ans.cost = now_cost;
				ans.data_id = cnt ++;
				lst.push_back(now);
			}
		}
		return;
	}
	
	now_gain += u[l];
	now_cost += v[l];
	now.push_back(l);
	dfs(l + 1, r, now, type);

	now_gain -= u[l];
	now_cost -= v[l];
	now.pop_back();
	dfs(l + 1, r, now, type);
}

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> W;
	for (int i = 1; i <= n; ++i)
	{
		cin >> s[i];
		cin >> u[i] >> v[i];
		v[i] = -v[i]; // u : gain, v : cost
	}

	vector<int> left, right;
	ans.gain = ans.cost = 0;

	dfs(1, n/2, left, 0);

	sort(tmp.begin(), tmp.end());

	for(auto &o : tmp) {
		if(lef.size() == 0 || o.gain > lef.back().gain) {
			lef.push_back(o);
		}
	} tmp.clear();

	dfs(n/2+1, n, right, 1);

	cout << ans.gain << endl;
	for(auto id : lst[ans.data_id]) cout << s[id] << endl;

	return 0;
}