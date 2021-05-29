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
ll b[200002];
unordered_set<int> nums;

int main() {
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		ll sum = 0;
		for (int i = 0; i < n + 2; i++) {
			cin >> b[i];
			sum += b[i];
		}
		sort(b, b + n + 2);
		int found = -1;
		for (int i = 0; i < n + 1; i++) {
			if (sum - b[i] == b[n + 1] * 2) {
				found = i;
			}
			if (found != -1) break;
		}
		if (found == -1) {
			if (sum - b[n + 1] == b[n] * 2) found = n + 1;
		}
		if (found == -1) {
			cout << -1 << '\n';
		}
		else {
			for (int i = 0; i < n; i++) {
				if (i == found) continue;
				cout << b[i] << ' ';
			}
			if (found == n + 1) cout << '\n';
			else if (found != n) cout << b[n] << '\n';
		}
	}
}