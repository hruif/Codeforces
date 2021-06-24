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
		cin >> n;
		vector<int> a(n);
		F0R(i, n) cin >> a[i];
		sort(a.begin(), a.end());

		int lasts = 0;
		while (lasts != a.size() && a.size() <= 300) {
			lasts = a.size();
			set<int> b;
			F0R(i, n) b.insert(a[i]);
			for (int i = 0; i < a.size(); i++) {
				b.insert(a[i]);
				for (int j = i + 1; j < a.size(); j++) {
					b.insert(abs(a[i] - a[j]));
				}
			}
			a.clear();
			for (auto i : b) a.push_back(i);
		}
		if (a.size() > 300) cout << "NO\n";
		else {
			cout << "YES\n";
			cout << a.size() << '\n';
			F0R(i, a.size()) {
				cout << a[i] << ' ';
			}
			cout << '\n';
		}
	}
}