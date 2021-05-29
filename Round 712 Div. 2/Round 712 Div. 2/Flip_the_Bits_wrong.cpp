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

int main() {
	cin >> t;
	while (t--) {
		int n;
		string a, b;
		cin >> n;
		cin >> a >> b;

		int cnt = 0;
		int ao = 0, az = 0, bo = 0, bz = 0;
		bool pos = true;
		for (int i = 0; i < n; i++) {
			if (a[i] == '1') ao++;
			else az++;
			if (b[i] == '1') bo++;
			else bz++;
			cnt++;

			bool unch = true, inv = true;
			if (ao == az && bo == bz) {
				unch = true;
				for (int j = i - cnt + 1; j <= i; j++) {
					if (a[j] != b[j]) {
						unch = false;
						break;
					}
				}
				inv = true;
				for (int j = i - cnt + 1; j <= i; j++) {
					if (a[j] == b[j]) {
						inv = false;
						break;
					}
				}
				cnt = 0;
			}
			if (!unch && !inv) {
				pos = false;
				break;
			}
		}
		if (pos) cout << "YES\n";
		else cout << "NO\n";
	}
}