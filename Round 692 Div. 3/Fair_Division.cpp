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

#define MOD 1

int t;

int main() {
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int total = 0;
		int ts = 0, os = 0;
		F0R(i, n) {
			int c;
			cin >> c;
			total += c;
			if (c == 2) ts++;
			else os++;
		}
		if (total % 2 == 1) cout << "NO\n";
		else {
			if (ts % 2 == 1 && os < 2) cout << "NO\n";
			else cout << "YES\n";
		}
	}
}