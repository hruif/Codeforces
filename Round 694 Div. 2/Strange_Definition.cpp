#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vb = vector<bool>;
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
int pcv[1000001];
vi primes;
vi a, vals(1000000, 0);
set<int> uv;

void findPrimes() {
	for (int i = 2; i <= 1000; i++) {
		bool nonp = false;
		int ps = primes.size();
		int st = sqrt(i);
		for (int j = 0; j < ps; j++) {
			if (primes[j] > st) break;
			if (i % primes[j] == 0) {
				nonp = true;
				break;
			}
		}
		if (nonp) continue;
		primes.push_back(i);
	}
}

void ato(int ind) {
	int val = a[ind];
	int atdo = 0;
	int ps = primes.size();
	F0R(i, ps) {
		if (val <= 1) break;

		int p = primes[i];
		if (p > sqrt(val)) {
			if (atdo == 0) atdo = 1;
			atdo *= val;
			break;
		}

		int e = 0;
		while (val % p == 0) {
			val /= p;
			e++;
		}
		if (e % 2 == 1 && atdo == 0) atdo = 1;
		if (e % 2 == 1) atdo *= p;
	}
	vals[atdo]++;
	uv.insert(atdo);
}

void precompVals(int v, int e, int prev) {
	FOR(i, prev, primes.size()) {
		int pi = primes[i];
		int newv = v * pi;
		if (newv > 1000000) break;
		if (newv % (pi * pi) == 0) newv /= pi * pi;
	}
}

int main() {
	findPrimes();

	cin >> t;
	while (t--) {
		a.clear(), uv.clear();

		ll n, q;
		cin >> n;
		a.resize(n);
		F0R(i, n) cin >> a[i];
		cin >> q;

		F0R(i, n) ato(i);

		int nmax = 0;
		int amax = vals[0] - 1;
		int amax2 = 0;
		for (auto i : uv) {
			int v = vals[i];
			if (v > nmax) nmax = v - 1;
		}
		for (auto i : uv) {
			if (i == 0) continue;
			int v = vals[i];
			if (v % 2 == 0) amax += v;
			else if (v > amax2) amax2 = v - 1;
		}

		F0R(i, q) {
			ll w;
			cin >> w;

			if (w > 0) {
				cout << max(amax, amax2) + 1 << '\n';
			}
			else {
				cout << nmax + 1 << '\n';
			}
		}
		for (auto i : uv) {
			vals[i] = 0;
		}
	}
}