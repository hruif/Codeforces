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

int n;
int grid[1000][1000];
pair<pair<pii, bool>, pair<pii, bool>> dp[1000][1000];
pii par[1000][1000];

int main() {
	cin >> n;
	F0R2(i, j, n, n) cin >> grid[i][j];
	vector<vector<pair<pii, pii>>> toswitch(n, vector<pair<pii, pii>>(n, { {-1, -1}, {-1, -1} }));
	F0R2(i, j, n, n) {
		int ts = 0, fs = 0;
		if (grid[i][j] != 0) {
			while (grid[i][j] % 2 == 0) {
				grid[i][j] /= 2;
				ts++;
			}
			while (grid[i][j] % 5 == 0) {
				grid[i][j] /= 5;
				fs++;
			}
		}
		if (i == 0 && j == 0) {
			dp[i][j] = { { { ts, fs }, grid[i][j] == 0 }, { { ts, fs }, grid[i][j] == 0 } };
			continue;
		}

		dp[i][j] = { { {1000001, 1000001}, false}, { {1000001, 1000001}, false} };
		if (grid[i][j] == 0) {
			dp[i][j] = { { {1, 1}, true}, { {1, 1}, true} };
			continue;
		}
		if (i > 0) {
			if (dp[i - 1][j].first.second && !dp[i][j].first.second) {
				dp[i][j].first.second = true;
				toswitch[i][j].first = toswitch[i - 1][j].first;
			}
			if (dp[i - 1][j].first.first.first < dp[i][j].first.first.first) {
				dp[i][j].first = dp[i - 1][j].first;
			}

			if (dp[i - 1][j].second.second && !dp[i][j].second.second) {
				dp[i][j].second.second = true;
				toswitch[i][j].second = toswitch[i - 1][j].second;
			}
			if (dp[i - 1][j].second.first.second < dp[i][j].second.first.second) {
				dp[i][j].second = dp[i - 1][j].second;
			}
		}
		if (j > 0) {
			if (dp[i][j - 1].first.second && !dp[i][j].first.second) {
				dp[i][j].first.second = true;
				toswitch[i][j].first = toswitch[i][j - 1].first;
			}
			if (dp[i][j - 1].first.first.first < dp[i][j].first.first.first) {
				par[i][j].first = 3;
				dp[i][j].first = dp[i][j - 1].first;
			}
			

			if (dp[i][j - 1].second.second && !dp[i][j].second.second) {
				dp[i][j].second.second = true;
				toswitch[i][j].second = toswitch[i][j - 1].second;
			}
			if (dp[i][j - 1].second.first.second < dp[i][j].second.first.second) {
				par[i][j].second = 3;
				dp[i][j].second = dp[i][j - 1].second;
			}
		}
		if (toswitch[i][j].first.first != -2) {
			dp[i][j].first.first.first += ts;
			dp[i][j].first.first.second += fs;
		}
		if (toswitch[i][j].second.second != -2) {
			dp[i][j].second.first.first += ts;
			dp[i][j].second.first.second += fs;
		}
		if (dp[i][j].first.second && dp[i][j].first.first.first > 1) {
			dp[i][j].first = { {1, 1}, true };
			par[toswitch[i][j].first.first][toswitch[i][j].first.second].first = 
				3 - par[toswitch[i][j].first.first][toswitch[i][j].first.second].first;
			toswitch[i][j].first = { -2, -2 };
		}
		if (dp[i][j].second.second && dp[i][j].second.first.second > 1) {
			dp[i][j].second = { {1, 1}, true };
			par[toswitch[i][j].second.first][toswitch[i][j].second.second].second = 
				3 - par[toswitch[i][j].second.first][toswitch[i][j].second.second].second;
			toswitch[i][j].second = { -2, -2 };
		}
	}
	cout << min(min(dp[n - 1][n - 1].first.first.first, dp[n - 1][n - 1].first.first.second),
		min(dp[n - 1][n - 1].second.first.first, dp[n - 1][n - 1].second.first.second)) << '\n';
	int x = n - 1, y = n - 1;
	vi ans;
	F1R(i, n + n - 1) {
		if (min(dp[x][y].first.first.first, dp[x][y].first.first.second) <
			min(dp[x][y].second.first.first, dp[x][y].second.first.second)) {
			if (par[x][y].first == 0) {
				x--;
				ans.push_back(1);
			}
			else {
				y--;
				ans.push_back(0);
			}
		}
		else {
			if (par[x][y].second == 0) {
				x--;
				ans.push_back(1);
			}
			else {
				y--;
				ans.push_back(0);
			}
		}
	}
	RF0R(i, sz(ans)) cout << ((ans[i] == 1) ? 'D' : 'R');
	cout << '\n';
}