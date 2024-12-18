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

ll n, m, k;
vector<vll> grc, gdc;

int main() {
	cin >> n >> m >> k;
	grc.rsz(n, vll(m - 1));
	gdc.rsz(n - 1, vll(m));
	F0R(i, n) {
		F0R(j, m - 1) cin >> grc[i][j];
	}
	F0R(i, n - 1) {
		F0R(j, m) cin >> gdc[i][j];
	}
	vector<vector<vll>> ans(n, vector<vll>(m, vll(k + 1, k * 1000001)));
	F0R2(i, j, n, m) ans[i][j][0] = 0;
	F1R(l, k + 1) {
		F0R(i, n) {
			F0R(j, m) {
				if (i > 0) ans[i][j][l] = min(ans[i][j][l], ans[i - 1][j][l - 1] + gdc[i - 1][j]);
				if (i < n - 1) ans[i][j][l] = min(ans[i][j][l], ans[i + 1][j][l - 1] + gdc[i][j]);
				if (j > 0) ans[i][j][l] = min(ans[i][j][l], ans[i][j - 1][l - 1] + grc[i][j - 1]);
				if (j < m - 1) ans[i][j][l] = min(ans[i][j][l], ans[i][j + 1][l - 1] + grc[i][j]);
			}
		}
	}
	if (k % 2) {
		F0R(i, n) {
			F0R(j, m) cout << -1 << ' ';
			cout << '\n';
		}
	}
	else {
		F0R(i, n) {
			F0R(j, m) {
				cout << ans[i][j][k / 2] * 2 << ' ';
			}
			cout << '\n';
		}
	}
}