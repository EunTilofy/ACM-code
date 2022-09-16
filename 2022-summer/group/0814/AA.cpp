#include <bits/stdc++.h>
using i64 = int64_t;
using u64 = uint64_t;
using u32 = uint32_t;
using i128 = __int128;
constexpr int P = 1000000007;
constexpr i64 inf = 1e18;
i64 binom[300][300];
int power(int a, int b) {
	int res = 1;
	for (; b > 0; b /= 2, a = i64(a) * a % P) {
		if (b % 2 == 1) {
			res = i64(res) * a % P;
		}
	}
	return res;
}
void solve() {
	i64 n, k;
	std::cin >> n >> k;
	n--;
	k--;
	i64 x = std::sqrt(2 * n);
	while (x * (x + 1) / 2 <= n) {
		x++;
	}
	i64 y = x - 1 - (n - x * (x - 1) / 2);
	int ans;
	if (y == 0) {
		if (k == 0) {
			ans = (power(2, x) - power(2, y) + P) % P;
		} else {
			ans = -1;
		}
	} else {
		y--;
		if (y <= 60 && k >= (1ll << y)) {
			ans = -1;
		} else if (y < 300) {
			ans = (power(2, x) - power(2, y + 1) + P) % P;
			int cnt = 0;
			while (k >= binom[y][cnt]) {
				k -= binom[y][cnt];
				cnt++;
			}
			for (int x = y - 1; x >= 0; x--) {
				if (k >= binom[x][cnt]) {
					k -= binom[x][cnt];
					cnt--;
					ans = (ans + power(2, x)) % P;
				}
			}
		} else {
			ans = (power(2, x) - power(2, y + 1) + P) % P;
			i64 binom = 1;
			int cnt = 0;
			while (binom <= k) {
				k -= binom;
				binom = std::min<i128>(inf, i128(binom) * (y - cnt) / (cnt + 1));
				cnt++;
			}
			while (cnt > 0) {
				i128 K = k;
				for (int i = 1; i <= cnt; i++) {
					K *= i;
				}
				i64 x = std::pow(K, 1.0 / cnt);
				if (x < cnt) {
					x = cnt - 1;
				}
				binom = 1;
				for (int i = 1; i <= cnt; i++) {
					binom = i128(binom) * (x - i + 1) / i;
				}
				while ((x == cnt - 1 ? 1 : i128(binom) * (x + 1) / (x - cnt + 1)) <= k) {
					binom = x == cnt - 1 ? 1 : i128(binom) * (x + 1) / (x - cnt + 1);
					x++;
				}
				k -= binom;
				ans = (ans + power(2, x)) % P;
				cnt--;
			}
		}
	}
	std::cout << ans << "\n";
}
int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
	for (int i = 0; i < 300; i++) {
		binom[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			binom[i][j] = std::min(inf, binom[i - 1][j] + binom[i - 1][j - 1]);
		}
	}
	int t;
	std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}