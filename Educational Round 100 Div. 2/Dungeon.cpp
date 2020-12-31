#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <string>
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

#define MOD 998244353

int t;

int main() {
	cin >> t;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;
		int sum = a + b + c;
		if (sum % 9 == 0) {
			if (a >= sum / 9 && b >= sum / 9 && c >= sum / 9) cout << "YES\n";
			else cout << "NO\n";
		}
		else cout << "NO\n";
	}
}