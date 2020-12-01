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
#define F0R(i,b) FOR(i, 0, b)
#define RFOR(i, a, b) for (int i = a; i >= b; i--)
#define RF0R(i, a) RFOR(i, a, 0)

#define MOD 998244353

struct Lat {
	char c;
	int ind;
	Lat() {}
	Lat(char c, int ind) {
		this->c = c;
		this->ind = ind;
	}
};

int t;
Lat s[500];
Lat ss[500];

int main() {
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		F0R(i, n) {
			char c;
			cin >> c;
			ss[i] = Lat(c, i);
			s[i] = ss[i];
		}
		F0R(i, n) {
			if (s[i].ind > 0 && s[i].c <= ss[s[i].ind - 1].c) {
				if (i < n - 1 && (ss[s[i].ind - 1].c > ss[s[i].ind + 1].c || ss[s[i].ind + 1].c == 'a' + k - 1)) {
					int tmp = s[i].ind;
					s[i].ind = tmp + 1;
					s[ss[tmp + 1].ind].ind = tmp;
					ss[tmp].ind = ss[tmp + 1].ind;
					ss[tmp].c = ss[tmp + 1].c;
					ss[tmp + 1].ind = i;
					ss[tmp + 1].c = s[i].c;
				}
				else {
					int tmp = s[i].ind;
					s[i].ind = tmp - 1;
					s[ss[tmp - 1].ind].ind = i;
					ss[tmp].ind = ss[tmp - 1].ind;
					ss[tmp].c = ss[tmp - 1].c;
					ss[tmp - 1].ind = i;
					ss[tmp - 1].c = s[i].c;
				}
			}
			else if (s[i].c == 'a' + k - 1) {
				s[i].c = 'a';
				ss[s[i].ind].c = 'a';
			}
			else if (i < n - 1 && (s[i].c > ss[s[i].ind + 1].c || ss[s[i].ind + 1].c == 'a' + k - 1)) {
				int tmp = s[i].ind;
				s[i].ind = tmp + 1;
				s[ss[tmp + 1].ind].ind = tmp;
				ss[tmp].ind = ss[tmp + 1].ind;
				ss[tmp].c = ss[tmp + 1].c;
				ss[tmp + 1].ind = i;
				ss[tmp + 1].c = s[i].c;
			}
			else if (s[i].c > 'a') {
				s[i].c--;
				ss[s[i].ind].c--;
			}
		}
		F0R(i, n) {
			cout << ss[i].c;
		}
		cout << '\n';
	}
}