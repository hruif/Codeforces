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

#define MOD 998244353

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int q;
ll a[500000], c[500000];
int p[500000][20];


int main() { 
	memset(p, -1, sizeof(p));

	cin >> q >> a[0] >> c[0];
	int i = 1;

	vpii all_bought;
	while (q--) {
		int op;
		cin >> op;
		if (op == 1) {
			cin >> p[i][0] >> a[i] >> c[i];
			int cur = p[i][0];
			for (int j = 1; j < 20; j++) {
				if (p[i][j - 1] == -1) break;
				p[i][j] = p[p[i][j - 1]][j - 1];
			}
		}
		else {
			int v, w;
			cin >> v >> w;
			vector<int> q;
			ll cnt = 0, cost = 0;
			q.push_back(v);
			while (!q.empty()) {
				v = q.back();
				if (v > 0 && p[v][0] < 0) cout << "E2 HERE <-------------" << '\n';
				while (v > 0 && a[p[v][0]] > 0) {
					int po = 0;
					for (; po < 20; po++) {
						if (p[v][po] == -1 || a[p[v][po]] == 0) break;
					}
					po--;
					if (po < 0) cout << "E1 HERE <-----------" << '\n';
					v = p[v][po];
					q.push_back(v);
				}
				if (v < 0) cout << "E3 HERE <-----------------" << '\n';
				if (a[v] >= w) {
					cnt += w;
					cost += w * c[v];
					a[v] -= w;
					q.clear();
				}
				else {
					cost += c[v] * a[v];
					cnt += a[v];
					w -= a[v];
					a[v] = 0;
					q.pop_back();
				}
			}
			cout << cnt << ' ' << cost << '\n';
		}

		i++;
	}
}