#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <queue>
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
int h[200000];

int main() {
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		F0R(i, n) cin >> h[i];

		int t = h[0];
		int b = h[0];
		bool imp = false;
		FOR(i, 1, n) {
			int newt = min(h[i] + (k - 1), t + (k - 1));
			if (newt < h[i] || newt < b - (k - 1)) imp = true;
			int newb = max(0, max(b - (k - 1), h[i]));
			if (newb > t + (k - 1) || newb > h[i] + (k - 1)) imp = true;
			if (newb > newt) imp = true;

			if (imp) {
				break;
			}
			t = newt;
			b = newb;
		}
		if (b > h[n - 1]) imp = true;

		if (imp) cout << "NO\n";
		else cout << "YES\n";
	}
}