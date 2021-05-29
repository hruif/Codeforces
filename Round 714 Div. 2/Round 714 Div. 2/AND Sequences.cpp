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
int a[200000];

int main() {
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		int tand = a[0];
		for (int i = 1; i < n; i++) tand = tand & a[i];
		ll tc = 0;
		for (int i = 0; i < n; i++) if (a[i] == tand) tc++;

		ll ans = tc * (tc - 1);
		for (int i = n - 2; i >= 1; i--) {
			ans *= i;
			ans %= 1000000007;
		}
		cout << ans % 1000000007 << '\n';
	}
}