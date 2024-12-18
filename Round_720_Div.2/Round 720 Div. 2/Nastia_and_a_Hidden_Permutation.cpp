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

#define MOD 998244353

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int T;
int a[10000];

int main() {
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int i = 0; i < n - 1; i += 2) {
			cout << "? 1 " << i + 1 << ' ' << i + 2 << ' ' << n - 1 << '\n';
			cout.flush();

			int res;
			cin >> res;
			if (res == n - 1) {
				cout << "? 1 " << i + 2 << ' ' << i + 1 << ' ' << n - 1 << '\n';
				cout.flush();
				cin >> res;
			}
			int mx = res;
			cout << "? 2 " << i + 1 << ' ' << i + 2 << ' ' << mx - 1 << '\n';
			cout.flush();
			cin >> res;
			if (res == mx) {
				a[i] = mx;
				cout << "? 2 " << i + 2 << ' ' << i + 1 << ' ' << 1 << '\n';
				cout.flush();
				cin >> res;
				a[i + 1] = res;
			}
			else {
				a[i + 1] = mx;
				cout << "? 2 " << i + 1 << ' ' << i + 2 << ' ' << 1 << '\n';
				cout.flush();
				cin >> res;
				a[i] = res;
			}
		}
		cout << "? 1 " << n - 1 << ' ' << n << ' ' << n - 1 << '\n';
		cout.flush();

		int res;
		cin >> res;
		if (res == n - 1) {
			cout << "? 1 " << n << ' ' << n - 1 << ' ' << n - 1 << '\n';
			cout.flush();
			cin >> res;
		}
		int mx = res;
		cout << "? 2 " << n - 1 << ' ' << n << ' ' << mx - 1 << '\n';
		cout.flush();
		cin >> res;
		if (res == mx) {
			a[n - 2] = mx;
			cout << "? 2 " << n << ' ' << n - 1 << ' ' << 1 << '\n';
			cout.flush();
			cin >> res;
			a[n - 1] = res;
		}
		else {
			a[n - 1] = mx;
			cout << "? 2 " << n - 1 << ' ' << n << ' ' << 1 << '\n';
			cout.flush();
			cin >> res;
			a[n - 2] = res;
		}
		cout << "! ";
		F0R(i, n) cout << a[i] << ' ';
		cout << '\n';
	}
}