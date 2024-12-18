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
ll weights[200000];
bool used[200000];
vi found;

int main() {
	cin >> t;
	while (t--) {
		memset(used, false, sizeof(used));
		int n;
		ll W;
		cin >> n >> W;
		FOR0(i, n) {
			cin >> weights[i];
		}
		ll sum = weights[0];
		used[0] = true;
		int s = 0;
		int p = 1;
		while ((sum <= W / 2 || sum > W) && p < n) {
			if (sum == W / 2) {
				if (W % 2 == 0) {
					break;
				}
			}
			sum += weights[p];
			used[p] = true;
			if (weights[p] > W) {
				used[p] = false;
				sum -= weights[p];
			}
			while (!used[s] && s <= p) {
				s++;
			}
			while (sum > W && used[s]) {
				sum -= weights[s];
				used[s] = false;
				do {
					s++;
				} while (!used[s] && s <= p);
				if (s == p + 1) {
					break;
				}
			}
			p++;
		}
		found.clear();
		bool invalid = false;
		if (sum >= W / 2 && sum <= W) {
			if (W % 2 == 1) {
				if (sum == W / 2) {
					invalid = true;
				}
			}
			if (!invalid) {
				FOR0(i, n) {
					if (used[i]) {
						found.push_back(i + 1);
					}
				}
				cout << found.size() << '\n';
				FOR0(i, found.size()) {
					if (i != 0) {
						cout << ' ';
					}
					cout << found[i];
				}
				cout << '\n';
			}
		}
		else {
			invalid = true;
		}
		if (invalid) {
			cout << "-1\n";
		}
	}
}