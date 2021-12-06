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
int a[200000];
vector<pair<ll, ll>> dp;
pii segs[200000];

int main() {
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		dp.rsz(m, { 3000000000, 3000000000 });
		F0R(i, n) cin >> a[i];
		F0R(i, m) cin >> segs[i].first >> segs[i].second;
		sort(a, a + n);
		sort(segs, segs + m);
		int p1 = 0, p2 = 0;
		long long ans = 0;
		while (p2 < m) {
			int l = segs[p2].first, r = segs[p2].second;
			int &x = a[p1];
			while (p1 + 1 < n && a[p1 + 1] <= l) {
				p1++;
			}
			if (p1 < l) {
				if (p2 == 0) {
					dp[p2].first = l - p1;
					if (p1 + 1 < n) dp[p2].second = max(0, a[p1 + 1] - r);
				}
				else {
					dp[p2].first = min(dp[p2 - 1].first + l - p1, dp[p2 - 1].second + max(0, l - segs[p2 - 1].second));
					if (p1 + 1 < n) dp[p2].second = min(dp[p2 - 1].first, dp[p2 - 1].second) + max(0, a[p1 + 1] - r);
				}
				p1++;
			}
			else if (p1 > r) {
				if (p2 == 0) dp[p2].second = p1 - r;
				else {
					dp[p2].second = min(dp[p2 - 1].first + p1 - r, dp[p2 - 1].second + max(0, l - r));
				}
			}
			else {
				if (p2 == 0) dp[p2].first = 0;
				else dp[p2].first = min(dp[p2 - 1].first, dp[p2 - 1].second + max(0, l - r));
			}
			p2++;
		}
		cout << min(dp[m - 1].first, dp[m - 1].second) / 2 << '\n';
	}
}