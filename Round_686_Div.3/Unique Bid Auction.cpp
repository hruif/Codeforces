#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string.h>
#include <algorithm>
#include <math.h>
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

#define MOD 998244353

int t;
unordered_map<int, int> found;

int main() {
	cin >> t;
	while (t--) {
		found.clear();
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			if (found.find(num) == found.end()) {
				found[num] = i + 1;
			}
			else {
				found[num] = -1;
			}
		}
		int min = -1;
		int minin = -1;
		for (auto i : found) {
			if (i.second != -1) {
				if (i.first < min || min == -1) {
					min = i.first;
					minin = i.second;
				}
			}
		}
		cout << minin << '\n';
	}
}