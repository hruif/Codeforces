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
ll s[200000];

int main() {
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		FOR0(i, n * k) {
			cin >> s[i];
		}
		int mid = n / 2 + (n % 2);
		int last = n * k - 1;
		int first = 0;
		ll total = 0;
		if (mid == 1) {
			FORI(i, 0, k * n, n) {
				total += s[i];
			}
		}
		else {
			FOR0(j, k) {
				FOR0(i, mid - 1) {
					s[first] = -1;
					while (s[first] == -1) {
						first++;
					}
				}
				int count = n - mid;
				while (count > 0) {
					s[last] = -1;
					count--;
					while (s[last] == -1) {
						last--;
					}
				}
				total += s[last];
				s[last] = -1;
				while (s[last] == -1) {
					last--;
				}
			}
		}
		cout << total << '\n';
	}
}