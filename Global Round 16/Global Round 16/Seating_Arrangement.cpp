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
vvi sts;

void set_sts(int n, int m) {
	int sn = 1;
	while (sn < m) sn *= 2;
	sts.rsz(n, vi(sn * 2, 0));
}

int findval(vi &st, int a, int b) {
	int sn = sz(st) / 2;
	a += sn; b += sn;
	int val = 0;
	while (a <= b) {
		if (a % 2 == 1) val += st[a++];
		if (b % 2 == 0) val += st[b--];
		a /= 2;
		b /= 2;
	}
	return val;
}

void changeval(vi &st, int k, int x) {
	int sn = sz(st) / 2;
	k += sn;
	st[k] = x;
	for (k /= 2; k >= 1; k /= 2) {
		st[k] = st[k * 2] + st[k * 2 + 1];
	}
}

int a[300 * 300], sa[300 * 300];
map<int, int> ni;
vi starts;
vvi rends;

int main() {
	cin >> t;
	while (t--) {
		ni.clear();
		starts.clear();
		rends.clear();
		sts.clear();

		int n, m;
		cin >> n >> m;
		set_sts(n + 1, m);
		F0R(i, n) {
			F0R(j, m) {
				cin >> a[i * m + j];
				sa[i * m + j] = a[i * m + j];
			}
		}
		sort(sa, sa + n * m);
		int ans = 0;
		int ind = 1;
		F0R(i, n) {
			F0R(j, m) {
				if (ni[sa[i * m + j]] == 0) ni[sa[i * m + j]] = ind++;
			}
		}
		starts.rsz(ind + 1, -1);
		rends.rsz(ind + 1, vi(n, -1));
		F0R(i, n) {
			F0R(j, m) {
				int v = ni[sa[i * m + j]];
				if (starts[v] == -1) starts[v] = i * m + j;
				rends[v][i] = j;
			}
		}

		F0R(i, n * m) {
			int v = ni[a[i]];
			int minv = m + 1, minvi = -1;
			int r = i / m, c = i % m;
			F0R(j, n) {
				if (rends[v][j] == -1) continue;
				int seats = m - rends[v][j] - 1;
				int vac = seats - findval(sts[j], rends[v][j], m - 1);
				if (vac < minv) {
					minv = vac;
					minvi = j;
				}
			}
			int curstart = 0;
			if (minvi * m < starts[v] && (minvi + 1) * (m) > starts[v]) curstart = starts[v] % m;
			ans += findval(sts[minvi], 0, rends[v][minvi] - 1);
			changeval(sts[minvi], rends[v][minvi], 1);
			if (rends[v][minvi] == curstart) rends[v][minvi] = -1;
			else rends[v][minvi]--;
		}
		cout << ans << '\n';
	}
}