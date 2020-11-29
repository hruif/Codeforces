#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string.h>
#include <algorithm>
#include <math.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vc = vector<char>;
using pii = pair<int, int>;
using vpii = vector<pii>;

#define FORI(i, a, b, p) for (int i = a; i < b; i += p)
#define FOR(i, a, b) FORI(i, a, b, 1)
#define FOR0(i,b) FOR(i, 0, b)
#define RFOR(i, a, b) for (int i = a; i >= b; i--)
#define RFOR0(i, a) RFOR(i, a, 0)

#define MOD 998244353

int t;
ll boxes[100000];
ll highs[100000];

int main() {
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		FOR0(i, n) {
			cin >> boxes[i];
		}
		ll high = 0;
		ll shigh = 0;
		int highi = -1, shighi = -1;
		ll total = 0;
		FOR0(i, n) {
			total += boxes[i];
			if (boxes[i] > high) {
				shigh = high;
				shighi = highi;
				high = boxes[i];
				highi = i;
			}
			else if (boxes[i] > shigh) {
				shigh = boxes[i];
				shighi = i;
			}
		}
		FOR0(i, n) {
			if (i == highi) {
				highs[i] = shigh;
			}
			else {
				highs[i] = high;
			}
		}
		ll need = high * (n - 1);
		ll rem = total - need;
		if (rem > 0) {
			ll mult = rem / (n - 1);
			need += (n - 1) * mult;
		}
		if (total > need) {
			need += n - 1;
		}
		cout << need - total << '\n';
	}
}