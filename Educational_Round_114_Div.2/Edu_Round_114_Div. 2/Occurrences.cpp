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

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int n, m, k;
vb badnum;
vvi pre, nxt, numarrs;
vvi A, B;

int main() {
	fast_cin();

	cin >> n >> m >> k;
	A.rsz(n);
	numarrs.rsz(k + 1);
	badnum.rsz(k + 1, false);
	pre.rsz(k + 1); nxt.rsz(k + 1);
	F0R(i, n) {
		int c;
		cin >> c;
		A[i].rsz(c);
		F0R(j, c) {
			cin >> A[i][j];
			numarrs[A[i][j]].push_back(i);
		}
	}
	F0R(i, n) {
		F1R(j, sz(A[i])) {
			pre[A[i][j]].push_back(A[i][j - 1]);
			nxt[A[i][j - 1]].push_back(A[i][j]);
		}
	}
	queue<int> q;
	F0R(i, k + 1) {
		sort(all(pre[i]));
		pre[i].erase(unique(all(pre[i])), pre[i].end());
		sort(all(nxt[i]));
		nxt[i].erase(unique(all(nxt[i])), nxt[i].end());

		if (sz(pre[i]) >= 2 || sz(nxt[i]) >= 2) {
			badnum[i] = true;
			q.push(i);
		}
	}
	vb checked(n, false);
	while (!q.empty()) {
		int num = q.front();
		q.pop();

		for (auto x : numarrs[num]) {
			if (checked[x]) continue;
			checked[x] = true;
			F0R(i, sz(A[x])) {
				int curn = A[x][i];
				if (badnum[curn]) continue;
				badnum[curn] = true;
				q.push(curn);
			}
		}
	}
	int cnt = 0;
	F1R(i, k + 1) {
		if (sz(numarrs) == 0) cnt++;
	}
	F1R(i, k + 1) {
		if (badnum[i]) continue;
		if (sz(pre[i]) == 0) {
			B.emplace_back();
			auto& b = B.back();
			int cur = i;
			while (true) {
				b.push_back(cur);
				if (nxt[cur].empty()) break;
				cur = nxt[cur][0];
			}
		}
	}

	map<int, int> bsz;
	F0R(i, sz(B)) bsz[sz(B[i])]++;
	vll dp(m + 1, 0);
	dp[0] = 1;
	for (int i = 1; i <= m; i++) {
		for (auto x : bsz) {
			if (x.first > i) break;
			int xsz = x.first, c = x.second;
			dp[i] += dp[i - xsz] * c;
			dp[i] += dp[i - 1] * cnt;
			dp[i] %= MOD;
		}
	}
	cout << dp[m] << '\n';
}