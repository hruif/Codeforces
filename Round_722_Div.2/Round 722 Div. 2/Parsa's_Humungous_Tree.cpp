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

#define MOD 998244353

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int t;
ll l[100000], r[100000];
vvi edges;
int par[100000];
pair<pair<ll, ll>, pair<ll, ll>> ans[100000];

ll cc = 0;

void solve(int cur) {
	cc++;
	int curpar = par[cur];

	pair<pair<ll, ll>, pair<ll, ll>> sum = { {0, 0}, {0,0} };
	if (cur != 0) {
		ll sd1, sd2, ld1, ld2;
		sd1 = abs(l[cur] - l[curpar]), sd2 = abs(l[cur] - r[curpar]);
		ld1 = abs(r[cur] - l[curpar]), ld2 = abs(r[cur] - r[curpar]);

		sum = { {sd1, sd2}, {ld1, ld2} };
	}

	for (auto x : edges[cur]) {
		if (x == curpar) continue;
		par[x] = cur;
		solve(x);
		pair<pair<ll, ll>, pair<ll, ll>> nsum = ans[x];
		sum.first.first += max(nsum.first.first, nsum.second.first);
		sum.first.second += max(nsum.first.first, nsum.second.first);
		sum.second.first += max(nsum.first.second, nsum.second.second);
		sum.second.second += max(nsum.first.second, nsum.second.second);
	}
	ans[cur] = sum;
}

int main() {
	cin >> t;
	while (t--) {
		cc = 0;
		edges.clear();

		int n;
		cin >> n;
		F0R(i, n) cin >> l[i] >> r[i];
		edges.resize(n);
		F0R(i, n - 1) {
			int u, v;
			cin >> u >> v;
			u--; v--;
			edges[u].push_back(v);
			edges[v].push_back(u);
		}

		par[0] = -1;
		solve(0);
		pair<pair<ll, ll>, pair<ll, ll>> s = ans[0];
		cout << max(max(s.first.first, s.first.second), max(s.second.first, s.second.second)) << ' ' << cc << '\n';
	}
}