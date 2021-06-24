#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>

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
#define pb push_back
#define eb emplace_back

#define lb lower_bound
#define ub upper_bound

// for loops
#define FORI(i, a, b, p) for (int i = a; i < b; i += p)
#define FOR(i, a, b) FORI(i, a, b, 1)
#define F0R(i,b) FOR(i, 0, b)
#define F0R2(i, j, a, b) F0R(i, a) F0R(j, b)
#define RFOR(i, a, b) for (int i = a; i >= b; i--)
#define RF0R(i, a) RFOR(i, a, 0)

#define MOD 1

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int n, m, node_cnt;
vstr grid;
vi a;
vvi node_inds, edges;
vector<vector<int>> SCC_edges;
vector<int> required;
vi in_SCC, left_of_req;
vvi SCC;

int nid;
vi id, low;
vb in_st;
stack<int> st;
void find_SCC(int node) {
	id[node] = low[node] = nid++;
	in_st[node] = true;
	st.push(node);
	for (auto x : edges[node]) {
		if (id[x] == -1) {
			find_SCC(x);
			low[node] = min(low[node], low[x]);
		}
		else if (in_st[x]) {
			low[node] = min(low[node], id[x]);
		}
	}
	if (id[node] == low[node]) {
		SCC.emplace_back();
		while (true) {
			int nnode = st.top();
			st.pop();
			in_st[nnode] = false;
			in_SCC[nnode] = sz(SCC) - 1;
			SCC.back().push_back(nnode);
			if (nnode == node) break;
		}
	}
}

vb marked;
void mark(int scc) {
	for (auto x : SCC_edges[scc]) {
		if (!marked[x]) {
			marked[x] = true;
			mark(x);
		}
	}
}

vpii dp;
pii find_range(int scc) {
	if (dp[scc].first != m + 1) return dp[scc];

	pii range = { m, -1 };
	for (auto x : SCC_edges[scc]) {
		if (marked[x]) continue;
		pii nr = find_range(x);
		range.first = min(range.first, nr.first);
		range.second = max(range.second, nr.second);
	}
	dp[scc] = range;
	return range;
}

int main() {
	{
		cin >> n >> m;

		grid.resize(n);
		F0R(i, n) cin >> grid[i];

		a.resize(m);
		F0R(i, m) cin >> a[i];

		node_inds.resize(n, vi(m, -1));
		F0R2(i, j, n, m) {
			if (grid[i][j] == '#') {
				node_inds[i][j] = node_cnt++;
			}
		}

		edges.resize(node_cnt);
		/*F0R(j, m) {
			int cur = -1;
			RF0R(i, n - 1) {
				if (node_inds[i][j] != -1) {
					if (cur != -1) {
						edges[node_inds[i][j]].push_back(cur);
					}
					cur = node_inds[i][j];
				}
				if (cur != -1) {
					if (j > 0) {
						if (node_inds[i][j - 1] != -1) {
							edges[node_inds[i][j - 1]].push_back(cur);
						}
					}
					if (j < m - 1) {
						if (node_inds[i][j + 1] != -1) {
							edges[node_inds[i][j + 1]].push_back(cur);
						}
					}
					if (i > 0) {
						if (node_inds[i][j] == cur && node_inds[i - 1][j] != -1) {
							edges[cur].push_back(node_inds[i - 1][j]);
						}
					}
				}
			}
		}*/
		F0R(i, n) {
			F0R(j, m) {
				if (grid[i][j] == '#') {
					if (i > 0 && grid[i - 1][j] == '#')
						edges[node_inds[i][j]].push_back(node_inds[i - 1][j]);
					FOR(k, i + 1, n) {
						if (grid[k][j] == '#') {
							edges[node_inds[i][j]].push_back(node_inds[k][j]);
						}
					}
					bool leftdone = false, rightdone = false;
					for (int k = i;
						k < n && (!leftdone || !rightdone) && (grid[k][j] != '#' || k == i);
						k++) {
						if (j > 0 && !leftdone && grid[k][j - 1] == '#') {
							edges[node_inds[i][j]].push_back(node_inds[k][j - 1]);
							leftdone = true;
						}
						if (j < m - 1 && !rightdone && grid[k][j + 1] == '#') {
							edges[node_inds[i][j]].push_back(node_inds[k][j + 1]);
							rightdone = true;
						}
					}
				}
			}
		}
	}
	{
		nid = 0;
		id.resize(node_cnt, -1);
		low.resize(node_cnt, -1);
		in_SCC.resize(node_cnt, -1);
		in_st.resize(node_cnt, false);
		F0R(i, node_cnt) {
			if (id[i] == -1) find_SCC(i);
		}

		SCC_edges.resize(sz(SCC));
		F0R(i, sz(SCC)) {
			for (auto x : SCC[i]) {
				for (auto y : edges[x]) {
					if (in_SCC[y] != i) SCC_edges[i].push_back(in_SCC[y]);
				}
			}
			sort(SCC_edges[i].begin(), SCC_edges[i].end());
			SCC_edges[i].erase(unique(SCC_edges[i].begin(), SCC_edges[i].end()), SCC_edges[i].end());
		}

		left_of_req.resize(sz(SCC), m);
		F0R(j, m) {
			int cnt = 0;
			RF0R(i, n - 1) {
				if (grid[i][j] == '#') {
					cnt++;
					if (a[j] == cnt) {
						required.push_back(in_SCC[node_inds[i][j]]);
						left_of_req[in_SCC[node_inds[i][j]]] = min(left_of_req[in_SCC[node_inds[i][j]]], j);
						break;
					}
				}
			}
		}
		sort(required.begin(), required.end());
		required.erase(unique(required.begin(), required.end()), required.end());

		marked.resize(sz(SCC));
		for (auto x : required) if (!marked[x]) mark(x);
		vector<int> compress;
		for (auto x : required) if (!marked[x]) compress.push_back(left_of_req[x]);
		sort(compress.begin(), compress.end());
		dp.resize(sz(SCC), { m + 1, -1 });
		for (auto x : required) if (!marked[x]) 
			dp[x].first = dp[x].second = lb(compress.begin(), compress.end(), left_of_req[x]) - compress.begin();

		vi ranges(sz(compress), -1);
		F0R(i, sz(SCC)) {
			if (!marked[i]) {
				pii range = find_range(i);
				if (range.first < m) {
					ranges[range.first] = max(ranges[range.first], range.second);
				}
			}
		}
		FOR(i, 1, sz(compress)) {
			ranges[i] = max(ranges[i], ranges[i - 1]);
		}
		int ans = 0;
		F0R(i, sz(compress)) {
			i = ranges[i];
			ans++;
		}
		cout << ans << '\n';
	}
}