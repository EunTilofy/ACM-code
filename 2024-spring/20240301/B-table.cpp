#include <bits/stdc++.h>
using namespace std;

std::string gen_string(int64_t a, int64_t b) {
std::string res;
int64_t ia = 0, ib = 0;
while (ia + ib < a + b) {
if ((__int128)ia * b <= (__int128)ib * a) {
res += '0';
ia++;
} else {
res += '1';
ib++;
}
}
return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 1; i <= 100; ++i) {
        for(int j = 1; j <= 10; ++j) {
            cout << "i=" << i << " j=" << j << "\t\t" << gen_string(i, j) << "\n";
        }
    }

    return 0;
}