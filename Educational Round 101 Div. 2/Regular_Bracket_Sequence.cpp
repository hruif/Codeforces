#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <queue>
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
		string s;
		cin >> s;

		int a = 0, l = 0;
		bool imp = false;
		int lb = 0, rb = 0, q = 0;
		F0R(i, s.size()) {
			if (s[i] == '(') {
				l++;
				lb++;
			}
			if (s[i] == ')') {
				rb++;
				if (a == 0) l--;
				else a--;
			}
			if (s[i] == '?') {
				a++;
				q++;
			}
			if (l < 0) {
				imp = true;
				break;
			}
		}
		if (lb + q < rb || rb + q < lb || (lb + q + rb) % 2 == 1) imp = true;
		a = 0;
		int r = 0;
		RF0R(i, s.size() - 1) {
			if (s[i] == '(') {
				if (a == 0) r--;
				else a--;
			}
			if (s[i] == ')') r++;
			if (s[i] == '?') a++;
			if (r < 0) {
				imp = true;
				break;
			}
		}

		if (imp) cout << "NO\n";
		else cout << "YES\n";
	}
}