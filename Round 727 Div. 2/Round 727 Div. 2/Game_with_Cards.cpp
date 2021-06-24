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

	int ll = n, lr = n;
	pii rl, rr;
	rl = rr = { -1, m + 1 };
	bool possible = true;
	RF0R(i, n) {
		int nll = ll, nlr = lr;
		pii nrl = rl, nrr = rr;
		if (k[i] >= l[i].first && k[i] <= l[i].second && k[i] >= rl.first && k[i] <= rl.second) {
			if (lr != -1) {
				dp[i].first = lr;
				nll = i;
			}
		}
		else {
			nll = -1;
			nrl = { max(nrl.first, l[i].first), min(nrl.second, l[i].second) };
		}
		if (k[i] >= r[i].first && k[i] <= r[i].second) {
			if (ll != 1) {
				nlr = i;
				dp[i].second = ll;
			}
		}
		else nlr = -1;
		ll = nll; lr = nlr;
		rl = nrl; rr = nrr;
		if (ll == -1 && lr == -1) {
			possible = false;
			break;
		}
	}
	if (!possible) cout << "No\n";
	else {
		cout << "Yes\n";
		bool side = dp[0].second != -1;
		cout << side ? 1 : 0;
		if (side) {
			if (dp[0].second != -1) {
				side = 0;
			}
		}
		else {
			if (dp[0].first != -1) {
				side = 1;
			}
		}
		FOR(i, 1, n) {
			cout << ' ' << side ? 1 : 0;
			if (side) {
				if (dp[i].second != -1) {
					side = 0;
				}
			}
			else {
				if (dp[i].first != -1) {
					side = 1;
				}
			}
		}
	}
}