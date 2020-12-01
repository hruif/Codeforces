#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <string>

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
		string n;
		cin >> n;
		int p = n.size() - 1;
		int s = n.size();
		while (n[p] == '0' && p >= 0) {
			p--;
		}
		if (p == 0 && n[0] == '1') {
			s--;
		}
		cout << s << '\n';
	}
}