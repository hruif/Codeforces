#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <unordered_set>
#include <unordered_map>

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

#define MOD 1

int t;
unordered_map<ll, int> angs;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	cin >> t;
	while (t--) {
		angs.clear();

		int n;
		cin >> n;
		ll total = 0;
		F0R(i, n) {
			int x, y, u, v;
			cin >> x >> y >> u >> v;
			ll ydif = v - y, xdif = u - x;
			ll gd = abs(gcd(ydif, xdif));
			ydif /= gd, xdif /= gd;
			ll ang = (ydif << 32) + xdif;
			total += angs[-ang];
			angs[ang]++;
		}
		cout << total << '\n';
	}
}