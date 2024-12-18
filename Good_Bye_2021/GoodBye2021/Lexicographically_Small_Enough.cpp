#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>
#include <cmath>
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
#include <array>

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

#define inf 100000000000000000
#define MOD (ll)(1e9 + 7)

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

struct SegmentTree_min {
	int sn;
	vector<ll> st;

	SegmentTree_min() {}

	SegmentTree_min(int n, ll max_v) {
		sn = 1;
		while (sn < n) sn *= 2;
		st.resize(sn * 2, max_v + 1);
	}

	SegmentTree_min(vector<ll>& v, ll max_v) {
		int n = v.size();
		sn = 1;
		while (sn < n) sn *= 2;
		st.resize(sn * 2, max_v + 1);
		for (int i = 0; i < n; i++) set_val(i, v[i]);
	}

	void set_st(int n, ll max_v) {
		st.clear();
		sn = 1;
		while (sn < n) sn *= 2;
		st.resize(sn * 2, max_v + 1);
	}

	void set_val(int k, ll x) {
		k += sn;
		st[k] = x;
		for (k /= 2; k >= 1; k /= 2) {
			st[k] = min(st[k * 2], st[k * 2 + 1]);
		}
	}

	void change_val(int k, ll x) {
		k += sn;
		st[k] += x;
		for (k /= 2; k >= 1; k /= 2) {
			st[k] = min(st[k * 2], st[k * 2 + 1]);
		}
	}

	ll find_val(int a, int b) {
		a += sn; b += sn;
		ll val = inf;
		while (a <= b) {
			if (a % 2 == 1) val = min(val, st[a++]);
			if (b % 2 == 0) val = min(val, st[b--]);
			a /= 2; b /= 2;
		}
		return val;
	}
};
struct SegmentTree_sum {
	int sn;
	vector<ll> st;

	SegmentTree_sum() {}

	SegmentTree_sum(int n) {
		sn = 1;
		while (sn < n) sn *= 2;
		st.resize(sn * 2, 0);
	}

	SegmentTree_sum(vector<ll>& v) {
		int n = v.size();
		sn = 1;
		while (sn < n) sn *= 2;
		st.resize(sn * 2, 0);
		for (int i = 0; i < n; i++) set_val(i, v[i]);
	}

	void set_st(int n) {
		st.clear();
		sn = 1;
		while (sn < n) sn *= 2;
		st.resize(sn * 2, 0);
	}

	void set_val(int k, ll x) {
		k += sn;
		st[k] = x;
		for (k /= 2; k >= 1; k /= 2) {
			st[k] = st[k * 2] + st[k * 2 + 1];
		}
	}

	void change_val(int k, ll x) {
		k += sn;
		st[k] += x;
		for (k /= 2; k >= 1; k /= 2) {
			st[k] = st[k * 2] + st[k * 2 + 1];
		}
	}

	ll find_val(int a, int b) {
		a += sn; b += sn;
		ll val = 0;
		while (a <= b) {
			if (a % 2 == 1) val += st[a++];
			if (b % 2 == 0) val += st[b--];
			a /= 2; b /= 2;
		}
		return val;
	}
};

int q;
string s, t;
vector<vector<int>> pos;
SegmentTree_min st_char; // earliest position of chars
SegmentTree_sum st_inds; // how many indexes have moved

void solve() {
	pos.clear();

	int n;
	cin >> n;
	cin >> s;
	cin >> t;
	pos.resize(26);
	for (int i = 0; i < n; i++) 
		pos[s[i] - 'a'].push_back(i);
	for (auto& x : pos)
		reverse(x.begin(), x.end());
	st_char.set_st(26, n);
	st_inds.set_st(n);
	for (int i = 0; i < 26; i++)
		if (!pos[i].empty()) 
			st_char.set_val(i, pos[i].back());
	int p = 0;
	ll ans = inf;
	ll cur = 0;
	for (int i = 0; i < n; i++) {
		while (p + st_inds.find_val(p + 1, n - 1) < i) p++;
		int c = t[i] - 'a';

		ll to_small = st_char.find_val(0, c - 1);
		if (to_small < n) ans = min(ans, to_small - i + st_inds.find_val(to_small, n - 1) + cur);

		ll to_same = st_char.find_val(c, c);
		if (to_same >= n) break;
		cur += to_same - i + st_inds.find_val(to_same, n - 1);
		st_inds.set_val(to_same, 1);
		pos[c].pop_back();
		if (pos[c].empty()) st_char.set_val(c, n);
		else st_char.set_val(c, pos[c].back());
	}
	if (ans >= 1000000000000) ans = -1;
	cout << ans << '\n';
}

int main() {
	fast_cin();

	cin >> q;
	while (q--)
		solve();
}