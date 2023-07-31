#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

string name="std",cmd[301];
void gen(int i){
	system(("maker.exe > "+to_string(i)+".in "+to_string(ull(i*time(0)))+" "+cmd[i]+" "+to_string(i)+".in").c_str());
	system((name+".exe < "+to_string(i)+".in > "+to_string(i)+".out ").c_str());
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("cmds.in","r",stdin);
	int T;
	cin>>T;
	getline(cin,cmd[0]);
	for(int i=1;i<=T;++i)getline(cin,cmd[i]);
	for(int i=1;i<=T;++i)gen(i);
}