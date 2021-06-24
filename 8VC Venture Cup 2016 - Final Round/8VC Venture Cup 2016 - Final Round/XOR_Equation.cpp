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
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define F0R(i,b) FOR(i, 0, b)
#define F0R2(i, j, a, b) F0R(i, a) F0R(j, b)
#define RFOR(i, a, b) for (int i = a - 1; i >= b; i--)
#define RF0R(i, a) RFOR(i, a, 0)

#define MOD 1

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

ll s, x;

int main() {
	cin >> s >> x;
	ll ans = 1;
	int carry = 0;
	string ss, sx;
	for (int i = 63 - 1; i >= 0; i--) {
		ss.push_back((s & ((ll)(1) << i)) ? '1' : '0');
		sx.push_back((x & ((ll)(1) << i)) ? '1' : '0');
	}
	for (int i = 0; i < 60; i++) {
		ll b = (ll)(1) << i;
		if (b & x) {
			if (b & s) {
				if (carry == 2) 
					ans = 0;
				carry = 0;
			}
			else {
				if (!carry) 
					ans = 0;
				carry = 2;
			}
		}
		else {
			if (b & s) {
				if (!carry)
					ans = 0;
				carry = 1;
			}
			else {
				if (carry == 2) 
					ans = 0;
				carry = 1;
			}
		}
	}
	for (int i = 0; i < 60; i++) {
		if (((ll)(1) << i) & x) 
			ans *= 2;
	}
	if (s == x) ans -= 2;
	cout << ans << '\n';
}