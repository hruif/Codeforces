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
		int a, b;
		cin >> a >> b;
		int o = 0, z = 0;
		string s;
		cin >> s;
		int ss = s.size();
		for (int i = 0; i < ss; i++) {
			if (s[i] == '1') o++;
			if (s[i] == '0') z++;
		}
		bool inv = false;
		bool mid = false;
		int doub = 0;
		for (int i = 0; i <= ss / 2; i++) {
			if (i == ss - i - 1) {
				if (s[i] == '?') mid = true;
				break;
			}
			if (s[i] != '?' && s[ss - i - 1] != '?') {
				if (s[i] != s[ss - i - 1]) inv = true;
			}
			else if (s[i] != '?') {
				if (s[i] == '1') {
					o++;
					s[ss - i - 1] = '1';
				}
				else {
					z++;
					s[ss - i - 1] = '0';
				}
			}
			else if (s[ss - i - 1] != '?') {
				if (s[ss - i - 1] == '1') {
					o++;
					s[i] = '1';
				}
				else {
					z++;
					s[i] = '0';
				}
			}
			else {
				doub++;
			}
		}
		for (int i = 0; i <= ss / 2; i++) {
			if (s[i] == '?') {
				if (z + 1 < a) {
					s[i] = '0';
					s[ss - i - 1] = '0';
					z += 2;
				}
				else if (o + 1 < b) {
					s[i] = '1';
					s[ss - i - 1] = '1';
					o += 2;
				}
				else if (i == ss - 1 - i) {
					if (z < a) {
						s[i] = '0';
						z++;
					}
					else {
						s[i] = '1';
						o++;
					}
				}
			}
		}
		if (inv || (z != a || o != b)) cout << -1 << '\n';
		else cout << s << '\n';
	}
}