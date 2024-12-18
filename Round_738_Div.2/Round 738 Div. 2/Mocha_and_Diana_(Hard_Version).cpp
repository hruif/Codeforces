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

vi us[2], ss[2];

int par(vi& u, int a) {
	while (u[a] != a) a = u[a];
	return a;
}

void unite(vi& u, vi& s, int a, int b) {
	a = par(u, a);
	b = par(u, b);
	if (s[a] < s[b]) swap(a, b);
	u[b] = a;
	s[a] += s[b];
}

bool sameu(vi& u, int a, int b) {
	return (par(u, a) == par(u, b));
}

int main() {
	int n, m1, m2;
	cin >> n >> m1 >> m2;
	us[0].rsz(n); ss[0].rsz(n, 1);
	us[1].rsz(n); ss[1].rsz(n, 1);
	F0R(i, n) us[0][i] = i;
	F0R(i, n) us[1][i] = i;
	F0R(i, m1) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		unite(us[0], ss[0], u, v);
	}
	F0R(i, m2) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		unite(us[1], ss[1], u, v);
	}
	int p1 = 0, p2 = 0;
	vpii ans;
	while (p1 < n && p2 < n) {
		while (p1 < n && sameu(us[0], 0, p1)) p1++;
		while (p2 < n && sameu(us[1], 0, p2)) p2++;
		if (p1 == n || p2 == n) break;
		int l, r;
		if (!sameu(us[1], 0, p1)) {
			l = 0, r = p1;
		}
		else if (!sameu(us[0], 0, p2)) {
			l = 0; r = p2;
		}
		else {
			l = p1; r = p2;
		}
		ans.push_back({ l + 1, r + 1 });
		unite(us[0], ss[0], l, r);
		unite(us[1], ss[1], l, r);
	}
	cout << sz(ans) << '\n';
	F0R(i, sz(ans)) cout << ans[i].first << ' ' << ans[i].second << '\n';
}