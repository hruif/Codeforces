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

int n;
int a[300000];
int b[300000];
vpii st;

void set_st() {
	int sn = 1;
	while (sn < n) sn *= 2;
	st.rsz(sn * 2, { 1000000, -1 });
}

void change_val(int k, pii x) {
	int sn = sz(st) / 2;
	k += sn;
	st[k] = x;
	for (k /= 2; k >= 1; k /= 2) {
		st[k] = min(st[k * 2], st[k * 2 + 1]);
	}
}

pii find_val(int a, int b) {
	int sn = sz(st) / 2;
	a += sn; b += sn;
	pii val = { 1000000, 0 };
	while (a <= b) {
		if (a % 2 == 1) val = min(val, st[a++]);
		if (b % 2 == 0) val = min(val, st[b--]);
		a /= 2; b /= 2;
	}
	return val;
}

int main() {
	fast_cin();

	cin >> n;
	set_st();
	F0R(i, n) cin >> a[i];
	F0R(i, n) cin >> b[i];
	vi maxh(n);
	F0R(i, n) {
		maxh[i] = i + b[i] - a[i + b[i]];
		change_val(i, { maxh[i], i });
	}
	int pos = n - 1;
	vb visited(n, false);
	vi ans;
	while (pos >= 0) {
		if (pos - a[pos] < 0) {
			ans.push_back(0);
			pos = -1;
			break;
		}
		if (visited[pos]) break;
		visited[pos] = true;
		pii p = find_val(pos - a[pos], pos);
		pos = p.second;
		ans.push_back(pos + 1);
		pos += b[p.second];
	}
	if (pos < 0) {
		cout << sz(ans) << '\n';
		for (auto x : ans) cout << x << ' ';
		cout << '\n';
	}
	else cout << "-1\n";
}