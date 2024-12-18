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
ll txs[100000][2];

int main() {
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		F0R(i, n) {
			cin >> txs[i][0] >> txs[i][1];
		}


		int goods = 0;

		ll prevt = 0, nextt = 0;
		ll prevx = 0, curx = 0;
		int dir = 1;
		F0R(i, n - 1) {
			ll t = txs[i][0], x = txs[i][1];
			
			if (t >= nextt) {
				if (x > curx) dir = 1;
				else dir = -1;
				prevt = t;
				nextt = t + abs(curx - x);
				prevx = curx;
				curx = x;
				if (txs[i + 1][0] >= nextt) goods++;
			}
			else {
				ll pxpos = prevx + (dir * (t - prevt));
				ll nxpos = prevx + (dir * (min(txs[i + 1][0], nextt) - prevt));
				prevx = pxpos;
				if ((pxpos <= x && nxpos >= x) || (pxpos >= x && nxpos <= x)) goods++;
				prevt = t;
			}
		}
		ll t = txs[n - 1][0], x = txs[n - 1][1];
		if (t >= nextt) {
			if (x > curx) dir = 1;
			else dir = -1;
			prevt = t;
			nextt = t + abs(curx - x);
			prevx = curx;
			curx = x;
			goods++;
		}
		else {
			ll pxpos = prevx + (dir * (t - prevt));
			prevx = pxpos;
			ll nxpos = curx;
			if ((pxpos <= x && nxpos >= x) || (pxpos >= x && nxpos <= x)) goods++;
			prevt = t;
		}

		cout << goods << '\n';
	}
}