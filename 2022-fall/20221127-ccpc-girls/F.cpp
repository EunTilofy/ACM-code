#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,i;
long long a[10],b[10];
bool mark[10],fl;
bool chk() {
//	if(b[1]==(0^1)&&b[2]==(0^6)&&b[3]==(1^6)&&b[4]==(0&1)&&b[5]==(0&6)&&b[6]==(6&1)) {
//		for(int i=1; i<=9; i++)printf("%d ",b[i]);
//		puts("");
//	}
	long long ans1=0, ans2=0, ans3=0;
	for(int i=0; i<60; ++i) {
		int cnt=0;
		cnt+=(b[1]>>i&1)+(b[2]>>i&1)+(b[3]>>i&1);
		if(cnt==1||cnt==3) return 0;
		if(cnt==0) {
			int ccnt=0;
			int num=0;
			ccnt+=(b[4]>>i&1)+(b[5]>>i&1)+(b[6]>>i&1);
			num = (ccnt>0);
			if(ccnt==0||ccnt==3);
			else return 0;
			ccnt-=(b[7]>>i&1)+(b[8]>>i&1)+(b[9]>>i&1);
			if(ccnt!=0) return 0;
			ans1+=num<<i;
			ans2+=num<<i;
			ans3+=num<<i;
		}
		if(cnt==2) {
			int ccnt=0;
			int cccnt=0;
			ccnt=(b[4]>>i&1)+(b[5]>>i&1)+(b[6]>>i&1);
			cccnt=(b[7]>>i&1)+(b[8]>>i&1)+(b[9]>>i&1);
			if(ccnt==1&&cccnt==3) {
				if(b[4]>>i&1) {
					ans1 += (1ll<<i), ans2 += (1ll<<i);
					if(b[1]>>i&1) return 0;
				} else if(b[5]>>i&1) {
					ans1 += (1ll<<i), ans3 += (1ll<<i);
					if(b[2]>>i&1) return 0;
				} else {
					ans2 += (1ll<<i), ans3 += (1ll<<i);
					if(b[3]>>i&1) return 0;
				}
			} else if (ccnt==0&&cccnt==2) {
				if(!(b[7]>>i&1)) {
					ans3 += (1ll<<i);
					if(b[1]>>i&1) return 0;
				} else if(!(b[8]>>i&1)) {
					ans2 += (1ll<<i);
					if(b[2]>>i&1) return 0;
				} else {
					ans1 += (1ll<<i);
					if(b[3]>>i&1) return 0;
				}
			} else return 0;
		}
	}
	if(!((ans1^ans2)==b[1])) return 0;
	if(!((ans1^ans3)==b[2])) return 0;
	if(!((ans2^ans3)==b[3])) return 0;
	if(!((ans1&ans2)==b[4])) return 0;
	if(!((ans1&ans3)==b[5])) return 0;
	if(!((ans2&ans3)==b[6])) return 0;
	if(!((ans1|ans2)==b[7])) return 0;
	if(!((ans1|ans3)==b[8])) return 0;
	if(!((ans2|ans3)==b[9])) return 0;
	cout<<ans1<<" "<<ans2<<" "<<ans3<<endl;
	return 1;
}
//int cnt=0;
void dfs(int x) {
	if(fl)return;
	if(x==8&&(b[4]&b[7])!=b[4]) return;
	if(x==9&&(b[5]&b[8])!=b[5]) return;
	if(x==10&&(b[6]&b[9])!=b[6]) return;
	if(x==10) {
//		int z=7;
//		for(int i=0; i<9; i++)if(!mark[i])b[z++]=a[i];
		if(chk())fl=1;
//		cnt++;
		return;
	}
	long long y=-1;
	for(int i=0; i<9; i++)
		if(!mark[i]&&y!=a[i]) {
			mark[i]=1,y=b[x]=a[i],dfs(x+1),mark[i]=0;
		}
}
void rdfs(int x,int z) {
	if(fl)return;
	if(x==4&&(((b[1]^b[2])^b[3])>0))return;
	else if(x==4) {
		dfs(4);
		return;
	}
	long long y=-1;
	for(int i=z; i<9; i++)
		if(!mark[i]&&y!=a[i]) {
			mark[i]=1,y=b[x]=a[i],rdfs(x+1,i+1),mark[i]=0;
		}
}
signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
//	cout<<(1<<58)<<endl;
	long long t;
	cin>>t;
//	scanf("%d",&t);
	while(t--) {
		for(i=0; i<9; i++) {
//			scanf("%lld",&a[i]);
			cin>>a[i];
		}
		sort(a,a+9);
//		cnt=0;
		fl=0;
//		dfs(1);
		rdfs(1,0);
//		printf("!%d\n",cnt);
	}
	return 0;
}