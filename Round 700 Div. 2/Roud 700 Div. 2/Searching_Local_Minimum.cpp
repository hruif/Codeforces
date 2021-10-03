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

#define MOD (ll)(1e9 + 7)

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int n;

int main() {
	cin >> n;
	if (n == 1) cout << "! 1\n";
	else if (n == 2) {
		int a, b;
		cout << "? 1\n";
		cout.flush();
		cin >> a;
		cout << "? 2\n";
		cout.flush();
		cin >> b;
		if (a < b) cout << "! 1\n";
		else cout << "! 2\n";
	}
	else {
		int a, b;
		cout << "? 1\n";
		cout.flush();
		cin >> a;
		cout << "? " << n << '\n';
		cout.flush();
		cin >> b;
		int l = 0, r = n - 1;
		vi con(n, -1);
		while (l < r - 1) {
			while (l < r - 1) {
				int mid = (l + r) / 2;
				cout << "? " << mid + 1 << '\n';
				cout.flush();
				int c;
				cin >> c;
				if (a < b) {
					b = c;
					r = mid;
				}
				else {
					a = c;
					l = mid;
				}
			}
		}
		cout << "? " << l + 1 << '\n';
		cout.flush();
		cin >> a;
		cout << "? " << r + 1 << '\n';
		cout.flush();
		cin >> b;
		if (a < b) cout << "! " << l + 1 << '\n';
		else cout << "! " << r + 1 << '\n';
	}
}