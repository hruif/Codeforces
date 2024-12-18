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

int t;

int main() {
	cin >> t;
	while (t--) {
		int x;
		cin >> x;
		set<int> s;
		queue<int> q;
		bool found = false;
		q.push(x);
		while (!q.empty()) {
			int curx = q.front();
			q.pop();
			int x2 = curx % 11;
			int x3 = curx - 111;
			int x5 = curx - 11111;
			int x7 = curx - 1111111;
			if (x2 == 0 || x3 == 0 || x5 == 0 || x7 == 0) {
				found = true;
				break;
			}
			if (x3 > 0 && s.find(x3) == s.end()) {
				q.push(x3);
				s.insert(x3);
			}
			if (x5 > 0 && s.find(x5) == s.end()) {
				q.push(x5);
				s.insert(x5);
			}
			if (x7 > 0 && s.find(x7) == s.end()) {
				q.push(x7);
				s.insert(x7);
			}
		}
		if (found) cout << "YES\n";
		else cout << "NO\n";
	}
}