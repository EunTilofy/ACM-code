#include<bits/stdc++.h>
using namespace std;
int m,d,c,l,x,v,i,j,h,res[50],q[4];
int main() {
	scanf("%d%d%d%d%d%d%d",&m,&d,&c,&l,&x,&v,&i);
	res[30]+=m/3;
	if(m%3==2)res[29]++;
	else if(m%3==1)res[28]++;
	res[21]+=c/3;
	if(c%3==2)res[20]++;
	else if(c%3==1)res[19]++;
	res[12]+=x/3;
	if(x%3==2)res[11]++;
	else if(x%3==1)res[10]++;
	res[3]+=i/3;
	if(i%3==2)res[2]++;
	else if(i%3==1)res[1]++;
	if(d<=res[21])res[26]=d,res[21]-=d;
	else {
		res[26]+=res[21],d-=res[21],res[21]=0;
		if(d&&res[20])d--,res[20]--,res[25]++;
		if(d&&res[19])d--,res[19]--,res[24]++;
		res[23]+=d;
	}
	if(l<=res[12])res[17]=l,res[12]-=l;
	else {
		res[17]+=res[12],l-=res[12],res[12]=0;
		if(l&&res[11])l--,res[11]--,res[16]++;
		if(l&&res[10])l--,res[10]--,res[15]++;
		res[14]+=l;
	}
	if(v<=res[3])res[8]=v,res[8]-=v;
	else {
		res[8]+=res[3],v-=res[3],res[3]=0;
		if(v&&res[2])v--,res[2]--,res[7]++;
		if(v&&res[1])v--,res[1]--,res[6]++;
		res[5]+=d;
	}
	for(j=0; j<4; j++) {
		for(h=j*9+1; h<=j*9+9; h++)q[j]+=res[h];
	}
	return 0;
}