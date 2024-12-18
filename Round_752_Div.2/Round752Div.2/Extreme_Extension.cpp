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

#define MOD (ll)(998244353)

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int t;
int a[100000];
int dp[2][100001];
vector<int> vs[2];

int main() {
	fast_cin();
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		F0R(i, n) cin >> a[i];
		dp[(n - 1) % 2][a[n - 1]] = 1;
		vs[(n - 1) % 2].push_back(a[n - 1]);
		ll ans = 0;
		for (int c = n - 2; c >= 0; c--) {
			int i = c % 2;
			int rev = i ^ 1;
			int v = a[c];
			vs[i].push_back(v);
			for (auto p : vs[rev]) {
				ll x = p, y = dp[rev][p];
				int splits = v / x;
				if (v % x == 0) splits--;
				ll nx = v / (splits + 1);
				ans += (y * splits * (c + 1)) % MOD;
				dp[i][nx] += y;
				dp[i][nx] %= MOD;
				if (vs[i].back() != nx) vs[i].push_back(nx);
			}
			dp[i][v] += 1;
			for (auto x : vs[rev]) dp[rev][x] = 0;
			vs[rev].clear();
		}
		cout << ans % MOD << '\n';
		for (auto x : vs[0]) dp[0][x] = 0;
		for (auto x : vs[1]) dp[1][x] = 0;
		vs[0].clear(); vs[1].clear();
	}
}