#include<bits/stdc++.h>
using namespace std;
// char s[2] = {'0', '1'};
char s[2] = {'b', 'r'};
void brute(int n){
    vector<pair<int,int>>q;
    for(int i=0;i<(1<<n);i++){
        int res=0;
        for(int j=0;j<n;j++){
            for(int k=j;k<n;k++){
                int x=0;
                for(int l=j;l<=k;l++){
                    if(i>>l&1)x^=1;
                }
           //     cout<<i<<" "<<j<<' '<<k<<x<<endl;
                res+=x;
            }
        }
        q.push_back({res,i});
    }
    sort(q.begin(),q.end());
    int cnt = 0;
    for(auto [v,w]:q){
        if(v!=q.back().first)continue;
        // cout << "\"";
        for(int i=n-1;i>=0;i--)cout<<s[(w>>i&1)];
        // cout << "\"";
        cout<<endl;
        ++cnt;
        if(cnt == 100) break;
    //    cout<<endl;
    }
}

vector<int> t[205];

string tab0[] = {
"0001001",
"0001010",
"0001011",
"0001101",
"0001110",
"0001111",
"0010010",
"0010100",
"0010101",
"0010111",
"0011001",
"0011010",
"0011011",
"0011101",
"0011110",
"0011111",
"0100100",
"0101000",
"0101001",
"0101011",
"0101110",
"0110001",
"0110010",
"0110011",
"0110101",
"0110110",
"0110111",
"0111010",
"0111100",
"0111101",
"0111111",
"1001000",
"1010000",
"1010001",
"1010011",
"1010110",
"1011100",
"1100001",
"1100010",
"1100011",
"1100101" };

void solve1(int n) {
    for(int i = 1; i <= 200; ++i) t[i].resize(n);

    int cnt = 0;
    t[++cnt][n/2-1] = 1;
    for(int j = 0; j <= n/2; ++j) {
        if(cnt >= 100) break;
        t[++cnt][n/2] = 1;
        if(j-1>=0) t[cnt][j-1] = 1;
        if(j-2>=0) t[cnt][j-2] = 1;
        if(cnt >= 100) break;
    }
    t[++cnt][n/2+1] = 1; t[cnt][0] = 1;
    t[++cnt][n/2+1] = 1; t[cnt][1] = 1;
    t[++cnt][n/2+1] = 1; t[cnt][0] = t[cnt][1] = 1;

    for(int j = 2; j <= n/2; ++j) {
        if(cnt >= 100) break;
        t[++cnt][n/2+1] = 1; t[cnt][j-2] = t[cnt][j] = 1;
        t[++cnt][n/2+1] = 1; t[cnt][j] = t[cnt][j-1] = 1;
        for(int jj = 0; jj <= j-2; ++jj) {
            if(cnt >= 100) break;
            t[++cnt][n/2+1] = 1;
            t[cnt][j] = t[cnt][j-1] = 1;
            t[cnt][jj] = 1;
            if(jj>0) t[cnt][jj-1] = 1;
        }
    }

    t[++cnt][n/2+2] = 1; t[cnt][1] = 1;
    t[++cnt][n/2+2] = 1; t[cnt][2] = 1;
    t[++cnt][n/2+2] = 1; t[cnt][1] = t[cnt][0] = 1;
    t[++cnt][n/2+2] = 1; t[cnt][2] = t[cnt][1] = t[cnt][0] = 1;

    for(int j = 0; j < 100; ++j) {
        if(cnt >= 100) break;
        t[++cnt][n/2+2] = 1;
        for(int kk = 0; kk < 7; ++kk) t[cnt][kk] = tab0[j][6-kk]-'0';
    }

    for(int i = 1; i <= 100; ++i) {
        for(int j = n-1; ~j; --j) cout << s[t[i][j]];
        cout << "\n";
    } 
}

string tab1[] = {
"00000100",
"00001001",
"00001011",
"00001110",
"00010010",
"00010101",
"00010111",
"00011010",
"00011101",
"00011111",
"00100100",
"00101001",
"00101011",
"00101110",
"00110010",
"00110101",
"00110111",
"00111010",
"00111101",
"00111111",
"01001000",
"01010001",
"01010011",
"01010110",
"01011100",
"01100010",
"01100101",
"01100111",
"01101010",
"01101101",
"01101111",
"01110100",
"01111001",
"01111011",
"01111110",
"10010000",
"10100001",
"10100011",
"10100110",
"10101100",
"10111000",
"11000010",
"11000101",
"11000111",
"11001010",
"11001101",
"11001111",
"11010100",
"11011001",
"11011011",
"11011110",
"11101000",
"11110001",
"11110011",
"11110110"
};

void solve2(int n) {
    for(int i = 1; i <= 200; ++i) t[i].resize(n);

    int cnt = 0;
    t[++cnt][n/2] = 1;
    for(int j = 0; j <= n/2; ++j) {
        if(cnt >= 100) break;
        t[++cnt][n/2+1] = 1;
        if(j>=0) t[cnt][j] = 1;
        if(j-1>=0) t[cnt][j-1] = 1;
        if(cnt >= 100) break;
    }
    t[++cnt][n/2+2] = 1; t[cnt][1] = 1;
    t[++cnt][n/2+2] = 1; t[cnt][2] = t[cnt][0] = 1;
    t[++cnt][n/2+2] = 1; t[cnt][2] = t[cnt][1] = t[cnt][0] = 1;

    for(int j = 3; j <= n/2+1; ++j) {
        if(cnt >= 100) break;
        t[++cnt][n/2+2] = 1; t[cnt][j] = t[cnt][j-2] = 1;
        for(int jj = 0; jj <= j-2; ++jj) {
            if(cnt >= 100) break;
            t[++cnt][n/2+2] = 1;
            t[cnt][j] = t[cnt][j-1] = 1;
            t[cnt][jj] = 1;
            if(jj>0) t[cnt][jj-1] = 1;
        }
    }

    for(int j = 0; j < 100; ++j) {
        if(cnt >= 100) break;
        t[++cnt][n/2+3] = 1;
        for(int kk = 0; kk < 8; ++kk) t[cnt][kk] = tab1[j][7-kk]-'0';
    }

    for(int i = 1; i <= 100; ++i) {
        for(int j = n-1; ~j; --j) cout << s[t[i][j]];
        cout << "\n";
    } 
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    cout << (1ll*(n+2-(n%2))*((n+1)/2)/2) << "\n";
    brute(n);
    // else if(n%2 == 0) solve1(n);
    // else solve2(n);

    return 0;
}