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

int t;
bool visited[100][100][10001];

int main() {
	cin >> t;

	while (t--) {
		memset(visited, false, sizeof(visited));
		int n, m, k;
		cin >> n >> m >> k;
		queue<pair<pii, int>> q;
		q.push({ {0, 0}, 0 });
		bool poss = false;
		while (!q.empty()) {
			int x = q.front().first.first + 1, y = q.front().first.second + 1;
			int score = q.front().second;
			q.pop();
			if (visited[x - 1][y - 1][score]) continue;
			visited[x - 1][y - 1][score] = true;
			if (x == n && y == m) {
				if (score == k) {
					poss = true;
					break;
				}
				continue;
			}
			if (x < n) {
				int ns = score + y;
				if (ns <= k) q.push({ {x, y - 1}, ns });
			}
			if (y < m) {
				int ns = score + x;
				if (ns <= k) q.push({ {x - 1, y}, ns });
			}
		}
		if (poss) cout << "YES\n";
		else cout << "NO\n";
	}
}