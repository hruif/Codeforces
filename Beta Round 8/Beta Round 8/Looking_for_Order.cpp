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

int hx, hy;
int n;
vpii obj;
int dp[1 << 24];
int par[1 << 24];

bool find_ans(int curmask, int dist) {
	if (dp[curmask] <= dist) {
		return false;
	}
	dp[curmask] = dist;
	return true;
}

int find_dist(int i) {
	return obj[i].first * obj[i].first + obj[i].second * obj[i].second;
}

int main() {
	memset(par, -1, sizeof(par));

	cin >> hx >> hy;
	cin >> n;
	F0R(i, n) {
		obj.emplace_back();
		cin >> obj.back().first >> obj.back().second;
	}
	F0R(i, n) {
		obj[i].first -= hx;
		obj[i].second -= hy;
	}
	F0R(i, 1 << 24) dp[i] = 1000000000;
	queue<pair<pii, int>> q, nq;
	dp[0] = 0;
	q.push({ { 0, 0 }, 0 });
	int curlen = 0;
	while (!q.empty() || !nq.empty()) {
		if (q.empty() || q.front().second != curlen) {
			curlen++;
			swap(q, nq);
		}

		int curmask = q.front().first.first;
		int curdist = q.front().first.second;
		int len = q.front().second;
		q.pop();
		if (curdist != dp[curmask]) continue;

		int front = 0;
		for (int i = 0; i < n; i++) {
			if (!(curmask & (1 << i))) break;
			front = i + 1;
		}
		if (front == n) continue;
		for (int i = front; i < n; i++) {
			if (!(curmask & (1 << i))) {
				int nmask = curmask | (1 << i);
				int ndist = curdist + find_dist(i) * 2;
				if (find_ans(nmask, ndist)) {
					par[nmask] = curmask;
					nq.push({ { nmask, ndist }, len + 1 });
				}
			}
		}
		int omask = curmask;
		curmask |= (1 << front);
		curdist += find_dist(front);
		for (int i = front + 1; i < n; i++) {
			if (!(curmask & (1 << i))) {
				int nmask = curmask | (1 << i);
				int xd = obj[front].first - obj[i].first;
				int yd = obj[front].second - obj[i].second;
				int ndist = curdist + find_dist(i) + 
					xd * xd + yd * yd;
				if (find_ans(nmask, ndist)) {
					par[nmask] = omask;
					q.push({ { nmask, ndist }, len + 2 });
				}
			}
		}
	}
	cout << dp[(1 << n) - 1] << '\n';
	vi ans;
	ans.push_back(0);
	int cur = (1 << n) - 1;
	while (cur != 0) {
		int nextm = par[cur];
		for (int i = 0; i < n; i++) {
			int b = 1 << i;
			if ((b & cur) && !(b & nextm)) ans.push_back(i + 1);
		}
		cur = nextm;
		ans.push_back(0);
	}
	RF0R(i, sz(ans)) cout << ans[i] << ' ';
	cout << '\n';
}