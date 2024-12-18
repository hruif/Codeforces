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

int q;
string s;
set<string> inverses;

void findInverse(string s) {
}

string ans;
int ansd = 500000;
void buildbeaut(int d, int len) {
	if (d == len) {
		if (inverses.find(ans) == inverses.end() && ansd > d) {
			ansd = d;
		}
		return;
	}

	ans[d] = '0';
	buildbeaut(d + 1, len);
	if (ansd <= len) return;
	ans[d] = '1';
	buildbeaut(d + 1, len);
	if (ansd <= len) return;
}

int main() {
	cin >> q;
	while (q--) {
		ansd = 500000;
		inverses.clear();
		ans = "";

		int n, k;
		cin >> n >> k;
		cin >> s;
		ans.resize(k);
		string inv = "";
		F0R(i, k - 1) {
			if (s[i] == '0') inv.push_back('1');
			else inv.push_back('0');
		}
		F0R(k - 1, n) {
			F0R(i, s.size()) {
				if (s[i] == '0') inv.push_back('1');
				else inv.push_back('0');
			}
			inverses.insert(inv);
		}
		buildbeaut(0, k);

		if (ansd > k) cout << "NO\n";
		else {
			cout << "YES\n";
			cout << ans << '\n';
		}
	}
}