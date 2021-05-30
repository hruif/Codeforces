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
string arr;

bool inSet(set<int>& s, int i) {
	return s.find(i) != s.end();
}

int main() {
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<int> alive;
		set<int> canAff;
		arr.resize(n);
		F0R(i, n) {
			cin >> arr[i];
			if (arr[i] == '1') {
				alive.push_back(i);
				canAff.insert(i);
			}
		}
		F0R(i, m) {
			vector<int> toAdd;
			vector<int> toDel;
			if (canAff.empty()) break;
			for (auto i : canAff) {
				if (i > 0 && arr[i - 1] == '0' && (i < 2 || arr[i - 2] == '0')) toAdd.push_back(i - 1);
				if (i < n - 1 && arr[i + 1] == '0' && (i > n - 3 || arr[i + 2] == '0')) toAdd.push_back(i + 1);
				toDel.push_back(i);
			}
			F0R(i, toDel.size()) canAff.erase(canAff.find(toDel[i]));
			F0R(i, toAdd.size()) {
				arr[toAdd[i]] = '1';
				canAff.insert(toAdd[i]);
			}
		}
		cout << arr << '\n';
	}
}