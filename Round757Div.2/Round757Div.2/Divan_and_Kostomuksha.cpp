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
#define MAX_V (int)(2e7)

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

bool sieve[20000001];
vector<int> primes;

int n;
int a[1000000];
ll cnts[MAX_V + 1], c[MAX_V + 1];
ll dp[MAX_V + 1];

int main() {
	fast_cin();
	primes.push_back(2);
	for (int i = 3; i * i <= MAX_V; i += 2) {
		if (!sieve[i]) {
			for (int j = i * i; j <= MAX_V; j += i) {
				sieve[j] = true;
			}
		}
	}
	for (int i = 3; i <= MAX_V; i += 2) {
		if (!sieve[i]) primes.push_back(i);
	}

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnts[a[i]]++;
		c[a[i]]++;
	}
	for (int i = 1; i <= MAX_V; i++) {
		for (int j = i + i; j <= MAX_V; j += i) {
			c[i] += cnts[j];
		}
		dp[i] = c[i] * i;
	}
	for (int i = MAX_V; i >= 1; i--) {
		for (auto x : primes) {
			ll j = i * x;
			if (j > MAX_V) break;
			dp[i] = max(dp[i], dp[j] + i * (c[i] - c[j]));
		}
	}
	cout << dp[1] << '\n';
}