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
int a[100];

int main() {
	cin >> t;
	while (t--) {
		int n, d;
		cin >> n >> d;
		F0R(i, n) cin >> a[i];

		bool clean = true;
		F0R(i, n) {
			if (a[i] > d) {
				clean = false;
				break;
			}
		}
		if (clean) {
			cout << "YES\n";
			continue;
		}
		sort(a, a + n);
		if (a[0] + a[1] <= d) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
}