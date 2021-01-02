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
ll b[61];
ll ans[500000];

int main() {
	cin >> t;
	F0R(i, t) {
		memset(b, 0, sizeof(b));
		ll o = 1;

		int n;
		cin >> n;
		F0R(i, n) cin >> x[i];
		F0R(i, n) {
			F0R(j, 61) {
				ll bi = o << j;
				if (bi > x[i]) break;
				if (x[i] & bi) b[j]++;
			}
		}
		ll sum = 0;
		F0R(i, n) {
			ll s1 = 0, s2 = 0;
			F0R(j, 61) {
				ll bi = o << j;
				bool bin = x[i] & bi;
				bi %= MOD;
				if (bin) {
					s1 += (b[j] * bi) % MOD;
					s2 += (n * bi) % MOD;
				}
				else s2 += (b[j] * bi) % MOD;
			}
			s1 %= MOD;
			s2 %= MOD;
			sum += (s1 * s2) % MOD;
		}

		cout << sum % MOD << '\n';
	}
}