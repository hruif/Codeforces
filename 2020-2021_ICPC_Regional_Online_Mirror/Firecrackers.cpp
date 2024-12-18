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

#define MOD 1

int t;
int s[200000];

int main() {
	cin >> t;
	while (t--) {
		int n, m, a, b;
		cin >> n >> m >> a >> b;
		F0R(i, m) cin >> s[i];
		sort(s, s + m);

		int cracks = 0;
		int maxt, maxdrop;
		if (a < b) {
			maxt = b - 2;
			maxdrop = b - a - 1;
		}
		else {
			maxt = n - b - 1;
			maxdrop = a - b - 1;
		}
		RF0R(i, m - 1) {
			if (maxdrop == 0) break;
			if (s[i] <= maxt) {
				maxt--;
				maxdrop--;
				cracks++;
			}
		}
		cout << cracks << '\n';
	}
}