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

int m;
vi weights;
bool dp[20][1001][11];

int main() {
	F0R(i, 10) {
		char c;
		cin >> c;
		if (c == '1') weights.push_back(i + 1);
	}
	cin >> m;
	dp[0][0][0] = true;
	for (auto x : weights) {
		dp[x + 9][1][x] = true;
	}
	for (int i = 2; i <= m; i++) {
		for (int j = -9; j <= 9; j++) {

			if (i % 2 && j >= 0) continue;
			if (!(i % 2) && j <= 0) continue;

			for (auto k : weights) {

				int next;
				if (i % 2) next = j + k;
				else next = j - k;

				if (i % 2 && next <= 0) continue;
				if (!(i % 2) && next >= 0) continue;

				for (auto l : weights) {
					if (dp[j + 9][i - 1][l] && k != l) {
						dp[next + 9][i][k] = true;
						break;
					}
				}
			}
		}
	}
	bool possible = false;

	for (int i = -9; i <= 10; i++) {
		for (auto x : weights) {
			if (dp[i + 9][m][x]) {
				cout << "YES\n";
				int v = i;
				int mo = m;
				vi ans;
				while (mo != 0) {
					ans.push_back(x);
					if (mo % 2) v -= x;
					else v += x;
					mo--;
					for (auto y : weights) {
						if (x == y) continue;
						if (dp[v + 9][mo][y]) {
							x = y;
							break;
						}
					}
				}

				RF0R(i, m) {
					cout << ans[i] << ' ';
				}
				cout << '\n';

				possible = true;
				break;
			}
		}
		if (possible) break;
	}
	if (!possible) cout << "NO\n";
}