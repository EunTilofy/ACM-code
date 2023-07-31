#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
template<class T> bool cmin(T &x,const T &y) { if (y<x) { x=y; return 1; }return 0; }
template<class T> bool cmax(T &x,const T &y) { if (x<y) { x=y; return 1; }return 0; }
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	string a;
	getline(cin,a);
	vector<int> id(128);
	id[' ']=1;
	vector<string> ans;
	int m=1,i;
	for (i=0; i<=9; i++) id[i+'0']=++m;
	for (i=0; i<26; i++) id[i+'A']=++m;
	for (i=0; i<26; i++) id[i+'a']=++m;
	while (a.size()&&!id[a.back()]) a.pop_back();
	int n=a.size(),j,k;
	sort(all(a)); a.resize(unique(all(a))-a.begin());
	auto cal=[&](const string &a)
		{
			int n=a.size(),i,j,k;
			string cur;
			for (i=j=0; i<n; i=j)
			{
				while (j<n&&id[a[i]]-i==id[a[j]]-j) ++j;
				if (j-i<=2) cur+=a.substr(i,j-i);
				else
				{
					char L=a[i],R=a[j-1];
					if (L=='0') L='!';
					if (L=='a') L='[';
					if (L=='A') L=':';
					cur+=L;
					cur+='-';
					cur+=R;
				}
			}
			if (cur=="") cur="!";
			return cur;
		};
	ans.push_back(cal(a));
	vector<int> ed(128);
	for (i=0; i<128; i++) if (id[i]) ed[i]=1;
	for (auto c:a) ed[c]=0;
	string b;
	for (i=0; i<128; i++) if (ed[i]) b+=i;
	ans.push_back('^'+cal(b));
	cout<<"%["<<*min_element(all(ans),[&](const auto &x,const auto &y)
		{
			if (x.size()!=y.size()) return x.size()<y.size();
			return x<y;
		})<<"]"<<endl;
}
