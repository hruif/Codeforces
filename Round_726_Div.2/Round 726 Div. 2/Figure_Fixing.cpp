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

#define MOD 1

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int t;
int nv[200000] , nt[200000];
ll difs[200000];
vvi edges;

vb visited;
ll dfs(int par, int n) {
	if (visited[n]) return 0;
	visited[n] = true;
	ll cur = difs[n];
	F0R(i, sz(edges[n])) {
		int nn = edges[n][i];
		cur -= dfs(n, nn);
	}
	return cur;
}

int main() {
	cin >> t;
	while (t--) {
		edges.clear();
		visited.clear();

		int n, m;
		cin >> n >> m;
		edges.resize(n);
		F0R(i, n) cin >> nv[i];
		F0R(i, n) cin >> nt[i];
		F0R(i, m) {
			int a, b;
			cin >> a >> b;
			a--; b--;
			edges[a].push_back(b);
			edges[b].push_back(a);
		}
		F0R(i, n) difs[i] = nv[i] - nt[i];
		int difsum = 0;
		F0R(i, n) difsum += difs[i];
		if (difsum % 2 != 0) cout << "NO\n";
		else {
			vi cols(n, -1);
			queue<pii> q;
			cols[0] = 0;
			F0R(i, sz(edges[0])) q.push({ edges[0][i], 0 });
			bool bip = true;
			while (!q.empty()) {
				int n = q.front().first, par = q.front().second;
				q.pop();
				int col = 1 - cols[par];
				if (cols[n] != -1) {
					if (cols[n] == col) continue;
					else {
						bip = false;
						break;
					}
				}
				cols[n] = col;
				F0R(i, sz(edges[n])) q.push({ edges[n][i], n });
			}
			if (!bip) cout << "YES\n";
			else {
				visited.resize(n, false);
				if (dfs(-1, 0) != 0) cout << "NO\n";
				else cout << "YES\n";
			}
		}
	}
}