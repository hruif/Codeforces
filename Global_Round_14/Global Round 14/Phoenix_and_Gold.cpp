#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vb = vector<bool>;
using vc = vector<char>;
using pii = pair<int, int>;
using vpii = vector<pii>;

#define FORI(i, a, b, p) for (int i = a; i < b; i += p)
#define FOR(i, a, b) FORI(i, a, b, 1)
#define F0R(i,b) FOR(i, 0, b)
#define RFOR(i, a, b) for (int i = a; i >= b; i--)
#define RF0R(i, a) RFOR(i, a, 0)

#define MOD 1

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int t;
int w[100];

int main() {
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		F0R(i, n) cin >> w[i];
		sort(w, w + n);
		int sum = 0;
		bool impossible = false;
		F0R(i, n) {
			sum += w[i];
			if (sum == x) {
				if (i == n - 1) impossible = true;
				else {
					swap(w[i], w[0]);
					swap(w[i + 1], w[i]);
					sum -= w[i + 1];
					sum += w[i];
					if (sum == 0) {
						if (i < n - 2) {
							swap(w[i], w[i + 2]);
						}
						else impossible = true;
					}
				}
			}
		}
		if (impossible) cout << "NO\n";
		else {
			cout << "YES\n";
			F0R(i, n) cout << w[i] << ' ';
			cout << '\n';
		}
	}
}