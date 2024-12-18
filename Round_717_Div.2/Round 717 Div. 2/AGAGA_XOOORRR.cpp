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
ll a[2000];
ll xors[2000];
bool zs[2000];

int main() {
	cin >> t;
	while (t--) {
		F0R(i, 2000) zs[i] = false;

		int n;
		cin >> n;
		F0R(i, n) cin >> a[i];
		xors[0] = a[0];
		FOR(i, 1, n) xors[i] = xors[i - 1] ^ a[i];
		F0R(i, n) if (!xors[i]) zs[i] = true;
		bool iseq = false;
		F0R(i, n - 1) {
			if ((xors[n - 1] ^ xors[i]) == xors[i]) iseq = true;
		}
		F0R(i, n) {
			if (xors[i] == xors[n - 1]) {
				FOR(j, i + 1, n - 1) {
					if (xors[j] == 0) iseq = true;
				}
			}
		}
		if (iseq) cout << "YES\n";
		else cout << "NO\n";
	}
}