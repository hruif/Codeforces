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
int comms[200006][2];

int main() {
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int val = n;
		int rt = sqrt(val);
		rt += (rt * rt == val) ? 0 : 1;
		int nc = 0;
		while (val != 2) {
			RFOR(i, val - 1, rt + 1) {
				comms[nc][0] = i;
				comms[nc][1] = val;
				nc++;
			}
			comms[nc][0] = val;
			comms[nc][1] = rt;
			nc++;
			comms[nc][0] = val;
			comms[nc][1] = rt;
			nc++;
			val = rt;
			rt = sqrt(val);
			rt += (rt * rt == val) ? 0 : 1;
		}
		cout << nc << '\n';
		F0R(i, nc) cout << comms[i][0] << ' ' << comms[i][1] << '\n';
	}
}