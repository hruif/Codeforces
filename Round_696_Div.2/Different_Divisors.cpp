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

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int t;
vi primes;

void findprimes() {
	for (int i = 2; i < 30000; i++) {
		bool nonprime = false;
		for (int j = 0; j < primes.size(); j++) {
			if (i % primes[j] == 0) {
				nonprime = true;
				break;
			}
		}
		if (!nonprime) primes.push_back(i);
	}
}

int main() {
	findprimes();

	cin >> t;
	while (t--) {
		int d;
		cin >> d;
		int p1 = 0;
		while (primes[p1] - 1 < d) p1++;
		int val = primes[p1];
		while (primes[p1] - val < d) p1++;
		cout << primes[p1] * val << '\n';
	}
}