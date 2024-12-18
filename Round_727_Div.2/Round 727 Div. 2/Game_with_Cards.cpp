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
#define F0R(i,b) FOR(i, 0, b)
#define F0R2(i, j, a, b) F0R(i, a) F0R(j, b)
#define RFOR(i, a, b) for (int i = a - 1; i >= b; i--)
#define RF0R(i, a) RFOR(i, a, 0)

#define MOD 1

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int n, m;
int k[100001];
pii l[100001], r[100001];
vpii dp;

int main() {
	cin >> n >> m;
	dp.resize(n, { -1, -1 });
	F0R(i, n) {
		cin >> k[i];
		cin >> l[i].first >> l[i].second;
		cin >> r[i].first >> r[i].second;
	}

	pii lr, rr;
	pair<bool, bool> canTake = { true, true };
	lr = rr = { -1, m + 1 };
	RF0R(i, n) {
		lr.first = max(lr.first, l[i].first); lr.second = min(lr.second, l[i].second);
		rr.first = max(rr.first, r[i].first); rr.second = min(rr.second, r[i].second);
		{
			if (canTake.second && (lr.first <= k[i] && lr.second >= k[i])) {
				lr = { -1, m };
				canTake.first = true;
				dp[i].first = 1;
			}
			if (canTake.first && (rr.first <= k[i] && rr.second >= k[i])) {
				rr = { -1, m };
				canTake.second = true;
				dp[i].second = 1;
			}
		}
		lr.first = max(lr.first, l[i].first); lr.second = min(lr.second, l[i].second);
		rr.first = max(rr.first, r[i].first); rr.second = min(rr.second, r[i].second);

		if (l[i].first > k[i] || l[i].second < k[i]) canTake.first = false;
		if (r[i].first > k[i] || r[i].second < k[i]) canTake.second = false;
	}
	if (l[0].first > 0) dp[0].second = -1;
	if (r[0].first > 0) dp[0].first = -1;

	if (dp[0].first == -1 && dp[0].second == -1) cout << "No\n";
	else {
		cout << "Yes\n";

		bool side;
		if (dp[0].first == -1) side = true;
		else side = false;
		int p = 0;
		while (p < n) {
			if (side) cout << "1 ";
			else cout << "0 ";
			if (side) {
				if (dp[p].second != -1) side = !side;
			}
			else if (dp[p].first != -1) side = !side;
			p++;
		}
	}
}