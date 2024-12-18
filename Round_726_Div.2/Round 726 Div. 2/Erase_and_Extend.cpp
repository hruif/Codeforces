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

int n, k;
string s;

int main() {
	cin >> n >> k;
	cin >> s;
	int p = n - 1;
	F1R(i, sz(s)) {
		if (s[i] > s[0]) {
			s = s.substr(0, i);
			break;
		}
	}
	int l = 0, r = 0;
	vi zarr(s.size(), 0);
	F1R(i, sz(s)) {
		if (i < r) {
			if (zarr[i - l] >= r - i) {
				l = i;
				while (r < n && s[r] == s[r - l]) r++;
				zarr[l] = r - l;
			}
			else {
				zarr[i] = zarr[i - l];
				continue;
			}
		}
		else if (s[i] == s[0]) {
			l = r = i;
			while (r < n && s[r] == s[r - l]) r++;
			zarr[l] = r - l;
		}
	}
	F1R(i, sz(s)) {
		int zr = zarr[i] + i;
		if (zr < n && s[zr] > s[zarr[i]]) {
			s = s.substr(0, i);
			break;
		}
	}
	p = sz(s) - 1;
	while (p > 0 && s[p--] >= s[0]) s.pop_back();
	while (s.size() < k) {
		s.append(s);
	}
	cout << s.substr(0, k) << '\n';
}