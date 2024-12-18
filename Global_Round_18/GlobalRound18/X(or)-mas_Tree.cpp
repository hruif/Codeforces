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

#define MOD (ll)(1e9 + 7)

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int t;
vector<array<int, 3>> given;
vector<vector<pair<int, int>>> edges;

int bit_cnt(int x) {
	int cnt = 0;
	while (x > 0) {
		if (x & 1) cnt++;
		x >>= 1;
	}
	return cnt;
}

vector<int> colors;
bool dfs_check(int node, int color) {
	if (colors[node] != -1) return colors[node] == color;
	colors[node] = color;
	for (auto x : edges[node]) {
		int next_color = color;
		if (x.second == 1) next_color = 1 - next_color;
		if (!dfs_check(x.first, next_color)) 
			return false;
	}
	return true;
}

map<pair<int, int>, int> e;
void dfs_assign(int node, int par) {
	if (par != -1) e[{node, par}] = e[{par, node}] = colors[node] ^ colors[par];
	for (auto x : edges[node]) {
		if (x.first == par) continue;
		dfs_assign(x.first, node);
	}
}

void clear_all() {
	given.clear();
	edges.clear();
	colors.clear();
	e.clear();
}

int main() {
	fast_cin();

	cin >> t;
	while (t--) {
		clear_all();

		int n, m;
		cin >> n >> m;
		edges.resize(n);
		for (int i = 0; i < n - 1; i++) {
			int x, y, v;
			cin >> x >> y >> v;
			x--; y--;
			given.push_back({ x, y, v });
			if (v != -1) {
				int p = bit_cnt(v) % 2;
				edges[x].push_back({ y, p });
				edges[y].push_back({ x, p });
			}
		}
		for (int i = 0; i < m; i++) {
			int a, b, p;
			cin >> a >> b >> p;
			a--; b--;
			edges[a].push_back({ b, p });
			edges[b].push_back({ a, p });
		}
		colors.resize(n, -1);
		bool valid = true;
		for (int i = 0; i < n; i++) {
			if (colors[i] == -1) {
				if (!dfs_check(i, 0)) valid = false;
			}
		}
		if (valid) {
			cout << "YES\n";

			edges.clear();
			edges.resize(n);
			for (auto& x : given) {
				edges[x[0]].push_back({ x[1], x[2] });
				edges[x[1]].push_back({ x[0], x[2] });
			}
			dfs_assign(0, -1);
			for (auto& x : given) {
				cout << x[0] + 1 << ' ' << x[1] + 1 << ' ';
				if (x[2] == -1) cout << e[{ x[0], x[1] }] << '\n';
				else cout << x[2] << '\n';
			}
		}
		else cout << "NO\n";
	}
}