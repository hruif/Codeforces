#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vc = vector<char>;
using pii = pair<int, int>;
using vpii = vector<pii>;

#define FORI(i, a, b, p) for (int i = a; i < b; i += p)
#define FOR(i, a, b) FORI(i, a, b, 1)
#define F0R(i,b) FOR(i, 0, b)
#define RFOR(i, a, b) for (int i = a; i >= b; i--)
#define RF0R(i, a) RFOR(i, a, 0)

#define MOD 1

int q;

int lg2(int a) {
	int l = 0;
	for (int i = 0; i < 32; i++) {
		if ((a >> i) & 1) l = i;
	}
	return l;
}

int main() {
	cin >> q;
	while (q--) {
		int n, k;
		string s;
		cin >> n >> k >> s;
		int l = min(lg2(n) + 1, k);
		int pre = max(0, k - l);
		string anss(pre, '0');
		
		vector<bool> B(1 << l + 1, false);
		int cnt = 0;
		F0R(i, k - l) {
			if (s[i] == '1') cnt++;
		}
		int mask = 0;
		FOR(i, k - l, k) {
			mask <<= 1;
			mask = mask | (1 - (s[i] - '0'));
		}
		if (cnt == (k - l)) B[mask] = true;
		FOR(i, k, n) {
			mask <<= 1;
			mask = (mask | (1 - (s[i] - '0'))) & ((1 << l) - 1);
			cnt += s[i - l] - '0';
			cnt -= s[i - k] - '0';
			if (cnt == (k - l)) B[mask] = true;
		}
		int ans = 0;
		while (ans < (1 << l) && B[ans]) ans++;
		if (ans == (1 << l)) cout << "NO\n";
		else {
			RF0R(i, l - 1) {
				anss.push_back(((ans >> i) & 1) + '0');
			}
			cout << "YES\n" << anss << '\n';
		}
	}
}