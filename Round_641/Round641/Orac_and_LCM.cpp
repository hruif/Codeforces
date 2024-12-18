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

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int n;
int a[100000];
vector<ll> primes;
vector<vector<int>> pcnt;

ll fast_pow(ll b, ll e) {
	if (e == 0) return 1;
	ll val = fast_pow(b, e / 2);
	val *= val;
	if (e % 2) val *= b;
	return val;
}

int main() {
	fast_cin();

	primes.push_back(2);
	for (int i = 3; i <= 200000; i += 2) {
		bool p = true;
		for (auto x : primes) {
			if (x * x > i) break;
			if (i % x == 0) {
				p = false;
				break;
			}
		}
		if (p) primes.push_back(i);
	}
	pcnt.resize(primes.size());

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < primes.size(); j++) {
			ll x = primes[j];
			if (x * x > a[i]) break;
			int cnt = 0;
			while (a[i] % x == 0) {
				a[i] /= x;
				cnt++;
			}
			if (cnt > 0) pcnt[j].push_back(cnt);
		}
		if (a[i] > 1) {
			pcnt[lower_bound(all(primes), a[i]) - primes.begin()].push_back(1);
		}
	}
	ll ans = 1;
	for (int i = 0; i < primes.size(); i++) {
		sort(all(pcnt[i]));
		int cur_pcnt = 0;
		if (pcnt[i].size() >= n - 1) cur_pcnt = pcnt[i][pcnt[i].size() - n + 1];
		ans *= fast_pow(primes[i], cur_pcnt);
	}
	cout << ans << '\n';
}