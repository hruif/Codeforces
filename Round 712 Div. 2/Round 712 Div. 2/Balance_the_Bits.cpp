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
		string s;
		cin >> n;
		cin >> s;

		bool pos = true;
		if (s[0] != '1' || s[s.size() - 1] != '1') pos = false;
		int o = 0, z = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '1') z++;
			else o++;
		}
		if (z % 2 != 0 || o % 2 != 0) pos = false;
		if (pos) {
			string a, b;
			int zl = 0;
			bool al = true;
			for (int i = 0; i < n; i++) {
				if (s[i] == '1') {
					if (zl < z / 2) {
						zl++;
						a.push_back('(');
						b.push_back('(');
					}
					else {
						a.push_back(')');
						b.push_back(')');
					}
				}
				else {
					a.push_back(al ? '(' : ')');
					b.push_back(al ? ')' : '(');
					al = !al;
				}
			}
			cout << "YES\n" << a << '\n' << b << '\n';
		}
		else cout << "NO\n";
	}
}