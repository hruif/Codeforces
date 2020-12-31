#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <unordered_set>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vc = vector<char>;
using pii = pair<int, int>;
using vpii = vector<pii>;

#define FORI(i, a, b, p) for (int i = a; i < b; i += p)
#define FOR(i, a, b) FORI(i, a, b, 1)
#define F0R(i,b) FOR(i, 0, b)
#define RFOR(i, a, b) for (int i = a; i >= b; i--)
#define RF0R(i, a) RFOR(i, a, 0)

#define MOD 1 // placeholder

ll k, l, r, t, x, y;
unordered_set<ll> levels;

int main() {
	cin >> k >> l >> r >> t >> x >> y;
	if (y < x) {
		if (r - k < y) {
			k -= x;
			t--;
		}
		ll dif = x - y;
		ll td = k - l;
		if (td / dif >= t && k - t * dif >= l) cout << "Yes\n";
		else cout << "No\n";
	}
	else if (y == x) {
		if (k + x <= r || k - x >= l) cout << "Yes\n";
		else cout << "No\n";
	}
	else {
		ll wl = k;
		ll ds = 0;
		bool canfill = true;
		while (ds < t) {
			ll maxtake = (wl - l) / x;
			ds += maxtake;
			wl -= maxtake * x;
			if (ds >= t) break;
			wl += y;
			if (wl > r) {
				canfill = false;
				break;
			}
			if (levels.find(wl) != levels.end()) break;
			levels.insert(wl);
		}
		if (canfill) cout << "Yes\n";
		else cout << "No\n";
	}
}