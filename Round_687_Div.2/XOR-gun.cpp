#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <unordered_map>
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

#define MOD 998244353

int n;
int nums[100000];

int main() {
	cin >> n;
	if (n > 64) {
		cout << 1 << '\n';
	}
	else {
		for (int i = 0; i < n; i++) {
			cin >> nums[i];
		}
		for (int i = 2; i < n; i++) {
			int num = 0;
			for (int j = 0; j < i; j++) {
				num ^= nums[j];
			}
			if (num > nums[i]) {
				cout << i - 1 << '\n';
				return 0;
			}
			for (int j = 0; j < n - i; j++) {
				num ^= nums[j];
				num ^= nums[j + i];
				if (num < nums[j]) {
					cout << i - 1 << '\n';
					return 0;
				}
				if (j < n - i - 1) {
					if (num > nums[j + i + 1]) {
						cout << i - 1 << '\n';
						return 0;
					}
				}
			}
		}
		cout << -1 << '\n';
	}
}

/*
* think everything through before starting coding
* start with simplest method
* actually calculate complexities
*/

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
*/