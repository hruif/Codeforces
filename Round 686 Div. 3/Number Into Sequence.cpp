#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string.h>
#include <algorithm>
#include <math.h>
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

#define MOD 998244353

int t;
ll mults[40];
int nprimes = 0;
int primes[100000];

void findPrimes() {
	for (int i = 2; i <= 100000; i++) {
		bool prime = true;
		for (int j = 0; j < nprimes; j++) {
			if (primes[j] > sqrt(i)) {
				break;
			}
			if (i % primes[j] == 0) {
				prime = false;
				break;
			}
		}
		if (!prime) {
			continue;
		}
		primes[nprimes++] = i;
	}
}

int main() {
	findPrimes();
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		int max = 0;
		int maxi = 0;
		FOR(j, 0, nprimes) {
			int i = primes[j];
			if (i > sqrt(n)) {
				break;
			}
			ll tmpn = n;
			int tcount = 0;
			while (tmpn % i == 0) {
				tmpn /= i;
				mults[tcount] = i;
				tcount++;
			}
			if (tcount > 0) {
				mults[tcount - 1] *= tmpn;
			}
			if (tcount > max) {
				max = tcount;
				maxi = i;
			}
		}
		if (max == 1 || max == 0) {
			cout << "1\n" << n << '\n';
		}
		else {
			int count = 0;
			while (n % maxi == 0) {
				n /= maxi;
				mults[count] = maxi;
				count++;
			}
			mults[count - 1] *= n;
			cout << count << '\n';
			F0R(i, count) {
				if (i != 0) {
					cout << ' ';
				}
				cout << mults[i];
			}
			cout << '\n';
		}
	}
}