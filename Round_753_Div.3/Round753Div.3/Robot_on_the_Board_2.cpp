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

int t, n, m;
char board[2000][2000];
int cnts[2000][2000];
bool visited[2000][2000], proc[2000][2000];

vpii cloop;
int track(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m) return 0;
	if (proc[x][y]) {
		cloop.push_back({ x, y });
		return 0;
	}
	if (cnts[x][y] != 0) return cnts[x][y];
	proc[x][y] = true;
	int moves = 0;
	switch (board[x][y]) {
	case 'U':
		moves = track(x - 1, y);
		break;
	case 'D':
		moves = track(x + 1, y);
		break;
	case 'L':
		moves = track(x, y - 1);
		break;
	case 'R':
		moves = track(x, y + 1);
		break;
	}
	proc[x][y] = false;
	if (!cloop.empty()) {
		if (pii(x, y) == cloop[0]) {
			int len = cloop.size();
			for (auto x : cloop) {
				cnts[x.first][x.second] = len;
			}
			cloop.clear();
		}
		else cloop.push_back({ x, y });
	}
	else cnts[x][y] = moves + 1;
	visited[x][y] = true;
	return moves + 1;
}

void clear_all() {
	F0R2(i, j, n, m) visited[i][j] = false;
	F0R2(i, j, n, m) proc[i][j] = false;
	F0R2(i, j, n, m) cnts[i][j] = 0;
}

int main() {
	fast_cin();

	cin >> t;
	while (t--) {
		cin >> n >> m;
		F0R2(i, j, n, m) cin >> board[i][j];
		
		F0R(i, n) {
			F0R(j, m) {
				if (!visited[i][j]) track(i, j);
			}
		}
		pii ans;
		int bestD = 0;
		F0R2(i, j, n, m) {
			if (cnts[i][j] > bestD) {
				bestD = cnts[i][j];
				ans = { i, j };
			}
		}
		cout << ans.first + 1 << ' ' << ans.second + 1 << ' ' << bestD << '\n';
		clear_all();
	}
}