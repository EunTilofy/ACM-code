#include<bits/stdc++.h>
using namespace std;
char s[500005],ans[500005];
int l,i,cnt[26],now,L,R;
int main() {
    freopen("prefixes.in", "r", stdin);
	freopen("prefixes.out", "w", stdout);
	scanf("%s",s),l=strlen(s),R=l-1;
	for(i=0; i<l; i++)cnt[s[i]-'a']++,now=min(now,s[i]-'a');
	for(i=l-1; i>=0; i--) {
		while(!cnt[now])now++;
		if(now==s[i]-'a')ans[L]=s[i],L++;
		else ans[R]=s[i],R--;
		cnt[s[i]-'a']--;
	}
	printf("%s",ans);
	return 0;
}