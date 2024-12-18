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
		int n, k;
		cin >> n >> k;
		int cnt = 0;
		int as = 0;
		int bs = 0;
		int cs = 0;
		while (cnt < n) {
			if (as >= k) {
				if (bs >= k) {
					if (cs >= k) {
						as = 1;
						bs = 0;
						cs = 0;
						cout << 'a';
					}
					else {
						cs++;
						cout << 'c';
					}
				}
				else {
					bs++;
					cout << 'b';
				}
			}
			else {
				as++;
				cout << 'a';
			}
			cnt++;
		}
		cout << '\n';
	}
}