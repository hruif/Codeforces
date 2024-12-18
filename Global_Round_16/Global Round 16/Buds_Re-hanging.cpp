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
vi par;
vvi ch, edges;

void set_ch(int node, int parent) {
	par[node] = parent;
	F0R(i, sz(edges[node])) {
		int nnode = edges[node][i];
		if (nnode == parent) continue;
		ch[node].push_back(nnode);
		set_ch(nnode, node);
	}
}

int main() {
	cin >> t;
	while (t--) {
		par.clear();
		ch.clear();
		edges.clear();

		int n;
		cin >> n;
		edges.rsz(n);
		ch.rsz(n);
		par.rsz(n);
		F0R(i, n - 1) {
			int u, v;
			cin >> u >> v;
			u--; v--;
			edges[u].push_back(v);
			edges[v].push_back(u);
		}
		set_ch(0, -1);
		vb leaf(n, false);
		int ls, bs;
		ls = bs = 0;
		F0R(i, n) {
			if (sz(ch[i]) == 0) {
				leaf[i] = true;
				ls++;
			}
		}
		vb bud(n, true);
		F0R(i, n) {
			F0R(j, sz(ch[i])) {
				if (!leaf[ch[i][j]]) bud[i] = false;
			}
			if (bud[i] && !leaf[i]) bs++;
		}
		bool hang = false;
		F0R(i, n) {
			if (leaf[i] && !bud[par[i]]) hang = true;
		}
		int ans = ls - bs + 1;
		if (hang) ans--;
		cout << ans << '\n';
	}
}