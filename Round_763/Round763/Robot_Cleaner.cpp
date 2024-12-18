#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>
#include <cmath>
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
#include <array>

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
int r[2], c[2];

int main() {
	fast_cin();

	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		cin >> r[0] >> r[1];
		cin >> c[0] >> c[1];
		int moves = 0;
		bool reached = r[0] == c[0] || r[1] == c[1];
		int dr = 1, dc = 1;
		if (r[0] == n) dr = -1;
		if (r[1] == m) dc = -1;
		while (!reached) {
			r[0] += dr;
			r[1] += dc;
			if (r[0] == n || r[0] == 1) dr = -dr;
			if (r[1] == m || r[1] == 1) dc = -dc;
			reached = r[0] == c[0] || r[1] == c[1];
			moves++;
		}
		cout << moves << '\n';
	}
}