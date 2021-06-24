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
#define FORI(i, a, b, p) for (int i = a; i < b; i += p)
#define FOR(i, a, b) FORI(i, a, b, 1)
#define F0R(i,b) FOR(i, 0, b)
#define F0R2(i, j, a, b) F0R(i, a) F0R(j, b)
#define RFOR(i, a, b) for (int i = a; i >= b; i--)
#define RF0R(i, a) RFOR(i, a, 0)

#define MOD 1

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int n;
ll a[100000], b[100000];
vector<pair<ll, ll>> prods;

int main() {
	cin >> n;
	prods.rsz(n);
	F0R(i, n) cin >> prods[i].second >> prods[i].first;
	sort(all(prods));

	ll bought = 0, cost = 0;
	int l = 0, r = n - 1;
	while (l < r) {
		ll dif = bought - prods[l].first;
		if (dif >= 0) {
			bought += prods[l].second;
			cost += prods[l].second;
			l++;
		}
		else {
			dif = prods[l].first - bought;
			if (dif < prods[r].second) {
				bought += dif;
				cost += dif * 2;
				prods[r].second -= dif;
			}
			else {
				bought += prods[r].second;
				cost += prods[r].second * 2;
				r--;
			}
		}
	}
	ll dif = prods[l].first - bought;
	if (dif > 0) {
		dif = min(dif, prods[l].second);
		prods[l].second -= dif;
		cost += dif * 2;
		bought += dif;
		dif = (prods[l].first - bought + 1) / 2;
	}
	if (dif <= 0) {
		cost += prods[l].second;
	}
	cout << cost << '\n';
}