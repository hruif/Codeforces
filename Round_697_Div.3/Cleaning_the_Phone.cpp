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
vi reg, imp;
int apps[200000][2];

int main() {
	cin >> t;
	while (t--) {
		reg.clear(); imp.clear();

		int n, m;
		cin >> n >> m;
		F0R(i, n) cin >> apps[i][0];
		F0R(i, n) cin >> apps[i][1];
		F0R(i, n) {
			if (apps[i][1] == 1) reg.push_back(apps[i][0]);
			else imp.push_back(apps[i][0]);
		}
		sort(reg.begin(), reg.end());
		sort(imp.begin(), imp.end());

		int p1 = reg.size() - 1, p2 = imp.size() - 1;
		int conv = 0;
		while (m > 0) {
			if (p1 == -1 && p2 == -1) break;
			if (p2 == -1 || (p1 != -1 && ((reg[p1] * 2 > imp[p2] && m > imp[p2]) || m <= reg[p1]))) {
				m -= reg[p1];
				p1--;
				conv++;
			}
			else {
				m -= imp[p2];
				p2--;
				conv += 2;
			}
		}
		p1++;
		while (p1 < reg.size() && -m >= reg[p1]) {
			m += reg[p1++];
			conv--;
		}
		if (m > 0) cout << "-1\n";
		else cout << conv << '\n';
	}
}