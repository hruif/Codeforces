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
pair<pii, pii> dp[1000][1000];
pii par[1000][1000];

int main() {
	cin >> n;
	F0R2(i, j, n, n) cin >> grid[i][j];
	F0R2(i, j, n, n) {
		int ts = 0, fs = 0;
		{
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
		}

		if (i == 0 && j == 0) {
			dp[i][j] = { {ts, fs}, {ts, fs} };
			continue;
		}

		dp[i][j] = { {1000001, 1000001}, {1000001, 1000001} };
		if (i > 0) {
			if (dp[i - 1][j].first.first < dp[i][j].first.first) {
				dp[i][j].first = dp[i - 1][j].first;
			}
			if (dp[i - 1][j].second.second < dp[i][j].second.second) {
				dp[i][j].second = dp[i - 1][j].second;
			}
		}
		if (j > 0) {
			if (dp[i][j - 1].first.first < dp[i][j].first.first) {
				dp[i][j].first = dp[i][j - 1].first;
				par[i][j].first = 3;
			}
			if (dp[i][j - 1].second.second < dp[i][j].second.second) {
				dp[i][j].second = dp[i][j - 1].second;
				par[i][j].second = 3;
			}
		}
		dp[i][j].first.first += ts;
		dp[i][j].first.second += fs;
		dp[i][j].second.first += ts;
		dp[i][j].second.second += fs;
		int a = 5;
	}
	int m = min(min(dp[n - 1][n - 1].first.first, dp[n - 1][n - 1].first.second),
		min(dp[n - 1][n - 1].second.first, dp[n - 1][n - 1].second.second));
	int zx = -1, zy = -1;
	F0R2(i, j, n, n) {
		if (grid[i][j] == 0) {
			zx = i; zy = j;
			break;
		}
	}
	if (zx != -1 && m > 1) {
		cout << "1\n";
		F0R(i, zx) cout << "D";
		F0R(i, zy) cout << "R";
		F0R(i, n - zx - 1) cout << "D";
		F0R(i, n - zy - 1) cout << "R";
		cout << '\n';
	}
	else {
		int x = n - 1, y = n - 1;
		cout << m << '\n';
		vc ans;
		F1R(i, n + n - 1) {
			if (min(dp[n - 1][n - 1].first.first, dp[n - 1][n - 1].first.second) <
				min(dp[n - 1][n - 1].second.first, dp[n - 1][n - 1].second.second)) {
				if (par[x][y].first == 0) {
					ans.push_back('D');
					x--;
				}
				else {
					ans.push_back('R');
					y--;
				}
			}
			else {
				if (par[x][y].second == 0) {
					ans.push_back('D');
					x--;
				}
				else {
					ans.push_back('R');
					y--;
				}
			}
		}
		RF0R(i, sz(ans)) {
			cout << ans[i];
		}
		cout << '\n';
	}
}