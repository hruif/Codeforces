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

int t;
set<string> found;
map<string, int> cnt;

void set_first(string a, int curcnt) {
	if (sz(a) == 0) return;
	string a1 = a.substr(0, sz(a) - 1), a2 = a.substr(1, sz(a) - 1);
	if (found.find(a1) == found.end()) {
		found.insert(a1);
		cnt[a1] = curcnt;
		set_first(a1, curcnt + 1);
	}
	if (found.find(a2) == found.end()) {
		found.insert(a2);
		cnt[a2] = curcnt;
		set_first(a2, curcnt + 1);
	}
}

int main() {
	cin >> t;
	while (t--) {
		found.clear();
		cnt.clear();

		string a, b;
		cin >> a;
		cin >> b;
		found.insert(a);
		cnt[a] = 0;
		set_first(a, 1);
		queue<pair<string, int>> q;
		q.push({ b, 0 });
		int ans;
		set<string> visited;
		while (!q.empty()) {
			string s = q.front().first;
			int curcnt = q.front().second;
			q.pop();
			if (found.find(s) == found.end()) {
				string s1 = s.substr(0, sz(s) - 1), s2 = s.substr(1, sz(s) - 1);
				if (visited.find(s1) == visited.end()) {
					visited.insert(s1);
					q.push({ s1, curcnt + 1 });
				}
				if (visited.find(s2) == visited.end()) {
					visited.insert(s2);
					q.push({ s2, curcnt + 1 });
				}
			}
			else {
				ans = curcnt + cnt[s];
				break;
			}
		}
		cout << ans << '\n';
	}
}