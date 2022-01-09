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

int n, k;
string s, unduped;
vector<int> udp;
vector<int> par, d, after;
vector<set<int>> ds;
vector<pair<int, int>> ch;

int cur = -1;
void set_after(int node) {
	if (node == -1) return;
	set_after(ch[node].first);
	if (cur != -1) after[cur] = node;
	cur = node;
	set_after(ch[node].second);
}

vector<bool> dup;
bool dfs_solve(int node, int cnt) {
	if (cnt > k) return false;
	if (node == -1) return false;
	if (s[node] == 'o')
		int alsldkj = 9324;
	if (dfs_solve(ch[node].first, cnt + 1)) { // left side needs to be duplicated
		dup[node] = true;
		dfs_solve(ch[node].second, 1);
		return true;
	}
	else if (after[node] == -1) return false; // if theres nothing afterwards, not optimal to duplicate
	else if (s[node] < s[after[node]]) { // if its lower than immediate after, always duplicate
		k -= cnt;
		dup[node] = true;
		dfs_solve(ch[node].second, 1);
		return true;
	}
	else if (s[node] == s[after[node]]) {
		if (udp[node] != unduped.size() - 1 && unduped[udp[node] + 1] > s[node]) {
			k -= cnt;
			dup[node] = true;
			dfs_solve(ch[node].second, 1);
			return true;
		}
	}
	return false;
}

void clear_and_resize(int n) {
	par.clear(); d.clear(); after.clear(); ch.clear();
	dup.clear(); udp.clear();

	par.resize(n, -1);
	d.resize(n, -1);
	after.resize(n, -1);
	ch.resize(n, { -1, -1 });
	dup.resize(n, false);
	udp.resize(n, -1);
}

void solve() {
	cin >> n >> k;
	clear_and_resize(n);
	cin >> s;
	for (int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		l--; r--;
		ch[i] = { l, r };
		if (l != -1) par[l] = i;
		if (r != -1) par[r] = i;
	}

	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	while (!q.empty()) {
		int cur = q.front().first, cur_d = q.front().second;
		q.pop();
		if (cur == -1) continue;
		d[cur] = cur_d;
		q.push({ ch[cur].first, cur_d + 1 });
		q.push({ ch[cur].second, cur_d + 1 });
	}
	set_after(0);

	vector<int> bef(n, -1);
	for (int i = 0; i < n; i++) {
		if (after[i] != -1) bef[after[i]] = i;
	}
	int start = -1;
	for (int i = 0; i < n; i++) if (bef[i] == -1) start = i;
	int cur = start;
	while (cur != -1) {
		udp[cur] = unduped.size();
		if (unduped.empty() || unduped.back() != s[cur]) unduped.push_back(s[cur]);
		else udp[cur]--;
		cur = after[cur];
	}

	dfs_solve(0, 1);
	string ans;
	cur = start;
	while (cur != -1) {
		ans.push_back(s[cur]);
		if (dup[cur]) ans.push_back(s[cur]);
		cur = after[cur];
	}
	cout << ans << '\n';
}

int main() {
	fast_cin();

	solve();
}