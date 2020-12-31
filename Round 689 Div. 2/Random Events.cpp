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
int arr[100000];
int sarr[100000];

int main() {
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;

		F0R(i, n) cin >> arr[i];
		F0R(i, n) sarr[i] = arr[i];
		sort(sarr, sarr + n);

		int last = -1;
		RF0R(i, n - 1) {
			if (arr[i] != sarr[i]) {
				last = i;
				break;
			}
		}
		if (last == -1) {
			F0R(i, m) {
				int r;
				double p;
				cin >> r >> p;
			}
			cout << 1 << '\n';
		}
		else {
			double prob = 0;
			double noprob = 1;
			F0R(i, m) {
				int r;
				double p;
				cin >> r >> p;
				if (r > last) {
					double newprob = prob + noprob * p;
					double newnoprob = noprob - noprob * p;
					prob = newprob;
					noprob = newnoprob;
				}
			}
			cout << prob << '\n';
		}
	}
}