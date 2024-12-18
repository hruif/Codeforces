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
pair<pair<int, int>, int> segs[200000];
ll facs[200001], invfacs[200001];
ll mpows[200001];

ll fast_pow(ll b, ll e) {
	if (e == 0) return 1;
	ll val = fast_pow(b, e / 2);
	val *= val;
	val %= MOD;
	if (e % 2) val *= b;
	return val % MOD;
}

multiset<pair<int, int>> s;
map<int, int> vals;
int main() {
	fast_cin();

	ll cur = 1;
	facs[0] = 1;
	invfacs[0] = 1;
	for (int i = 1; i < 200001; i++) {
		cur *= i;
		cur %= MOD;
		facs[i] = cur;
		invfacs[i] = fast_pow(cur, MOD - 2);
	}
	cur = 1;
	for (int i = 0; i < 200001; i++) {
		mpows[i] = cur;
		cur = cur * 2 % MOD;
	}
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			cin >> segs[i].first.first >> segs[i].first.second >> segs[i].second;
		}
		sort(segs, segs + m);
		vi vans(n, 0);
		int p = 0;
		vector<int> bits(31, 0);
		int cval = 0;
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			if (p != m) {
				while (p < m && i + 1 == segs[p].first.first) {
					s.insert({ segs[p].first.second, segs[p].second });
					for (int b = 0; b < 31; b++) {
						if (segs[p].second & (1 << b)) bits[b]++;
					}
					vals[segs[p++].second]++;
				}
			}
			while (!s.empty() && s.begin()->first < i + 1) {
				for (int b = 0; b < 31; b++) {
					if (s.begin()->second & (1 << b)) bits[b]--;
				}
				vals[s.begin()->second]--;
				if (vals[s.begin()->second] == 0) vals.erase(vals.find(s.begin()->second));
				s.erase(s.begin());
			}
			cval = 0;
			bool valid = true;
			for (int b = 0; b < 31; b++) {
				bool cb = cval & (1 << b);
				bool bb = bits[b] == s.size();
				if (bb) cval += (1 << b);
			}
			if (valid) vans[i] = cval;
		}
		s.clear();
		vals.clear();
		bits.clear();
		bits.resize(31, 0);
		for (int i = 0; i < n; i++) {
			for (int b = 0; b < 31; b++) {
				if (vans[i] & (1 << b)) bits[b]++;
			}
		}
		for (int b = 0; b < 31; b++) {
			int ocnt = n - bits[b];
			ll oc = mpows[ocnt];
			for (int i = 1; i <= bits[b]; i += 2) {
				ll cnt = facs[bits[b]] * invfacs[bits[b] - i] % MOD;
				cnt *= invfacs[i];
				cnt %= MOD;
				cnt *= (1 << b);
				cnt %= MOD;
				ans += cnt * oc % MOD;
			}
		}
		cout << ans % MOD << '\n';
	}
}