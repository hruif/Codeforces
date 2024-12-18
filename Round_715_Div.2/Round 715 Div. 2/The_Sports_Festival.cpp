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

int n;
int s[2000];
pair<ll, int> sp[2000];
ll dp[2000][2000];

int main() {
	cin >> n;
	F0R(i, n) cin >> s[i];
	sort(s, s + n);
	sp[0] = { s[0], 1 };
	int disv = 0;
	F1R(i, n) {
		if (s[i] == s[i - 1]) {
			sp[disv].second++;
		}
		else {
			sp[++disv] = { s[i], 1 };
		}
	}
	disv++;
	F0R(i, disv) dp[i][i] = 0;
	F0R(dist, disv) {
		F0R(i, disv) {
			if (i + dist >= disv) break;
			int j = i + dist;
			ll dif = abs(sp[i].first - sp[j].first);
			dp[i][j] = min(dp[i + 1][j] + dif * sp[i].second, dp[i][j - 1] + dif * sp[j].second);
		}
	}
	cout << dp[0][disv - 1] << '\n';
}