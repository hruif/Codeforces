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

#define MOD (ll)(998244353)
#define MAX_N (1000000 + 1)

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_cin();
	int n, m, k;
	int checker[2] = { 0, 0 };
	int freec = 0, freer = 0;
	int badc = 0, badr = 0;
	int cols[MAX_N][2], rows[MAX_N][2];
	memset(cols, 0, sizeof(cols));
	memset(rows, 0, sizeof(rows));
	vll P(MAX_N, 0);
	map<pii, int> M;

	P[0] = 1;
	for (int i = 1; i < MAX_N; i++) {
		P[i] = P[i - 1] * 2 % MOD;
	}

	cin >> n >> m >> k;
	freec = m, freer = n;
	F0R(i, k) {
		int x, y, t;
		cin >> x >> y >> t;
		x--; y--;

		pii sq = { x, y };
		if (M.find(sq) == M.end()) M[sq] = -1;
		auto& msq = M[sq];

		bool init_freec = !cols[y][0] && !cols[y][1], init_freer = !rows[x][0] && !rows[x][1];
		bool init_badc = cols[y][0] && cols[y][1], init_badr = rows[x][0] && rows[x][1];
		if (msq != -1) {
			int v = msq;
			int par = (x + y + v) % 2;
			checker[par]--;
			par = (x + v) % 2;
			cols[y][par]--;
			par = (y + v) % 2;
			rows[x][par]--;

			msq = -1;
		}

		if (t != -1) {
			int par = (x + y + t) % 2;
			checker[par]++;
			par = (x + t) % 2;
			cols[y][par]++;
			par = (y + t) % 2;
			rows[x][par]++;

			msq = t;
		}
		bool cur_freec = !cols[y][0] && !cols[y][1], cur_freer = !rows[x][0] && !rows[x][1];
		bool cur_badc = cols[y][0] && cols[y][1], cur_badr = rows[x][0] && rows[x][1];

		if (init_freec && !cur_freec) freec--;
		if (!init_freec && cur_freec) freec++;

		if (init_freer && !cur_freer) freer--;
		if (!init_freer && cur_freer) freer++;

		if (init_badc && !cur_badc) badc--;
		if (!init_badc && cur_badc) badc++;

		if (init_badr && !cur_badr) badr--;
		if (!init_badr && cur_badr) badr++;

		ll val = 0;
		if (badc == 0) {
			val += P[freec];
		}
		if (badr == 0) {
			val += P[freer];
		}
		if (checker[0] == 0) val--;
		if (checker[1] == 0) val--;

		cout << val % MOD << '\n';
	}
}