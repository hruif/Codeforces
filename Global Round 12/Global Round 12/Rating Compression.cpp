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
int a[300000];
vi app[300001];
bool happy[300000];

int main() {
	cin >> t;
	while (t--) {
		memset(app, 0, sizeof(app));

		int n;
		cin >> n;
		F0R(i, n) {
			cin >> a[i];
			app[a[i]].push_back(i);
		}
		if (app[1].empty()) {
			F0R(i, n) {
				cout << 0;
			}
			cout << '\b';
			continue;                                                              
		}
		F0R(i, n) {
			int d = i + 1;
			
		}
	}
}