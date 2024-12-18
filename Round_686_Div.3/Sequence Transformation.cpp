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
		int prev = -1;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			if (num == prev) {
				if (i == n - 1) {
					found[num]--;
				}
				continue;
			}
			prev = num;
			if (i == 0 || i == n - 1) {
				if (found.find(num) == found.end()) {
					found[num] = 0;
				}
				continue;
			}
			found[num]++;
			prev = num;
		}
		int min = -1;
		for (auto i : found) {
			if (i.second < min || min == -1) {
				min = i.second;
			}
		}
		if (found.size() == 1) {
			min = -1;
		}
		cout << min + 1 << '\n';
	}
}