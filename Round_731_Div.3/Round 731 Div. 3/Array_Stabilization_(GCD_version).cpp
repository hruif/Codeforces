#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <climits>

using namespace std;
using ll = long long;
using str = string;

using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vb = vector<bool>;
using vc = vector<char>;
using vstr = vector<string>;
using pii = pair<int, int>;
using vpii = vector<pii>;

#define sz(x) (int)(x.size())
#define rsz resize
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define pb push_back
#define eb emplace_back

#define lb lower_bound
#define ub upper_bound

// for loops
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define F0R(i, b) FOR(i, 0, b)
#define F1R(i, b) FOR(i, 1, b)
#define F0R2(i, j, a, b) F0R(i, a) F0R(j, b)
#define RFOR(i, a, b) for (int i = a - 1; i >= b; i--)
#define RF0R(i, a) RFOR(i, a, 0)

#define MOD 1

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int gcf(int a, int b) {
	if (a == 0) return b;
	return gcf(b % a, a);
}

vi primes;

int main() {
	for (int i = 2; i <= sqrt(1000000); i++) {
		bool prime = true;
		F0R(j, sz(primes)) {
			if (i % primes[j] == 0) {
				prime = false;
				break;
			}
		}
		if (prime) primes.push_back(i);
	}

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vi a(n);
		F0R(i, n) cin >> a[i];
		vector<map<int, int>> pfs(n, map<int, int>());
		F0R(i, n) {
			int num = a[i];
			pfs[i][1]++;
			F0R(j, sz(primes)) {
				while (num % primes[j] == 0) {
					num /= primes[j];
					pfs[i][primes[j]]++;
				}
				if (num == 1) break;
			}
			if (num != 1) pfs[i][num]++;
		}
		map<int, int> shared;
		for (auto x : pfs[0]) shared[x.first] += x.second;
		F1R(i, sz(pfs)) {
			map<int, int> cur;
			for (auto x : pfs[i]) cur[x.first] += x.second;
			for (auto x : shared) shared[x.first] = min(x.second, pfs[i][x.first]);
		}
		int val = 1;
		for (auto x : shared) {
			F0R(i, x.second) {
				val *= x.first;
			}
		}
		queue<pii> q;
		vb visited(n, false);
		int move = 0;
		bool gcfval = false;
		while (!gcfval) {
			bool notyet = true;
			F0R(i, n) {
				if (a[i] == val) {
					notyet = false;
					break;
				}
			}
			if (!notyet) break;
			move++;

			int a0 = a[0];
			F0R(i, n - 1) {
				int ni = (i + 1) % n;
				a[i] = gcf(a[i], a[ni]);
			}
			a[n - 1] = gcf(a[n - 1], a0);
		}
		F0R(i, n) {
			if (a[i] == val) {
				q.push({ i, move });
				visited[i] = true;
				visited[(i + 1) % n] = true;
			}
		}

		while (!q.empty()) {
			int i = q.front().first, m = q.front().second;
			q.pop();
			move = max(move, m);
			if (!visited[(i + 2) % n]) {
				visited[(i + 2) % n] = true;
				q.push({ (i + 1) % n, m + 1 });
			}
			if (!visited[(i + n - 1) % n]) {
				visited[(i + n - 1) % n] = true;
				q.push({ (i + n - 1) % n, m + 1 });
			}
		}
		cout << move << '\n';
	}
}