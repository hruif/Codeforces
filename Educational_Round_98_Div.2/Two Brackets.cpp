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
char s[200000];

int main() {
	cin >> t;
	while (t--) {
		memset(s, 0, sizeof(s));
		cin >> s;
		int lp = 0, lb = 0;
		int p = 0;
		int total = 0;
		while (s[p]) {
			if (s[p] == '(') {
				lp++;
			}
			else if (s[p] == '[') {
				lb++;
			}
			else if (s[p] == ')') {
				if (lp > 0) {
					total++;
					lp--;
				}
			}
			else if (s[p] == ']') {
				if (lb > 0) {
					total++;
					lb--;
				}
			}
			p++;
		}
		cout << total << '\n';
	}
}