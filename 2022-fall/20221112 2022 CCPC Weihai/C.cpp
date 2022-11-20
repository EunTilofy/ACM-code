#include<bits/stdc++.h>
using namespace std;
int n;
struct VEC{
	double x, y;
}a[300000];
bool b[300000];
typedef double NUM;
const NUM EPS=1e-12;
inline NUM cmp(NUM a, NUM b) {
	return fabs(a-b)>=EPS+fabs(a)*EPS?a-b:0;
}
VEC operator +(VEC a, VEC b) {
	return (VEC){a.x+b.x, a.y+b.y};
}
VEC operator -(VEC a, VEC b) {
	return (VEC){a.x-b.x, a.y-b.y};
}
NUM operator %(VEC a, VEC b){
	return a.x*b.x+a.y*b.y;
}
NUM cmp_side(VEC a, VEC b) {
	return cmp(a.x*b.y, a.y*b.x);
}
int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int T;
	cin>>T;
	while(T--) {
		cin>>n;
		for(int i = 1; i <= n; ++i) cin>>a[i].x>>a[i].y;
		if(n < 5) {
			cout<<"NO"<<endl;
			continue;
		}
		int fl = 0;
		for(int i = 3; i <= n; ++i) {
			if(cmp_side(a[i]-a[1],a[2]-a[1])!=0) {fl = i; break;}
		}
		if(!fl) {
			cout<<"NO"<<endl;
			continue;
		}
		for(int i = 1; i <= n; ++i) b[i] = 0;
		b[1] = b[2] = b[fl] = 1;
		for(int j = 1; j <= n; ++j) if(!b[j]) {b[j] = 1; break;}
		for(int j = 1; j <= n; ++j) if(!b[j]) {b[j] = 1; break;}
		vector<VEC> c;
		for(int i = 1; i <= n; ++i) if(b[i]) c.push_back(a[i]);
		for(int i = 0; i < 5; ++i) {
			bool _ = 1;
			for(int j = 0; j < 5; ++j) for(int k = 0; k < 5; ++k) 
				if(i != j && i != k && j != k) {
					if(cmp_side(c[i]-c[j], c[i]-c[k])==0) {
						if(((c[i]-c[j])%(c[i]-c[k]))>0) {_ = 0; break;}
					}
				}
			if(_) {
//				cout<<"find"<<c[i].x<<" "<<c[i].y<<endl;
				swap(c[0], c[i]);
				break;
			}
		}
		cout<<"YES"<<endl;
		for(int i = 0; i < 5; ++i) {
			cout<<fixed<<setprecision(0)<<c[i].x<<" "<<c[i].y<<endl;
		}
	}
	return 0;
}