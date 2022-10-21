#include<bits/stdc++.h>
using namespace std;
#define M 100005
#define int long long
long long sum[26],cnt[26],now,res[M][26];
int k,i,j,l,st[M],si,pos[M],x,num[M],fa[M];
char s[M];
#define INF 1000000000000
void chk(long long &x) {
	if(x>INF)x=-1;
}
void calc(int l,int r,int y) {
	for(int i=0; i<26; i++)
		if(res[l][i]==-1)sum[i]=-1;
		else if(sum[i]!=-1) {
			__int128 RES = res[l][i];
			RES = RES * y;
			if(RES > INF) sum[i]=-1;
			else sum[i]+=res[l][i]*y,chk(sum[i]);
		}
	now+=res[l][0]*y;
//	printf("%d %d\n",res[l][0],res[l][25]);
}
void did(int l,int r) {
	int L=0,R=num[l],mid,ans;
	while(L<=R) {
		mid=L+R>>1;
		__int128 RES = res[l][0];
		RES = RES * mid;
		if(res[l][0]!=-1&&RES<INF&&res[l][0]*mid+now<k)ans=mid,L=mid+1;
		else R=mid-1;
	}
//	printf("%d %d %d %d %lld\n",l,r,ans,now,sum[25]);
	calc(l,r,ans);
//	printf("%d %d %d %d %lld\n",l,r,ans,now,sum[25]);
	if(ans==num[l])return;
	for(int i=l+1; i<r; i++) {
		if(s[i]=='(')did(i,pos[i]),i=pos[i];
		else {
			if('a'<=s[i]&&s[i]<='z'&&sum[s[i]-'a']!=-1)sum[s[i]-'a']++,chk(sum[s[i]-'a']);
			if(s[i]=='a')now++;
		}
		if(now==k)return;
	}
}
bool mark[26];
signed main() {
	freopen("az.in", "r", stdin);
	freopen("az.out", "w", stdout);
	scanf("%s",s+1),l=strlen(s+1),scanf("%lld",&k);
	for(i=1; i<=l; i++)
		if(s[i]=='(')fa[i]=st[si],st[++si]=i,num[i]=x,x=0;
		else if(s[i]==')') {
			if(fa[st[si]]) {
				for(j=0; j<26; j++)
					if(res[st[si]][j]==-1)res[fa[st[si]]][j]=-1;
					else if(res[fa[st[si]]][j]!=-1) {
						__int128 RES = res[st[si]][j];
						RES = RES * num[st[si]];
						if(RES > INF)res[fa[st[si]]][j]=-1;
						else res[fa[st[si]]][j]+=res[st[si]][j]*num[st[si]],chk(res[fa[st[si]]][j]);
					}
			}
			pos[st[si]]=i,si--;
		} else if('0'<=s[i]&&s[i]<='9')x=x*10+s[i]-'0';
		else if(s[i]>='a'&&s[i]<='z') {
			mark[s[i]-'a']=1;
			if(res[st[si]][s[i]-'a']!=-1)res[st[si]][s[i]-'a']++,chk(res[st[si]][s[i]-'a']);
		}
	for(i=1; i<=l; i++)
		if(s[i]=='(') {
			__int128 RES = res[i][0];
			RES = RES * num[i];
			if(res[i][0]==-1||RES>INF||res[i][0]*num[i]+now>=k) {
				did(i,pos[i]);
				break;
			} else {
				calc(i,pos[i],num[i]);
			}
			i=pos[i];
		} else {
			if('a'<=s[i]&&s[i]<='z'&&sum[s[i]-'a']!=-1)sum[s[i]-'a']++,chk(sum[s[i]-'a']);
			if(s[i]=='a')now++;
			if(now==k)break;
		}
	for(i=0; i<26; i++)
		if(mark[i])printf("%c %lld\n",i+'a',sum[i]);
	return 0;
}