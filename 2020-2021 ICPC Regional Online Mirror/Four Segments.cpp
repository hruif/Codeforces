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

int main() {
	cin >> t;
	while (t--) {
		int as[4];
		cin >> as[0] >> as[1] >> as[2] >> as[3];
		int mini = 0, mina = 100000;
		for (int i = 0; i < 4; i++) {
			if (as[i] < mina) {
				mina = as[i];
				mini = i;
			}
		}
		int mini2 = 0;
		mina = 100000;
		for (int i = 0; i < 4; i++) {
			if (i == mini) continue;
			if (as[i] < mina) {
				mina = as[i];
				mini2 = i;
			}
		}
		int maxi = 0, maxa = 0;
		for (int i = 0; i < 4; i++) {
			if (i == mini || i == mini2) continue;
			if (as[i] > maxa) {
				maxa = as[i];
				maxi = i;
			}
		}
		int maxi2;
		for (int i = 0; i < 4; i++) {
			if (i == mini || i == mini2 || i == maxi) continue;
			maxi2 = i;
		}
		cout << min(as[mini], as[mini2]) * min(as[maxi], as[maxi2]) << '\n';
	}
}