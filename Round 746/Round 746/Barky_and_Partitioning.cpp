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
int a[100000], xors[100000];
vi pars, depth;
vvi edges;

void dfs(int node, int par, int d) {
	int v = a[node];
	pars[node] = par;
	depth[node] = d;

	for (auto x : edges[node]) {
		if (x == par) continue;
		dfs(x, node, d + 1);
		v ^= xors[x];
	}
	xors[node] = v;
}

int main() {
	cin >> t;
	while (t--) {
		edges.clear();
		pars.clear();
		depth.clear();

		int n, k;
		cin >> n >> k;
		F0R(i, n) cin >> a[i];
		int tree_xor = 0;
		F0R(i, n) tree_xor ^= a[i];
		edges.rsz(n);
		depth.rsz(n);
		pars.rsz(n);
		F0R(i, n - 1) {
			int u, v;
			cin >> u >> v;
			u--; v--;
			edges[u].push_back(v);
			edges[v].push_back(u);
		}
		if (tree_xor == 0) cout << "YES\n";
		else {
			if (k <= 2) cout << "NO\n";
			else {
				dfs(0, -1, 0);
				vector<pii> depth_ordered;
				for (int i = 1; i < n; i++) {
					depth_ordered.push_back({ depth[i], i });
				}
				sort(all(depth_ordered), greater<pii>());

				bool found = false;
				vector<bool> flags(n, false);
				for (int p = 0; p < sz(depth_ordered); p++) {
					int i = depth_ordered[p].second;
					if (flags[i]) continue;
					if (xors[i] == tree_xor) {
						int cur = pars[i];
						while (cur != -1) {
							flags[cur] = true;
							if (xors[cur] == 0) {
								found = true;
								break;
							}
							cur = pars[cur];
						}

						for (int p2 = p + 1; p2 < sz(depth_ordered); p2++) {
							int j = depth_ordered[p2].second;
							if (flags[j]) continue;
							if (xors[j] == tree_xor) {
								found = true;
								break;
							}
						}
						break;
					}
				}
				if (found) cout << "YES\n";
				else cout << "NO\n";
			}
		}
	}
}