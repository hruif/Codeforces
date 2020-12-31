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
		int cnt = 0;
		F0R(i, s.size()) {
			if (i > 0) {
				if (s[i - 1] == s[i]) {
					s[i] = 'z' + 1;
					cnt++;
				}
			}
			if (s[i] == 'z' + 1) continue;
			if (i > 1) {
				if (s[i - 2] == s[i]) {
					s[i] = 'z' + 1;
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
	}
}