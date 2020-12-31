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

int T;
int rs[1000];
int bs[1000];

int main() {
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		F0R(i, n) {
			char d;
			cin >> d;
			rs[i] = d - '0';
		}
		F0R(i, n) {
			char d;
			cin >> d;
			bs[i] = d - '0';
		}

		int rc = 0, bc = 0;
		F0R(i, n) {
			if (rs[i] < bs[i]) bc++;
			if (rs[i] > bs[i]) rc++;
		}

		if (bc > rc) cout << "BLUE\n";
		else if (bc < rc) cout << "RED\n";
		else cout << "EQUAL\n";
	}
}