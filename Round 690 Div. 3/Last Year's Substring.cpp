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
bool fh[3];
bool bh[3];
bool js;
string s;

int main() {
	cin >> t;
	while (t--) {
		F0R(i, 3) {
			fh[i] = false;
			bh[i] = false;
		}
		js = false;

		int n;
		cin >> n >> s;
		if (n < 4) {
			cout << "NO\n";
			continue;
		}
		if (s[0] == '2') {
			fh[0] = true;
			if (s[1] == '0') {
				fh[1] = true;
				if (s[2] == '2') {
					fh[2] = true;
					if (s[3] == '0') js = true;
				}
			}
		}
		if (s[n - 1] == '0') {
			bh[2] = true;
			if (s[n - 2] == '2') {
				bh[1] = true;
				if (s[n - 3] == '0') {
					bh[0] = true;
					if (s[n - 4] == '2') {
						js = true;
					}
				}
			}
		}

		F0R(i, 3) {
			if (fh[i] && bh[i]) js = true;
		}

		if (js) cout << "YES\n";
		else cout << "NO\n";

		
	}
}