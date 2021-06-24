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
#define FORI(i, a, b, p) for (int i = a; i < b; i += p)
#define FOR(i, a, b) FORI(i, a, b, 1)
#define F0R(i,b) FOR(i, 0, b)
#define F0R2(i, j, a, b) F0R(i, a) F0R(j, b)
#define RFOR(i, a, b) for (int i = a; i >= b; i--)
#define RF0R(i, a) RFOR(i, a, 0)

#define MOD 1

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int n;

int main() {
	cin >> n;
	bool d1 = false, d2 = false;
	int i1 = 0, j1 = 0;
	int i2 = 0, j2 = 1;
	int last = n * n;
	F0R(i, n * n) {
		if (d1 || d2) {
			last = i;
			break;
		}
		int a;
		cin >> a;
		if (a == 2) {
			cout << 1 << ' ' << i1 + 1 << ' ' << j1 + 1 << '\n' << flush;
			j1 += 2;
			if (j1 >= n) {
				i1++;
				if (i1 % 2 == 1) j1 = 1;
				else j1 = 0;
			}
		}
		else {
			cout << 2 << ' ' << i2 + 1 << ' ' << j2 + 1 << '\n' << flush;
			j2 += 2;
			if (j2 >= n) {
				i2++;
				if (i2 % 2 == 0) j2 = 1;
				else j2 = 0;
			}
		}
		d1 = i1 >= n;
		d2 = i2 >= n;
	}
	FOR(i, last, n * n) {
		int a;
		cin >> a;
		if (d1) {
			if (a == 2) cout << 3;
			else cout << 2;
			cout << ' ' << i2 + 1 << ' ' << j2 + 1 << '\n' << flush;

			j2 += 2;
			if (j2 >= n) {
				i2++;
				if (i2 % 2 == 0) j2 = 1;
				else j2 = 0;
			}
		}
		else {
			if (a == 1) cout << 3;
			else cout << 1;
			cout << ' ' << i1 + 1 << ' ' << j1 + 1 << '\n' << flush;

			j1 += 2;
			if (j1 >= n) {
				i1++;
				if (i1 % 2 == 1) j1 = 1;
				else j1 = 0;
			}
		}
	}
}