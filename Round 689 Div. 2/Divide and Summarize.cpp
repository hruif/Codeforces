#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <unordered_set>

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

#define MOD 1 // placeholder

int t;
vector<ll> arr;
ll psum[100000];
unordered_set<ll> vals;

void remove(int l, int r) {
	if (l > r) return;
	if (l == r) {
		vals.insert(arr[l]);
		return;
	}
	if (l == 0) vals.insert(psum[r]);
	else vals.insert(psum[r] - psum[l - 1]);
	int mid = (arr[l] + arr[r]) / 2;
	auto midp = upper_bound(arr.begin() + l, arr.begin() + r, mid);
	if (midp > arr.begin() + r || (midp == arr.begin() + r && mid >= *midp)) return;
	int midr = midp - arr.begin() - 1;
	int midl = midr + 1;
	remove(midl, r);
	remove(l, midr);
}

int main() {
	cin >> t;
	while (t--) {
		int n, q;
		cin >> n >> q;
		arr.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		sort(arr.begin(), arr.end());

		psum[0] = arr[0];
		FOR(i, 1, n) {
			psum[i] = psum[i - 1] + arr[i];
		}
		int l = 0, r = n - 1;
		vals.clear();
		remove(l, r);
		F0R(i, q) {
			int s;
			cin >> s;
			if (vals.find(s) == vals.end()) cout << "No\n";
			else cout << "Yes\n";
		}
	}
}