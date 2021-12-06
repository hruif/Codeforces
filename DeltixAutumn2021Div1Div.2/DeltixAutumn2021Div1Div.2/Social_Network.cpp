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

int n, d;
vector<int> sz, par;

int rep(int a) {
	while (par[a] != -1) a = par[a];
	return a;
}

bool same(int a, int b) {
	return rep(a) == rep(b);
}

void merge(int a, int b) {
	a = rep(a); b = rep(b);
	if (same(a, b)) return;
	if (sz[a] < sz[b]) swap(a, b);
	sz[a] += sz[b];
	par[b] = a;
}

int main() {
	fast_cin();

	cin >> n >> d;
	sz.resize(n, 1);
	par.resize(n, -1);
	int ms = 0, msx = 0;
	int s = 0;
	for (int i = 0; i < d; i++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		x = rep(x); y = rep(y);
		if (x == y) s++;
		else merge(x, y);
		if (sz[rep(x)] > ms) {
			msx = rep(x);
			ms = sz[msx];
		}
		ll ans = ms;	
		vector<bool> checked(n, false);
		checked[msx] = true;
		vector<int> szs;
		for (int i = 0; i < n; i++) {
			int ti = rep(i);
			if (!checked[ti]) {
				szs.push_back(sz[ti]);
				checked[ti] = true;
			}
		}
		sort(szs.begin(), szs.end());
		for (int j = 0; j < s; j++) {
			if (szs.size() - 1 - j < 0) break;
			ans += szs[szs.size() - 1 - j];
		}

		cout << ans - 1 << '\n';
	}
}