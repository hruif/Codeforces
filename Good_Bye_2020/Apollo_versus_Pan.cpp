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
using vc = vector<char>;
using pii = pair<int, int>;
using vpii = vector<pii>;

#define FORI(i, a, b, p) for (int i = a; i < b; i += p)
#define FOR(i, a, b) FORI(i, a, b, 1)
#define F0R(i,b) FOR(i, 0, b)
#define RFOR(i, a, b) for (int i = a; i >= b; i--)
#define RF0R(i, a) RFOR(i, a, 0)

#define MOD ((ll)(1e9 + 7))

int t;
ll x[500000];
ll b[60];

int main() {
	cin >> t;
	while (t--) {
		ll o = 1;

		int n;
		cin >> n;
		F0R(i, n) cin >> x[i];
		F0R(i, n) x[i] %= MOD;
		F0R(i, n) {
			F0R(j, 60) {
				ll bi = o << j;
				if (x[i] & (bi)) b[j]++;
			}
		}
		ll sum = 0;
		F0R(i, n) {
			ll s1 = 0;
			F0R(j, 60) {
				ll bi = o << j;
				if (x[i] & (bi)) s1 += (b[j] * ((bi) % MOD)) % MOD;
				s1 %= MOD;
			}
			ll s2 = 0;
			F0R(j, 60) {
				ll bi = o << j;
				if (x[i] & (bi)) s2 += (n * ((bi) % MOD)) % MOD;
				else s2 += (b[j] * ((bi) % MOD)) % MOD;
				s2 %= MOD;
			}
			sum += (s1 * s2) % MOD;
			sum %= MOD;
		}

		cout << sum << '\n';
	}
}