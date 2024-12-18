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

int n, v;
vpii k, c;

int main() {
	cin >> n >> v;
	F0R(i, n) {
		int type, cap;
		cin >> type >> cap;
		if (type == 1) k.push_back({ cap, i });
		else c.push_back({ cap, i });
	}
	sort(all(k)); sort(all(c));

	int tcap = 0;
	vi vnums;
	int kp = sz(k) - 1, cp = sz(c) - 1;
	while (v > 1 && kp >= 0 && cp >= 0) {
		if (c[cp].first / 2 >= k[kp].first) {
			tcap += c[cp].first;
			v -= 2;
			vnums.push_back(c[cp--].second);
		}
		else {
			tcap += k[kp].first;
			v--;
			vnums.push_back(k[kp--].second);
		}
	}
	if (cp < 0) {
		while (v > 0 && kp >= 0) {
			tcap += k[kp].first;
			v--;
			vnums.push_back(k[kp--].second);
		}
	}
	else if (kp < 0) {
		while (v > 1 && cp >= 0) {
			tcap += c[cp].first;
			v -= 2;
			vnums.push_back(c[cp--].second);
		}
		if (cp >= 0 && v == 1) {
			if (sz(k) > 0 && k[0].first < c[cp].first) {
				tcap -= k[0].first;
				tcap += c[cp].first;
				v = 0;
				vnums.push_back(k[0].second);
				vnums.push_back(c[cp].second);
			}
		}
	}
	else {
		if (v == 2) {
			int k1 = 0, k2 = 0;
			k1 = k[kp].first;
			if (kp > 0) k2 = k[kp - 1].first;
			if (k1 + k2 > c[cp].first) {
				tcap += k1 + k2;
				vnums.push_back(k[kp--].second);
				if (kp > 0) vnums.push_back(k[kp].second);
			}
			else {
				tcap += c[cp].first;
				vnums.push_back(c[cp].second);
			}
		}
		if (v == 1) {
			if (kp < sz(k) - 1) {
				if (k[kp].first > c[cp].first - k[kp + 1].first) {
					tcap += k[kp].first;
					vnums.push_back(k[kp].second);
				}
				else {
					tcap -= k[kp + 1].first;
					tcap += c[cp].first;
					vnums.push_back(k[kp + 1].second);
					vnums.push_back(c[cp].second);
				}
			}
			else {
				tcap += k[kp].first;
				vnums.push_back(k[kp].second);
			}
		}
	}

	vb carcap(n, false);
	F0R(i, sz(vnums)) {
		carcap[vnums[i]] = !carcap[vnums[i]];
	}
	cout << tcap << '\n';
	F0R(i, n) {
		if (carcap[i]) cout << i + 1 << ' ';
	}
	cout << '\n';
}