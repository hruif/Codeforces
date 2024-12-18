#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <climits>

using namespace std;
using ll = long long;
using str = string;

using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vb = vector<bool>;
using vc = vector<char>;
using vstr = vector<string>;
using pii = pair<int, int>;
using vpii = vector<pii>;

#define sz(x) (int)(x.size())
#define rsz resize
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define pb push_back
#define eb emplace_back

#define lb lower_bound
#define ub upper_bound

// for loops
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define F0R(i, b) FOR(i, 0, b)
#define F1R(i, b) FOR(i, 1, b)
#define F0R2(i, j, a, b) F0R(i, a) F0R(j, b)
#define RFOR(i, a, b) for (int i = a - 1; i >= b; i--)
#define RF0R(i, a) RFOR(i, a, 0)

#define MOD (ll)(1e9 + 7)

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int t;
int a[40];
int dp[40][21];

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

set<int> s1[21], s2[21];
set<int> fac1, fac2;

int main() {
	fast_cin();

	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);
		int vs[20], vs2[20];
		for (int i = 0; i < (1 << (n / 2)); i++) {
			int cnt = 0;
			for (int b = 0; b < n / 2; b++) {
				if (i & (1 << b)) {
					vs[cnt] = a[b];
					vs2[cnt++] = a[n / 2 + b];
				}
			}
			int v = 0;
			for (int j = 0; j < cnt; j++) v = gcd(v, vs[j] - vs[0]);
			s1[cnt].insert(v);
			v = 0;
			for (int j = 0; j < cnt; j++) v = gcd(v, vs2[j] - vs2[0]);
			s2[cnt].insert(v);
		}
		bool has0 = false;
		int ans = 1;
		for (int i = 0; i < n / 2; i++) {
			for (auto x : s1[i]) {
				if (s2[n / 2 - i].find(x) != s2[n / 2 - i].end()) 
					has0 = true;
			}
			if (has0) break;
			for (auto x : s1[i]) {
				for (int j = sqrt(x); j > ans; j--) {
					if (x % j == 0) {
						fac1.insert(j);
						fac1.insert(x / j);
					}
				}
			}
			for (auto x : s2[n / 2 - i]) {
				for (int j = sqrt(x); j > ans; j--) {
					if (x % j == 0) {
						if (fac1.find(j) != fac1.end()) ans = max(j, ans);
						if (fac1.find(x / j) != fac1.end()) ans = max(x / j, ans);
					}
				}
			}
			s1[i].clear(); s2[i].clear();
			fac1.clear(); fac2.clear();
		}
		for (auto x : s1[n / 2]) {
			ans = max(ans, x);
			if (x == 0) has0 = true;
		}
		s1[n / 2].clear();
		for (auto x : s2[n / 2]) {
			ans = max(ans, x);
			if (x == 0) has0 = true;
		}
		s2[n / 2].clear();
		if (has0) cout << -1 << '\n';
		else cout << ans << '\n';
	}
}