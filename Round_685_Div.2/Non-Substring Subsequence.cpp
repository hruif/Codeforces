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
char s[100];

int main() {
	cin >> t;
	while (t--) {
		int n, q;
		cin >> n >> q;
		cin >> s;
		FOR0(i, q) {
			int l, r;
			cin >> l >> r;
			l--;
			r--;
			int p = l;
			bool cont = true;
			bool found = false;
			FOR0(j, n) {
				if (p > r) {
					break;
				}
				if (s[j] == s[p]) {
					found = true;
					if (p == r && cont) {
						cont = false;
						continue;
					}
					p++;
				}
				else if (found) {
					cont = false;
				}
			}
			if (p > r && !cont) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
	}
}