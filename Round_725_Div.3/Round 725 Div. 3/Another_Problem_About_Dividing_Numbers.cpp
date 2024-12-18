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
#define F1R(i, b) FOR(i, 1, b);
#define F0R2(i, j, a, b) F0R(i, a) F0R(j, b)
#define RFOR(i, a, b) for (int i = a - 1; i >= b; i--)
#define RF0R(i, a) RFOR(i, a, 0)

#define MOD 1

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int t;
vi primes;

int main() {
	FOR(i, 2, INT_MAX) {
		if (i > sqrt(1000000000)) break;
		bool prime = true;
		F0R(j, sz(primes)) {
			if (primes[j] > sqrt(i)) break;
			if (i % primes[j] == 0) {
				prime = false;
				break;
			}
		}
		if (prime) primes.push_back(i);
	}

	cin >> t;
	while (t--) {
		int a, b, k;
		cin >> a >> b >> k;
		int oa = a, ob = b;
		vi ap, bp;
		F0R(i, sz(primes)) {
			if (a == 1 && b == 1) break;
			while (a % primes[i] == 0) {
				ap.push_back(primes[i]);
				a /= primes[i];
			}
			while (b % primes[i] == 0) {
				bp.push_back(primes[i]);
				b /= primes[i];
			}
		}
		if (a != 1) {
			ap.push_back(a);
			a = 1;
		}
		if (b != 1) {
			bp.push_back(b);
			b = 1;
		}
		int p = 0;
		bool cando = true;
		if (k > sz(ap) + sz(bp)) cout << "NO\n";
		else if (k == 1) {
			if (sz(ap) == sz(bp)) cout << "NO\n";
			else {
				if (sz(ap) > sz(bp)) {
					int ai = 0;
					cando = true;
					F0R(i, sz(bp)) {
						while (ai < sz(ap) && ap[ai] != bp[i]) ai++;
						ai++;
					}
					if (ai > sz(ap)) cando = false;
					if (cando) cout << "YES\n";
					else cout << "NO\n";
				}
				else {
					int bi = 0;
					cando = true;
					F0R(i, sz(ap)) {
						while (bi < sz(bp) && bp[bi] != ap[i]) bi++;
						bi++;
					}
					if (bi > sz(bp)) cando = false;
					if (cando) cout << "YES\n";
					else cout << "NO\n";
				}
			}
		}
		else cout << "YES\n";
	}
}