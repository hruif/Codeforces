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
vi sz;
vi par;

int find_rep(int a) {
	while (par[a] != -1) a = par[a];
	return a;
}

bool same_u(int a, int b) {
	return find_rep(a) == find_rep(b);
}

void merge(int a, int b) {
	a = find_rep(a); b = find_rep(b);
	if (same_u(a, b)) return;
	if (sz[a] < sz[b]) swap(a, b);
	sz[a] += sz[b];
	par[b] = a;
}

int main() {
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<bool> used(n, false);
		F0R(i, m) {
			int a, b, c;
			cin >> a >> b >> c;
			b--;
			used[b] = true;
		}
		int ind = -01;
		for (int i = 0; i < n; i++) {
			if (!used[i]) ind = i;
		}
		F0R(i, n) {
			if (i == ind) continue;
			cout << ind + 1 << ' ' << i + 1 << '\n';
		}
	}
}